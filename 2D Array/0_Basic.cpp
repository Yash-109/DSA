#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};

    int matrixxx[4] [3];
    int rows = 4;
    int cols = 3;

    // cell = (row,cols)

    cout<< matrixxx[2] [1]<<endl; // random value 

    matrixxx[2] [1] = 18;
    cout<< matrixxx[2] [1]<<endl;// 18

    //input
    for(int i=0;i<rows;i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin>>matrixxx[i] [j];
        }
    }

    //output
    for(int i=0;i<rows;i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout<<matrixxx[i] [j]<<" ";
        }
        cout<<endl;

        /*
        1 2 3
        4 5 6
        7 18 9
        10 11 12
        */
    }

    return 0;
}