#include <iostream>
#include <fstream>
#include <string>

int main() {
    // File writing (output)
    std::ofstream outputFile("sample.txt"); // Open a file for writing

    if (!outputFile) {
        std::cerr << "Error opening the file for writing." << std::endl;
        return 1;
    }

    std::string dataToWrite = "This is a sample text. Writing to a file using C++.";

    outputFile << dataToWrite << std::endl; // Write data to the file
    outputFile.close(); // Close the file

    std::cout << "Data has been written to the file." << std::endl;

    // File reading (input)
    std::ifstream inputFile("sample.txt"); // Open the same file for reading

    if (!inputFile) {
        std::cerr << "Error opening the file for reading." << std::endl;
        return 1;
    }

    std::string readData;
    while (std::getline(inputFile, readData)) {
        std::cout << "Read from file: " << readData << std::endl;
    }

    inputFile.close(); // Close the file

    return 0;
}
