// To find linear convolution from circular convolution

#include<iostream>
#include<vector>
using namespace std;
# define MAX_SIZE 10
//function to find linear convolution from circular convolution
void LinearConvolution_fromCircularConvolution(vector<int>&x,vector<int>&y,int n, int m){
int row_vec[MAX_SIZE], col_vec[MAX_SIZE];
    int out[MAX_SIZE] = {0};
    int circular_shift_mat[MAX_SIZE][MAX_SIZE];

    int N = n+m-1;

    // Copying elements of x to row_vec and padding with zeros if size of x < N
for (int i = 0; i < N; i++)
{
    if (i < n)
    {
        row_vec[i] = x[i];
    }
    else
    {
        row_vec[i] = 0;
    }
}
    
    // Copying elements of h to col_vec and padding with zeros if size of h < N
    for (int i = 0; i < N; i++)
    {
        if (i < m)
    {
        col_vec[i] = h[i];
    }
    else
    {
        col_vec[i] = 0;
    }
    }
}