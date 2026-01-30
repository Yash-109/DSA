#include<iostream>
#include<cmath>
using namespace std;

void printDigits(int n)
{
    int count = 0;
    int sum=0;
    while(n != 0)  // tc is O(log n) base = 10 because we divide n by 10
                   // tc is O(log n) base = 2 if we divivde by 2
    {
        int digit = n%10;
        cout<< digit << " ";
        n = n / 10;
        count++;
        sum += digit;

    }
    cout<<endl;
    cout<< "count is "<< count;
    cout<<endl;
    cout<< "Sum is "<< sum;
}

int main()
{
    int n = 37652;
    cout<<"Number = "<<n<<endl;
    cout<< "Digits = ";
    printDigits(n);

    cout<<endl;
    cout<<endl;

    // short function to get digits directly wihtout while loop
    cout<< (int) (log10(n) + 1)<<endl;  // have to include #include<cmath> 
    return 0;
}