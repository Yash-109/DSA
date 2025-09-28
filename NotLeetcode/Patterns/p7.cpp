#include<iostream>
using namespace std;

// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********
void ptn1(int n)
{
    int space=0;
    for(int i=0;i<n;i++)
    {
        
        //stars
        for(int j=0;j<n-i;j++)
        {
            cout<<"*";
        }

        //space
        
        for(int j=0;j<space;j++)
        {
            cout<<" ";
        }
        //stars
        for(int j=0;j<n-i;j++)
        {
            cout<<"*";
        }
        space+=2;
        cout<<endl;
    }

    //2nd half:
        space = 2*n -2;
        for(int i=0;i<n;i++)
        {
            //stars
            for(int j=0;j<=i;j++)
            {   
                cout<<"*";
            }

            //space
            for(int j=0;j<space;j++)
            {
                cout<<" ";
            }
            //stars
            for(int j=0;j<=i;j++)
            {
                cout<<"*";
            }
            space-=2;
            cout<<endl;

        }
}

// **        **
// ***      ***
// ****    ****
// *****  *****
// ************
// *****  *****
// ****    ****
// ***      ***
// **        **
void ptn2(int n)
{
    int space= 2*n - 2;
    for(int i=1;i<=2*n-1;i++)   // if n=5 rows then loop = 9
    {
        int stars=i;
        if(i>n) stars= 2*n - i;

        //stars
        for(int j=0;j<=stars;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<=space;j++)
        {
            cout<<" ";
        }

        //stars
        for(int j=0;j<=stars;j++)
        {
            cout<<"*";
        }
        cout<<endl;

        if(i<n) space -= 2;
        else space +=2;
    }

}
int main()
{
    int n;
    cin>>n;
    // ptn1(n);
     ptn2(n);
    return 0;
}