// Book Allocation Problem

// There are N books, each book has A[i] number of pages.
// You have to allocate books to M number of students so that the maximum number of pages allocated to a student is minimum.

// Conditions:

// Each book should be allocated to a student.
// Each student has to be allocated at least one book.
// Allotment should be in contiguous order.
// Calculate and return that minimum possible number.

// Return -1 if a valid assignment is not possible.

#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> arr,int n, int m, int maxAllowedPages)  // maxAllowedPages=mid  tc:O(n)
{
    int student=1, page=0;

    for(int i=0;i<n;i++) 
    {
        if(arr[i]> maxAllowedPages) // edge case
        {
            return false;
        }

        if(page + arr[i] <= maxAllowedPages) 
        {
            page+=arr[i];
        }
        else
        {
            student++;
            page=arr[i];
        }
    }
    return student > m ? false:true;
}


int allocateBooks(vector<int> &arr,int n,int m) // TOtal tc of code: O(logN * n)
{
    if(m>n)
    {
        return -1;  // if student>no.of books
    }
    int sum=0, maxValue = INT_MIN;
    for(int i = 0;i<n;i++)  // O(n)   
    {
        sum+=arr[i];
        maxValue = max(maxValue,arr[i]);
    }

    int ans=0;
    int st=maxValue, end=sum; // rangle of possible ans which is 0 to 10

    while(st<=end)   // O(logN)*O(n) = o(n*logN)
    {
        int mid = st + (end-st)/2;

        if(isValid(arr,n,m,mid)) // if mid is valid  tc:O(n)
        {
            ans=mid; // store ans if mid is valid
            end = mid-1; // have to go left to find minimun num of mamimun pages
        }
        else  // if mid is invalid
        {
            st = mid+1; // right for finding maximum pages
        }
    }
    return ans;
}


int main()
{
    vector<int> arr={2,1,3,4};
    int n=arr.size();
    int m = 2;  // no of students

    cout<<allocateBooks(arr,n,m);
    return 0;
}


// arr = [15, 17, 20], N = 3        M = 2

// sum : 52
// search space : 0 to 52
// mid = 26        ...Invalid

// search space : 27 to 52
// mid = 39        ...Valid

// search space : 27 to 38
// mid = 32        ...Valid

// search space : 27 to 31
// mid = 29        ...Invalid

// search space : 30 to 31
// mid = 30        ...Invalid

// search space : 31 to 31
// mid = 31        ...Invalid

// 32 is the ans