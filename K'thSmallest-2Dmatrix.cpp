//C++ program to find the Kth smallest element
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function to find the kth smallest element in a sorted 2D
// matrix
int findKthSmallest(vector<vector<int> >& matrix, int k)
{
    int n = matrix.size();

    // Create a vector to store all elements
    vector<int> elements;

    // Store all elements of the matrix into the vector
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            elements.push_back(matrix[i][j]);
        }
    }

    // Sort the vector
    sort(elements.begin(), elements.end());

    // Return the kth smallest element (1-based index, hence
    // k-1)
    return elements[k - 1];
}

int main()
{
    // Define the sorted 2D matrix
    vector<vector<int> > matrix
        = { { 1, 5, 9 }, { 10, 11, 13 }, { 12, 13, 15 } };
    int k = 8;
    int result = findKthSmallest(matrix, k);

    cout << "The " << k
         << "th smallest element is: " << result << endl;

    return 0;
}