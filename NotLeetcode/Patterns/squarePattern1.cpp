#include<iostream>
using namespace std;

int main(){
    int n=4;
    for(int i=0;i<n;i++){
        int m=4;
        char ch='A';
        for(int j=1;j<=m;j++){
            cout<<ch;
            ch += 1;
        }
        cout<<endl;
    }

    return 0;
}