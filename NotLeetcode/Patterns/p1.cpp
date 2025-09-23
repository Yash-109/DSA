#include<iostream>
using namespace std;
void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}

void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1<<" ";
        }
        cout<<"\n";
    }
}

void pattern3(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<i+1<<" ";
        }
        cout<<"\n";
    }
}


int main(){
    int t;
    cin>>t;      // for test case enter: how many pattern want to print
    for(int i=0;i<t;i++){
       int n;
       cin>>n;        // no of rows for each pattern particular
       pattern1(n);          
       pattern2(n);
       pattern3(n);

    }
    
    return 0;
}