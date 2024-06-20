#include <iostream>
#include <vector>

// Function to calculate the value of c using Lagrange Interpolation
double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi) {
    int n = x.size();
    double result = 0.0;

    for (int i = 0; i < n; ++i) {
        double term = y[i];
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    // Given x and y values
    std::vector<double> x = {1, 2, 3, 6};
    std::vector<double> y = {4, 7, 12, 39};

    // Finding the value of c corresponding to x = 0 (using Lagrange Interpolation)
    double xi = 0;
    double c = lagrangeInterpolation(x, y, xi);

    // Output the value of c
    std::cout << "The value of c is: " << c << std::endl;

    return 0;
}