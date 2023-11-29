#include <iostream>
#include <fstream>

int main() {
    // Step i: Open file1.txt and file2.txt in read mode
    std::ifstream file1("file1.txt");
    std::ifstream file2("file2.txt");

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Failed to open input files." << std::endl;
        return 1;
    }

    // Step ii: Open file3.txt in write mode
    std::ofstream file3("file3.txt");

    if (!file3.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    // Step iii: Copy characters from file1.txt to file3.txt
    char ch;
    while (file1.get(ch)) {
        file3.put(ch);
    }

    // Step iv: Copy characters from file2.txt to file3.txt
    while (file2.get(ch)) {
        file3.put(ch);
    }

    // Step v: Close all files
    file1.close();
    file2.close();
    file3.close();

    std::cout << "Files copied successfully." << std::endl;

    return 0;
}
