#include<bits/stdc++.h>
using namespace std;

void printIntersection(int arr1[], int sz1, int arr2[], int sz2)
{
    cout<<"Intersection: ";
    for(int i=0;i<sz1;i++)
    {
        for(int j=0;j<sz2;j++)
        {
            if(arr1[i]==arr2[j])
            {
                cout<<arr1[i]<<" ";
                break; // Avoid printing duplicates from arr1
            }
        }
    }
    cout<<endl;
}

int main()
{
    int arr1[]={1,2,3,4,5};
    int arr2[]={3,4,5,6,7};
    
    int sz1=sizeof(arr1)/sizeof(int);
    int sz2=sizeof(arr2)/sizeof(int);
    
    cout<<"Array 1: ";
    for(int i=0;i<sz1;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Array 2: ";
    for(int i=0;i<sz2;i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    
    printIntersection(arr1, sz1, arr2, sz2);
}
