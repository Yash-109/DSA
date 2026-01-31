// 2D Vectors - Dynamic 2D arrays
// Unlike 2D arrays, vectors are dynamic - size can change at runtime

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // ============ DECLARATION ============
    // Method 1: Initialize with values
    vector<vector<int>> mat = {{1, 2, 3}, 
                                {4, 5, 6}, 
                                {7, 18, 9}, 
                                {10, 11, 12}};
    
    // Method 2: Create empty vector with specific size
    // vector<vector<int>> mat(rows, vector<int>(cols, 0)); // rows x cols matrix with 0
    
    
    // ============ ACCESSING ELEMENTS ============
    // Accessing element at row 2, col 1
    cout << "Element at [2][1] = " << mat[2][1] << endl;  // Output: 18
    
    // Modifying element
    mat[2][1] = 99;
    cout << "After modification [2][1] = " << mat[2][1] << endl;  // Output: 99
    mat[2][1] = 18; // Reset back
    
    
    // ============ DYNAMIC SIZE ============
    // In vectors, size is dynamic, so we use mat.size() and mat[i].size()
    int rows = mat.size();           // Number of rows
    int cols = mat[0].size();        // Number of columns (assuming all rows have same cols)
    
    cout << "\nRows: " << rows << ", Cols: " << cols << endl;
    
    
    // ============ INPUT ============
    cout << "\nEnter " << rows << "x" << cols << " matrix elements:" << endl;
    for(int i = 0; i < mat.size(); i++)      // mat.size() gives rows
    {
        for(int j = 0; j < mat[i].size(); j++)  // mat[i].size() gives cols
        {
            cin >> mat[i][j];
        }
    }
    
    
    // ============ OUTPUT ============
    cout << "\nMatrix:" << endl;
    for(int i = 0; i < mat.size(); i++)      // Dynamic row iteration
    {
        for(int j = 0; j < mat[i].size(); j++)  // Dynamic col iteration
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    
    // ============ FINDING ELEMENT INDEX ============
    int key = 18;
    cout << "\nSearching for element " << key << "..." << endl;
    
    bool found = false;
    for(int i = 0; i < mat.size(); i++)
    {
        for(int j = 0; j < mat[i].size(); j++)
        {
            if(mat[i][j] == key)
            {
                cout << "Element " << key << " found at index [" << i << "][" << j << "]" << endl;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    
    if(!found) {
        cout << "Element " << key << " not found!" << endl;
    }
    
    
    // ============ DYNAMIC OPERATIONS ============
    // Add a new row
    mat.push_back({13, 14, 15});
    cout << "\nAfter adding new row, size: " << mat.size() << "x" << mat[0].size() << endl;
    
    
    return 0;
}

