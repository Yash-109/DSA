/*
 * Problem: Reverse Words in a String
 * Similar to LeetCode 151
 *
 * Given a string s, reverse the order of the words.
 * A word is defined as a sequence of non-space characters.
 *
 * Example: "  the sky  is blue  " -> "blue is sky the"
 */

/*
 * Pseudocode (Reverse String Then Reverse Each Word)
 * --------------------------------------------------
 *   function reverseWords(s):
 *       n = length(s)
 *       ans = empty string
 *
 *       reverse s in-place (entire string)
 *
 *       i = 0
 *       while i < n:
 *           word = empty string
 *
 *           // build next word (skip spaces)
 *           while i < n and s[i] != ' ':
 *               append s[i] to word
 *               i = i + 1
 *
 *           reverse characters of word
 *
 *           if word is not empty:
 *               ans = ans + " " + word
 *
 *           // skip extra spaces between words
 *           i = i + 1
 *
 *       if ans is not empty:
 *           return substring of ans from index 1 onward  // remove first space
 *       else:
 *           return ans
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Time Complexity: O(n), Space Complexity: O(n)
string reverseWords(string s)
{
    int n = s.length();
    string ans = "";

    // Reverse the whole string first
    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++)
    {
        string word = "";

        // Collect a word (skip spaces)
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        // Reverse individual word to fix its character order
        reverse(word.begin(), word.end());

        if (word.length() > 0)
        {
            // Append word with a leading space
            ans += " " + word;
        }
    }

    // Remove the first extra space
    if (!ans.empty())
    {
        return ans.substr(1);
    }
    return ans;
}

int main()
{
    string s1 = "  the sky  is blue  ";
    string s2 = "hello world";
    string s3 = "a good   example";

    cout << '"' << s1 << '"' << " -> " << '"' << reverseWords(s1) << '"' << endl;
    cout << '"' << s2 << '"' << " -> " << '"' << reverseWords(s2) << '"' << endl;
    cout << '"' << s3 << '"' << " -> " << '"' << reverseWords(s3) << '"' << endl;

    return 0;
}