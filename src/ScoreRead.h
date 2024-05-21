#ifndef SCORE_WRITER_H
#define SCORE_WRITER_H

#include <iostream>
#include <fstream>
#include <string>

void writeFile(const std::string& filename, int score, const std::string& name) {
    // Open the file in append mode
    std::ofstream outFile(filename, std::ios_base::app);

    // Check if the file is successfully opened
    if (outFile.is_open()) {
        // Write score and name into file as a new row, followed by a newline character
        outFile << score << "\t" << name << std::endl;

        // Close the file after writing
        outFile.close();

        // Print a success message
        std::cout << "Data appended to " << filename << " successfully." << std::endl;
    } else {
        // If the file cannot be opened, print an error message
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}


#endif // SCORE_WRITER_H
