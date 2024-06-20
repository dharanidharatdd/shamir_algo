#include <iostream>
#include <vector>

// Function to calculate the secret using Lagrange interpolation
int reconstruct_secret(int N, int K, const std::vector<int>& x, const std::vector<int>& y) {
    int secret = 0;

    for (int i = 0; i < K; ++i) {
        int term = y[i];
        for (int j = 0; j < K; ++j) {
            if (i != j) {
                term = (term * (0 - x[j])) % x[i] - x[j];
            }
        }
        secret = (secret + term) % x[i];
    }

    return secret;
}

int main() {
    // Example values
    int N = 4; // Total number of shares
    int K = 3; // Number of shares required to reconstruct the secret

    // Example shares (x, y coordinates)
    std::vector<int> x = {1, 2, 3, 6};
    std::vector<int> y = {4, 7, 12, 39};

    // Check if enough points are provided
    if (x.size() < K || y.size() < K) {
        std::cerr << "Not enough points to reconstruct the secret." << std::endl;
        return 1;
    }

    // Reconstruct the secret using the provided shares
    int secret = reconstruct_secret(N, K, x, y);

    // Output the reconstructed secret
    std::cout << "Reconstructed Secret Code: " << secret << std::endl;

    return 0;
}
