#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

void IDFT(std::vector<std::complex<double>>& X, int N) {
    std::vector<std::complex<double>> x(N, 0.0); // Initialize the IDFT output vector x

    for (int n = 0; n < N; n++) {
        std::complex<double> x_n = std::complex<double>(0.0, 0.0); // Initialize x_n for the current n
        for (int k = 0; k < N; k++) {
            double angle = 2.0 * M_PI * k * n / N; // Calculate the phase angle
            std::complex<double> exp_term(std::cos(angle), std::sin(angle)); // Calculate the complex exponential term
            x_n += X[k] * exp_term; // Perform the IDFT calculation
        }
        x[n] = x_n / static_cast<double>(N);
    }

    // x now contains the IDFT values

    for (int n = 0; n < N; n++) {
        std::cout << "x[" << n << "] = " << x[n] << std::endl;
    }
}

int main() {
    // Provide the input data vector 'X' and its size 'N'
    std::vector<std::complex<double>> X = /* Initialize X with your data */;
    int N = X.size();
    
    IDFT(X, N); // Compute and display the IDFT of the sequence
    
    return 0;
}
