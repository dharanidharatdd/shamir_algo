#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include "/usr/local/include/json/json.h"

using json = nlohmann::json;

// Function to convert a string from a given base to decimal
int convertToDecimal(const std::string& value, int base) {
    int decimalValue = 0;
    int power = 0;
    for (int i = value.size() - 1; i >= 0; --i) {
        int digit = value[i] - '0';
        decimalValue += digit * pow(base, power);
        power++;
    }
    return decimalValue;
}

// Function to calculate the value of c using Lagrange Interpolation
double lagrangeInterpolation(const std::vector<int>& x, const std::vector<double>& y, double xi) {
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
    // Read JSON file
    std::ifstream ifs("data.json");
    if (!ifs) {
        std::cerr << "Failed to open data.json" << std::endl;
        return 1;
    }

    json data;
    ifs >> data;

    // Extract keys and values from JSON
    int n = data["keys"]["n"];
    int k = data["keys"]["k"];

    std::vector<int> x;
    std::vector<double> y;

    for (int i = 1; i <= n; ++i) {
        std::string base = data[std::to_string(i)]["base"];
        std::string value = data[std::to_string(i)]["value"];

        int xi = std::stoi(std::to_string(i)); // x coordinate
        int yi; // y coordinate in decimal

        // Convert value to decimal based on the given base
        if (base == "10") {
            yi = std::stoi(value);
        } else if (base == "2") {
            yi = convertToDecimal(value, 2);
        } else if (base == "4") {
            yi = convertToDecimal(value, 4);
        } else {
            std::cerr << "Unsupported base: " << base << std::endl;
            return 1;
        }

        // Store x and y coordinates
        x.push_back(xi);
        y.push_back(static_cast<double>(yi)); // store y as double for interpolation
    }

    // Finding the value of c corresponding to x = 0 (using Lagrange Interpolation)
    double xi = 0;
    double c = lagrangeInterpolation(x, y, xi);

    // Output the value of c
    std::cout << "The value of c is: " << c << std::endl;

    return 0;
}
