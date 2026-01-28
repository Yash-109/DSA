/*
 * Problem: 443. String Compression
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/string-compression/
 * 
 * Compress a character array in-place and return the new length.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Time Complexity: O(n), Space Complexity: O(1) extra (ignoring input array)
int compress(vector<char>& chars)
{
  int n = chars.size();
  int writeIndex = 0; // position to write compressed result

  for (int i = 0; i < n; i++)
  {
    char ch = chars[i];
    int count = 0;

    // Count occurrences of current character
    while (i < n && chars[i] == ch)
    {
      i++;
      count++;
    }

    // Write character
    chars[writeIndex++] = ch;

    // Write count if greater than 1
    if (count > 1)
    {
      string str = to_string(count);
      for (char digit : str)
      {
        chars[writeIndex++] = digit;
      }
    }

    // Adjust i because for-loop will increment it
    i--;
  }

  chars.resize(writeIndex);
  return writeIndex;
}

int main()
{
  vector<char> chars1 = {'a','a','b','b','c','c','c'};   // -> a2b2c3
  vector<char> chars2 = {'a'};                           // -> a
  vector<char> chars3 = {'a','b','b','b','b','b','b'};   // -> a b6

  auto printVec = [](const vector<char>& v)
  {
    for (char c : v)
    {
      cout << c;
    }
    cout << " (len=" << v.size() << ")" << endl;
  };

  cout << "Before: ";
  printVec(chars1);
  int len1 = compress(chars1);
  cout << "After : ";
  printVec(chars1);
  cout << "New length: " << len1 << "\n" << endl;

  cout << "Before: ";
  printVec(chars2);
  int len2 = compress(chars2);
  cout << "After : ";
  printVec(chars2);
  cout << "New length: " << len2 << "\n" << endl;

  cout << "Before: ";
  printVec(chars3);
  int len3 = compress(chars3);
  cout << "After : ";
  printVec(chars3);
  cout << "New length: " << len3 << endl;

  return 0;
}