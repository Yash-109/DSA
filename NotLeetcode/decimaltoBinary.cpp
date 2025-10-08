#include<iostream>
using namespace std;

int decToBinary(int decNum){
    int ans=0,pow=1;
    while(decNum>0){
        int rem= decNum%2;
        decNum /=2;

        ans = ans + (rem*pow);
        pow *=10;
    }
    return ans;
}

int bintoDecimal(int binNum){
    int ans=0,pow=1;
    while(binNum>0){
        int rem= binNum%10;
        binNum /=10;

        ans= rem*pow;
        pow *=2;
    }
    return ans;
}
int main(){
    int decNum=4;
    for(int i=0;i<10;i++)
    {
        cout<<decToBinary(i)<<endl;
    }
    
    cout<<endl;
    cout<<bintoDecimal(100);
    return 0;
}