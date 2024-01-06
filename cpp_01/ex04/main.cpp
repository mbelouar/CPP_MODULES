#include <iostream>
#include <fstream>
#include <string>

void replaceAndWriteToFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    if (s1.empty()) { // Check if the s1 is empty ==> do nothing
        return;
    }

    std::ifstream inputFile(filename.c_str());  // Use .c_str() to convert std::string to const char*

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::ofstream outputFile((filename + ".replace").c_str());  // Use .c_str() here as well

    if (!outputFile.is_open()) {
        std::cerr << "Error creating output file." << std::endl;
        inputFile.close();
        return;
    }

    std::string line;
    while (getline(inputFile, line)) {
        size_t pos = 0;
        size_t searchLen = s1.length();

        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + searchLen);
            pos += s2.length();
        }

        outputFile << line << std::endl;
    }

    std::cout << "Replacement completed successfully." << std::endl;

    inputFile.close();
    outputFile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replaceAndWriteToFile(filename, s1, s2);

    return 0;
}
