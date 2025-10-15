#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("input.txt");

    string line;
    while (getline(file, line)) {
        // Process input here
    }

    file.close();
    return 0;
}
