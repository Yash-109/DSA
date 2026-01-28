/*
 * Problem: 567. Permutation in String
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/permutation-in-string/
 * 
 * Check if s1's permutation is a substring of s2.
 */

#include <iostream>
#include <string>
using namespace std;

// Helper function to compare two frequency arrays
// Time Complexity: O(26) -> O(1)
bool isFreqSame(int freq1[], int freq2[])  
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}

// Sliding Window Approach
// Time Complexity: O(n), Space Complexity: O(1)
bool checkInclusion(string s1, string s2) 
{
    if (s1.length() > s2.length())
    {
        return false;
    }

    int freq1[26] = {0};
    int freq2[26] = {0};

    int windowSize = s1.length();

    // Build frequency for s1 and first window of s2
    for (int i = 0; i < windowSize; i++)
    {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    if (isFreqSame(freq1, freq2))
    {
        return true;
    }

    // Slide the window over s2
    for (int i = windowSize; i < s2.length(); i++)
    {
        // Add new character in the window
        freq2[s2[i] - 'a']++;

        // Remove character going out of the window
        freq2[s2[i - windowSize] - 'a']--;

        if (isFreqSame(freq1, freq2))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo"; // contains "ba" which is a permutation of "ab"

    cout << "s1: " << s1 << ", s2: " << s2
         << " -> " << (checkInclusion(s1, s2) ? "true" : "false") << endl;

    string s3 = "ab";
    string s4 = "eidboaoo"; // does not contain any permutation of "ab"

    cout << "s1: " << s3 << ", s2: " << s4
         << " -> " << (checkInclusion(s3, s4) ? "true" : "false") << endl;

    return 0;
}

//🔹 Note: Handling digits & special characters (general ASCII / Unicode)

// The above solution works only for lowercase English letters (a–z) because it uses fixed-size arrays of length 26.

// If the string can contain digits, uppercase letters, or special characters, the following changes are required:

// ✅ Required Changes

// Replace frequency arrays with hash maps

// unordered_map<char, int> freq1, freq2;


// Build frequencies using characters directly

// freq1[s1[i]]++;
// freq2[s2[i]]++;


// Sliding window logic remains the same

// Increment count for the incoming character

// Decrement count for the outgoing character

// Remove entries with zero frequency (important for equality check)

// Compare maps instead of arrays

// if (freq1 == freq2) return true;