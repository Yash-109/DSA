#include<iostream>
#include<vector>
using namespace std;


int binarysearch(vector<int> arr, int tar)
{
    int st=0, end=arr.size()-1;
    
    while(st<=end)   // = because in worst case st=end and returns mid 
    {

       int mid = st + (end-st)/2;   // takle overflow: (st + end)/2

        if(tar > arr[mid])
        {
            st = mid+1;
        }
        else if(tar<arr[mid])
        {
            end = mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;     // if target doesn't exist.
}

int recursiveBS(vector<int> arr,int tar,int st,int end)
{
    if(st<=end)
    {
        int mid = st + (end-st)/2;

        if(tar> arr[mid])
        {
            recursiveBS(arr,tar,mid+1,end);
        }
        else if(tar< arr[mid])
        {
            recursiveBS(arr,tar,st,mid-1);
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr1= {-1,0,3,4,5,9,12};  // odd size
    int tar1=12;

    cout<<binarysearch(arr1,tar1)<<endl; // iterative
    
    tar1=40; 
    cout<<binarysearch(arr1,tar1)<<endl; // iterative

    vector<int> arr2= {-1,0,3,5,9,12};  // even size
    int tar2=3;

    cout<<binarysearch(arr2,tar2)<<endl;  // iterative


    cout<<recursiveBS(arr1,tar1,0,arr1.size()-1)<<endl; // Recursive

}