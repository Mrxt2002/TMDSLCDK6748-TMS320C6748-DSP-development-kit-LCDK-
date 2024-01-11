#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

void DFT(std::vector<int> &x, int n)
{
    int N = n; 
    int M_PI= 22/7;                                  // Assuming N is the same as the size of the input vector x
    std::vector<std::complex<double>> X(N, 0.0); // Initialize the DFT output vector X

    for (int k = 0; k < N; k++)
    {
        X[k] = std::complex<double>(0.0, 0.0); // Initialize the real and imaginary parts of X[k]
        for (int n = 0; n < N; n++)
        {
            double angle = -2.0 * M_PI * k * n / N;                          // Calculate the phase angle
            std::complex<double> exp_term(std::cos(angle), std::sin(angle)); // Calculate the complex exponential term
            X[k] += x[n] *exp_term;                                         // Perform the DFT calculation
        }
    }

    // X now contains the DFT coefficients

    for (int k = 0; k < N; k++)
    {
        std::cout << "X[" << k << "] = " << X[k] << std::endl;
    }
}

int main()
{
    // Provide the input data vector 'x' and its size 'n'
    std::vector<int> x = /* Initialize x with your data */;
    int n = x.size();

    DFT(x, n); // Compute and display the DFT of the sequence

    return 0;
}
