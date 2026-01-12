// Painter’s Partition Problem

//          """Pattern: minimum of maximum or maximum of minimum"""
//           """ min possible max time"""

// Given are N boards of length of each given in the form of array, and M painters, such that each painter takes 1 unit of time to paint 1 unit of the board.

// The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards.

// if arr = [40,30,10,20] and m = 2(no. of painters)
// n = 4 (no. of boards)

// then possible case :  p1=40, p2=60   max = 60
//                       p1=70, p2=30   max = 70 
//                       p1=80, p2=20   max = 80

//         we need minimum time to paint so ans is first case: 60


#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> arr,int n,int m,int maxAllowedMinutes) // O(n)
{
    int painter=1, minutes=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > maxAllowedMinutes)  // edge case
        {
            return false;
        }
        if(minutes + arr[i] <= maxAllowedMinutes)
        {
            minutes+=arr[i];
        }
        else
        {
            painter++;
            minutes=arr[i];
        }
    }
    return painter > m ? false:true;
}
int allocatePainter(vector<int> &arr,int n, int m)  //total tc : O(n * log(sum))
{
    if(m>n)  // edge case
    {
        return -1;
    }

    int time=0, maxValue = INT_MIN;
    for(int i=0;i<n;i++)                // O(n)
    {
        time+=arr[i];   // total possible time
        maxValue = max(maxValue,arr[i]);
    }

    int ans=0;
    int st=maxValue,end=time;  // st is minimum time to paint all board and end = maximum time

    while(st<=end)  // binary search logic       //O(log(sum))
    {
        int mid = st + (end-st)/2;

        if(isValid(arr,n,m,mid))
        {
            ans = mid;
            end = mid-1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}       
int main()
{
    vector<int> arr={40,30,10,20};
    int n=arr.size();
    int  m= 2;

    cout<<allocatePainter(arr,n,m);

    return 0;
}
