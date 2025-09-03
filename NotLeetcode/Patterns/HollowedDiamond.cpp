    #include<iostream>
    using namespace std;

    int main()
    {
        int n=4;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++) //for space just like pyramid
            {
                cout<<" ";
            }
            cout<< "*";  // left star

            if(i!=0)        // condotion bcz in first line we dont want any space or *
            {
                for(int j=0;j<2*i-1;j++) // Spaces between left and right stars
                {
                    cout<<" ";
                }
                cout<< "*"; // right star

            }
            cout<<endl;
        }

        // bottom part:

        for(int i=0;i<n-1;i++) // outerloop
        {
            for(int j=0;j<i+1;j++)
            {
                cout<<" ";
            }
            cout<<"*";  // left star

            if(i!=n-2) // condition bcz in last line (n-2) we dont want any other spce or again *
            {
                for(int j=0;j<2*(n-i)-5;j++) // Spaces between left and right stars
                {
                    cout<< " ";
                }
                cout<<"*"; // right star
            }
            cout<<endl;
        }
        return 0;
    }