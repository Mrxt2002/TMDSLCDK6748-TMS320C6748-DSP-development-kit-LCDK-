#include <stdio.h>

#define MAX_SIZE 10

// Function to find the linear convolution of two sequences
void linear_convolution(int x[], int h[], int n, int m) {
    int x1[MAX_SIZE], x2[MAX_SIZE];
    int out[MAX_SIZE] = {0};

    // Copy elements from the x array to the x1 array
    for (int i = 0; i < n; i++) {
        x1[i] = x[i];
    }

    // Copy elements from the h array to the x2 array
    for (int i = 0; i < m; i++) {
        x2[i] = h[i];
    }

    // Calculate the linear convolution and store it in the 'out' array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out[i + j] += x1[i] * x2[j];
        }
    }

    // Print the result of linear convolution
    for (int i = 0; i < n + m - 1; i++) {
        printf("%d ", out[i]);
    }
}

int main() {
    int x[] = {5, 7, 3, 2};
    int n = sizeof(x) / sizeof(x[0]);
    int h[] = {1, 5};
    int m = sizeof(h) / sizeof(h[0]);
    linear_convolution(x, h, n, m);
    return 0;
}
