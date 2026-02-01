// 2D Array Operations: Linear Search, Max Row Sum, and Diagonal Sum

#include<iostream>
using namespace std;

// ============ LINEAR SEARCH ============
// Search for a key in 2D matrix and return its position (i, j)
// Time Complexity: O(rows * cols)
pair<int,int> linearSearch(int mat[][3], int rows, int cols, int key)  // we must specify no of colums every time
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(mat[i] [j] == key)
            {
                return {i, j};  // return the position (i, j)
            }
        }
    }
    return {-1, -1};  // element not found
}

// ============ MAX ROW SUM ============
// Find the maximum sum among all rows
// Time Complexity: O(rows * cols)
int getMaxSum(int mat[][3],int rows, int cols)
{
    int maxRowSum = INT_MIN;
    for(int i=0; i<rows; i++)
    {
        int rowSum = 0;
        for(int j=0; j< cols; j++)
        {
            rowSum+= mat[i] [j];
        }
        maxRowSum = max(maxRowSum,rowSum);
    }
    return maxRowSum;
}

// ============ DIAGONAL SUM (For Square Matrix) ============
// Calculate sum of both diagonals
// Time Complexity: O(n²) - Brute Force approach
int diagonalSum(int mat[][4], int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // in odd sized matrix center ele satisfy both condition i==j & j == n-i-1
            // by  else if we can prevent adding it twice
            
            // Primary Diagonal: i == j (top-left to bottom-right)
            if(i == j) {
                sum += mat[i][j];
            }
            // Secondary Diagonal: j == n-i-1 (top-right to bottom-left)
            else if(j == n-i-1) {
                sum += mat[i][j];
            }  // this else if stemnt does not run for center element bcz alreadyfirst condition become tru i == j
        }
    }
    return sum;
}

// ============ DIAGONAL SUM - OPTIMIZED ============
// Calculate sum of both diagonals in single loop
// Time Complexity: O(n) - Optimal approach
int diagonalSumOptimal(int mat[][4], int n)
{
    int sum = 0;
    //pd : i = j   // Primary diagonal index: (i, i)
    //sd : j = n-i-1  // Secondary diagonal index: (i, n - i - 1)

//     i	Primary (i,i)	Secondary (i,4-i)	Same?
//     0	(0,0)	(0,4)	No
//     1	(1,1)	(1,3)	No
//     2	(2,2)	(2,2)	Yes (center)
//     3	(3,3)	(3,1)	No

        // For all non-center rows, this condition is true, 
        //so the secondary diagonal element is added.

        //At the center row, i == n - i - 1, so the condition is false,
        // and the element is not added again.
    
    for(int i=0; i<n; i++)
    {
        sum += mat[i][i];  // Primary diagonal
        
        if(i != n-i-1) {   // Secondary diagonal
    // if(i != n - i - 1) prevents adding the same center element twice when both diagonals intersect in an odd-sized matrix.
            sum += mat[i][n-i-1];  
        }
    }
    return sum;
}

int main()
{
    int matrixxx[4] [3] = {{1,2,3}, {4,5,60}, {7,8,9}, {10,11,12}};
    int rows = 4;
    int cols = 3;

    // Test Linear Search
    pair<int,int> result = linearSearch(matrixxx,rows,cols,8);
    cout << "Element found at: (" << result.first << ", " << result.second << ")" << endl;

    // Test Max Row Sum
    cout << "Max sum of rows = " << getMaxSum(matrixxx,rows,cols) << endl;
    /* 
    For Column Sum (similar to row sum):
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += mat[i][j];
        }
    }
    */

    
    // Test Diagonal Sum (Square Matrix)
    int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = 4;
    cout << "Diagonal Sum (Brute Force) = " << diagonalSum(matrix, n) << endl;
    cout << "Diagonal Sum (Optimal) = " << diagonalSumOptimal(matrix, n) << endl;
    
    


    
    return 0;
    
}