/*
 * Problem: 125. Valid Palindrome
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-palindrome/
 * 
 * Check if a string is a palindrome (considering only alphanumeric characters and ignoring case)
 */

#include<iostream>
#include<string>
using namespace std;

// Helper function to check if character is alphanumeric

// c++ function to check alphanumeric:::   isalnum((ch))

bool isAlphaNum(char ch)
{
    if(ch >= '0' && ch <= '9' || tolower(ch) >= 'a' && tolower(ch) <= 'z')
    {
        return true;
    }
    return false;
}

// Two Pointer Approach - Optimal Solution
// Time Complexity: O(n), Space Complexity: O(1)
bool isPalindrome(string s) 
{
    int st = 0;                 // Left pointer
    int end = s.length() - 1;   // Right pointer

    while(st < end)
    {
        // Skip non-alphanumeric characters from left
        if(!isAlphaNum(s[st]))
        {
            st++; 
            continue;
        }
        
        // Skip non-alphanumeric characters from right
        if(!isAlphaNum(s[end]))
        {
            end--; 
            continue;
        }

        // Compare characters (case-insensitive)
        if(tolower(s[st]) != tolower(s[end]))
        {
            return false;
        }

        st++;
        end--;
    }

    return true; 
}

int main()
{
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";
    
    cout << "Test 1: \"" << s1 << "\" -> " << (isPalindrome(s1) ? "true" : "false") << endl;
    cout << "Test 2: \"" << s2 << "\" -> " << (isPalindrome(s2) ? "true" : "false") << endl;
    cout << "Test 3: \"" << s3 << "\" -> " << (isPalindrome(s3) ? "true" : "false") << endl;
    
    return 0;
}