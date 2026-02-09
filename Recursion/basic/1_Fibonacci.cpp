// for fibonacci term(n) = term(n-1) + term(n-2)
// fibonacci: 0,1,1,2,3,5,8,13,...
#include<iostream>
using namespace std;

int fibonacci(int n){
        if(n==0 || n==1){
            return n;
        }
        else{
            return fibonacci(n-1) + fibonacci(n-2);
        }
}
int main(){
    
    cout<<fibonacci(3);
    return 0;
}