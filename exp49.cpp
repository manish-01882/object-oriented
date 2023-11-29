#include <iostream>
#include <fstream>
#include <string>

int main() {
    // File writing (output)
    std::ofstream outputFile("file_pointer_example.txt"); // Open a file for writing

    if (!outputFile) {
        std::cerr << "Error opening the file for writing." << std::endl;
        return 1;
    }

    std::string dataToWrite = "This is a sample text. Writing to a file using C++.";

    outputFile << dataToWrite << std::endl; // Write data to the file

    // Move the file pointer to the beginning
    outputFile.seekp(0, std::ios::beg);

    // Append more data at the beginning of the file
    outputFile << "New Data: ";

    outputFile.close(); // Close the file

    std::cout << "Data has been written to the file." << std::endl;

    // File reading (input)
    std::ifstream inputFile("file_pointer_example.txt"); // Open the file for reading

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
