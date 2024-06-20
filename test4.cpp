#include <iostream>
#include <fstream>
#include "/usr/local/include/json/json.h"

int main() {
    // Load and parse JSON from a file
    Json::Value root;
    Json::Reader reader;
    
    std::ifstream ifs("./keys.json");
    if (!reader.parse(ifs, root)) {
        std::cerr << "Failed to parse JSON" << std::endl;
        return 1;
    }
    
    // Access keys and values
    int n = root["keys"]["n"].asInt();
    int k = root["keys"]["k"].asInt();
    
    // Process x and y coordinates
    for (int i = 1; i <= n; ++i) {
        std::string base = root[std::to_string(i)]["base"].asString();
        std::string value = root[std::to_string(i)]["value"].asString();
        
        int xi = i; // x coordinate
        int yi; // y coordinate
        
        // Convert value to decimal based on the given base
        if (base == "10") {
            yi = std::stoi(value);
        } else if (base == "2") {
            // Convert binary value to decimal
            yi = std::stoi(value, nullptr, 2);
        } else if (base == "4") {
            // Convert quaternary value to decimal
            yi = std::stoi(value, nullptr, 4);
        } else {
            std::cerr << "Unsupported base: " << base << std::endl;
            return 1;
        }
        
        // Process x and y coordinates as needed
        std::cout << "x" << i << ": " << xi << ", y" << i << ": " << yi << std::endl;
    }
    
    return 0;
}
