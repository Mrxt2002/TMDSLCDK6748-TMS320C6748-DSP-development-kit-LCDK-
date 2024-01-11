// C++ program to compute circular convolution of two arrays
#include <iostream>
using namespace std;

#define MAX_SIZE 10

// Function to find circular convolution
void convolution(vector<int> &x, vector<int> &h, int n, int m)
{
    int row_vec[MAX_SIZE], col_vec[MAX_SIZE];
    int out[MAX_SIZE] = {0};
    int circular_shift_mat[MAX_SIZE][MAX_SIZE];

    // Finding the maximum size between the two input sequence sizes
    int maxSize = n > m ? n : m; // when n>m , maxSize is n else its m

    // Copying elements of x to row_vec and padding with zeros if size of x < maxSize
    for (int i = 0; i < maxSize; i++)
    {
        if (i >= n)
        {
            row_vec[i] = 0;
        }
        else
        {
            row_vec[i] = x[i];
        }
    }

    // Copying elements of h to col_vec and padding with zeros if size of h is less than maxSize
    for (int i = 0; i < maxSize; i++)
    {
        if (i >= m)
        {
            col_vec[i] = 0;
        }
        else
        {
            col_vec[i] = h[i];
        }
    }

// Generating a 2D matrix of circularly shifted elements
    int k = 0, d = 0;
    for (int i = 0; i < maxSize; i++)
    {
        int curIndex = k - d;
        for (int j = 0; j < maxSize; j++)
        {
            circular_shift_mat[j][i] = row_vec[curIndex % maxSize];
            curIndex++;
        }
        k = maxSize;
        d++;
    }

    // Computing the result by matrix multiplication and printing results
    for (int i = 0; i < maxSize; i++)
    {
        for (int j = 0; j < maxSize; j++)
        {
            out[i] += circular_shift_mat[i][j] * col_vec[j];
        }
        cout << out[i] << " ";
    }

    // Generating a 2D matrix of circularly shifted elements
for (int i = 0; i < N; i++)
{
    int curIndex = i; // Start with the current row index
    for (int j = 0; j < N; j++)
    {
        circular_shift_mat[i][j] = row_vec[curIndex % N]; // Store the circularly shifted element
        curIndex++; // Move to the next element in row_vec
    }
}

// Computing the result by matrix multiplication and printing results
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        out[i] += circular_shift_mat[i][j] * col_vec[j];
    }
    cout << out[i] << " "; // Print the result
}

}


// Driver program
// int main()
// {
//     vector<int> x = {5, 7, 3, 2};
//     int n = x.size();
//     vector<int> h = {1, 5};
//     int m = h.size();
//     convolution(x, h, n, m);
//     return 0;
// }