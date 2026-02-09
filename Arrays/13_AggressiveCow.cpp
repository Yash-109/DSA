// Aggressive Cows Problem

//          """Pattern: minimum of maximum or maximum of minimum"""
//             """max possible minimum distance"

// Assign C cows to N stalls such that min distance between them is largest possible.
// Return largest minimum distance.

// N = 5
// arr = [1, 2, 8, 4, 9]
// C = 3

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


bool isPossible(vector<int> &arr,int n,int c,int minAllowedDistance )  // O(n)
{
    int cows=1, lastStallPos=arr[0];

    for(int i=1;i<n;i++)
    {
        if(arr[i] - lastStallPos >= minAllowedDistance)
        {
            cows++;
            lastStallPos = arr[i];
        }

        if(cows == c)
        {
            return true;
        }
    }
    return false;
}

int getDistance(vector<int> &arr,int n, int c)  // 
{
    sort(arr.begin(), arr.end());    // O(nlogn)
    // st = 1 bcz minimum distace would be 1 between two cows

    int st = 1, end = arr[n-1]-arr[0];  
    int ans = -1;

    while(st<=end)         // O(log (Range) * n )
    {
        int mid = st + (end-st)/2;

        if(isPossible(arr,n,c,mid))  //O(n)
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr ={1,2,8,4,9};
    int n = arr.size(), c = 3;  // c = cows

    cout<<getDistance(arr,n,c);
    return 0;
}