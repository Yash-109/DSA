
/*
string in c++

character array = c string
char str[] = {'a', 'b', 'c'};
cout<< str //  abc

int arr[]= {1,2,3,};  
cout<<arr  // addres of array like 0xbch24mck

char str = {'a', 'b', 'c','\0};  here \0 is a null character also use 1 byte as a,b and c takes
cout<< str //  abc    here abc is valid string
cout<<strlen(str);    // 3

char str[] = "hello"   // hello is called string literals       literals  = something whose value cant be changed
cout<<strlen(str);    // 5
cout<<str[2]   // l

char str[100];
cin>> str;      // hello world
cout<<str ;    // hello

for input & output in string::

cin.getline(str,len,delim)

char str[100];
cin.getline(str,100);      // hello world
cout<<str ;   // hello world

delim = delimiter is character where we can stop taking input afterwards
default delim = new line 


char str[100];
cin.getline(str,100,$);      // hello wo$rld hi
cout<<str ;         // hello wo

int len=0;
char str[]= "yash parmar"
 for(int i=; i<str[i] != '\0'; i++)
 {
 len++;
 }
 cout<<len;    //11



 
 Strings in c++:


========================= IMPORTANT STRING FUNCTIONS IN C++ =========================

1. LENGTH/SIZE FUNCTIONS:
   - str.length()           // Returns length of string | str.length() returns 5 for "hello"
   - str.size()             // Same as length() | str.size() returns 5 for "hello"

2. CHARACTER CASE FUNCTIONS:
   - tolower(ch)            // Converts character to lowercase | tolower('A') returns 'a'
   - toupper(ch)            // Converts character to uppercase | toupper('a') returns 'A'

3. CHARACTER CHECKING FUNCTIONS:
   - isalnum(ch)            // Check if alphanumeric (letter or digit) | isalnum('5') returns true
   - isalpha(ch)            // Check if alphabetic | isalpha('a') returns true
   - isdigit(ch)            // Check if digit | isdigit('9') returns true

4. SUBSTRING & SEARCH FUNCTIONS:
   - str.find(substr)       // Returns index of first occurrence | "hello".find("ll") returns 2
   - str.substr(start, len) // Extract substring | "hello".substr(1, 3) returns "ell"
   - str.erase(pos, len)    // Erase substring | "hello".erase(1, 2) modifies to "hlo"

5. STRING MODIFICATION:
   - str.push_back(ch)      // Add character at end | str.push_back('!') adds '!' at end
   - str.pop_back()         // Remove last character | str.pop_back() removes last char
   - str + str2             // Concatenate strings | "hello" + " world" returns "hello world"
   - str.append(str2)       // Append string | str.append(" world") appends " world"
   - str.insert(pos, s)     // Insert string at position | str.insert(0, "Hi ") inserts at start
   - str.clear()            // Empty the string | str.clear() makes string empty

6. STRING COMPARISON:
   - str1 == str2           // Check equality | "hello" == "hello" returns true
   - str1 != str2           // Check inequality | "hello" != "world" returns true
   - str1 < str2            // Lexicographic comparison | "apple" < "banana" returns true
   - str1.compare(str2)     // Returns 0 if equal, <0 if less, >0 if greater

7. STRING REVERSAL (needs #include<algorithm>):
   - reverse(str.begin(), str.end())  // Reverse string | reverse makes "hello" to "olleh"

8. STRING CONVERSION:
   - to_string(num)         // Convert number to string | to_string(123) returns "123"
   - stoi(str)              // String to integer | stoi("123") returns 123
   - stod(str)              // String to double | stod("3.14") returns 3.14

9. STRING ACCESS:
   - str[index]             // Access character at index | "hello"[1] returns 'e'
   - str.at(index)          // Access with bounds checking | str.at(1) returns 'e'
   - str.front()            // First character | "hello".front() returns 'h'
   - str.back()             // Last character | "hello".back() returns 'o'

10. STRING INPUT:
    - getline(cin, str)     // Read entire line with spaces | getline(cin, str) reads "hello world"
    - cin >> str            // Read until whitespace | cin >> str reads only "hello" from "hello world"

11. ITERATORS:
    - str.begin()           // Iterator to start | for(auto it = str.begin(); it != str.end(); it++)
    - str.end()             // Iterator to end (one past last element)

12. STRING CHECKS:
    - str.empty()           // Check if string is empty | "".empty() returns true
    - str.resize(n)         // Resize string to n characters | str.resize(10) resizes to 10 chars

==================================================================================

*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    string str="yash parmar";  // dynamic in nature => runtime resize
    cout<<str;   // yash parmar
    str="yashh";  // dont give error

    char chArr[]="yash"; 
    //  chArr = "hello"; it gives error bcz character array is constant which can not be changed at run time

    string str1="yash";
    string str2="parmar";
    
    string s3= str1+str2;  // concatination of string
    
    cout<<(str1 == str2);   // 0  means false

    cout<<(str1<str2);  // 0 bcz in yash y comes later whereas parmar p comes first

    // by above operations strings are much better than character array

    cout<<str1.length();    // 4

    // for input:
    string strr;
    cin>> strr;      // hello world
    cout<<strr ;   // hello
    cout<<endl;
    
    string st3;
    getline(cin, str);  // yash parmar  same as character array also can use delimiter
    cout<<st3;    // yash parmar

    string st4="yash parmar";
    for(int i=0; i<st4.length();i++)
    {
        cout<<st4[i]; // yash parmar
    }

    for(char ch: st4)
    {
        cout<< ch; //yash parmar 
    }
    cout<<endl;

    // reverse a string
    string s5="hello world";
    reverse(s5.begin(), s5.end()); 
    cout<<s5;  // dlrow olleh
    return 0;
}

/*
std::string

find() – finds first occurrence of a substring or character
substr() – extracts a substring from a string
erase() – removes characters from a string
insert() – inserts characters at a given position
push_back() – adds a character at the end
pop_back() – removes last character
length() / size() – returns string length

*/