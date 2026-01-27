
/*
string in c++

character array = c string
char str[] = {'a', 'b', 'c'};
cout<< str //  abc

int arr[]= {1,2,3,};  
cout<<arr  // addres of array like 0xbch24mck

char str = {'a', 'b', 'c','\0};  here \0 is a null character also use 1 byte as a b and c takes
cout<< str //  abc    here abc is valid string
cout<<strlen(str);    // 3

char str[] = "hello"   // hello is caleed string literals       literals  = something whose value cant be changed
cout<<strlen(str);    // 5
cout<<str[2]   // l

char str[100];
cin>> str;      // hello world
cout<<str ;    // hello

for input & putput in string::

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
    //  chArr = "hello"; it gives error bcz character array is constant which can be changed at run time

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