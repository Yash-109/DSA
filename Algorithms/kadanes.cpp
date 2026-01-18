#include<iostream>
using namespace std;

// Kadane's Algorithm: Maximum Subarray Sum
// Time Complexity: O(n)
// Space Complexity: O(1)

int kadan()
{
    int n=5;
    int arr[] = {1,2,3,4,5};
    int maxsum=INT_MIN;
    int currsum=0;
    for(int i=0;i<n;i++)
    {
        currsum+=arr[i];
        maxsum= max(currsum,maxsum);  // reason for writing maxsum here is including edge(last element of array) cases

        if(currsum<0)
        {
            currsum=0;
        } 
    }
    cout<<"max:"<<maxsum;
    return 0;
}

//brutforce: o(n^2)
int main()
{
    int n=5;
    int arr[] = {1,2,3,4,5};
    int maxsum=INT_MIN;

    for(int st=0;st<n;st++)
    {
        int currentsum=0;
        for (int end=st;end<n;end++)
        {
            currentsum +=arr[end];
            maxsum = max(currentsum,maxsum);
        }
    }
    cout<<"maximum subarray sum:"<<maxsum<<endl;

    kadan();
    return 0;


}

