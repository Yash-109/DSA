#include<iostream>
using namespace std;

bool isArmstrong(int n)
{
    int copy = n;
    int sumOfCubes = 0;
    while(n != 0)
    {
        int dig = n%10;
        sumOfCubes += (dig*dig*dig);
        n= n/10;
    }

    return sumOfCubes == copy;
}
int main()
{
    int n = 153;  // 1^3 + 5^3 + 3^3 = 153   means cube of each digits total sum = n itself --> Armstrong

    if(isArmstrong)
    {
        cout<<n<<" is an Armstrong number.\n";
    }
    else{
        cout<<n<<" is not an Armstrong number.\n";
    }
    return 0;

}