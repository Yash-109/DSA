/*
 * Problem: 1910. Remove All Occurrences of a Substring
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
 * 
 * Remove all occurrences of a substring from a given string
 */

#include<iostream>
#include<string>
using namespace std;

// Iterative Approach - Keep removing until no more occurrences found
// Time Complexity: O(n * m) where n is length of s and m is length of part
// Space Complexity: O(1)
string removeOccurrences(string s, string part) 
{

    // .find(part) fucntion return the first index of accurance of part
    while(s.length() > 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    string s1 = "daabcbaabcbc";
    string part1 = "abc";
    
    string s2 = "axxxxyyyyb";
    string part2 = "xy";
    
    cout << "Test 1: \"" << s1 << "\" removing \"" << part1 << "\" -> \"" << removeOccurrences(s1, part1) << "\"" << endl;
    cout << "Test 2: \"" << s2 << "\" removing \"" << part2 << "\" -> \"" << removeOccurrences(s2, part2) << "\"" << endl;
    
    return 0;
}