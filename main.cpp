#include <iostream>
#include <fstream>
#include </usr/local/include/json/value.h>
#include </usr/local/include/json/json.h>
// using namespace std;
int main()
{
    Json::Value people;
    std::ifstream people_file("keys.json", std::ifstream::binary);
    people_file >> people;

    std::cout << people["Anna"] << "\n";
    std::cout << people["Anna"]["profession"] << "\n";
}