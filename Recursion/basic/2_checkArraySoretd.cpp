#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int> arr,int n){ // tc and sc : o(n)
    if(n == 0 || n==1) return true;
    else{
        return arr[n-1] > arr[n-2] && isSorted(arr,n-1);
    }
}
int main()
{
    vector<int> a = {1,3,6,8,7};
    cout<<isSorted(a,a.size());  // 0 = false

    return 0;
}