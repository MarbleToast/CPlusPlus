#include <iostream>
#include <fstream>

#include "CustomerList.h"

// Main function, entry point to program
int main(int argc, char *argv[]) {

    // Expecting two arguments (executable name + input file)
	if (argc != 2) {
		std::cerr << "Invalid syntax.\nSyntax: ordering [inputFile.txt]" << std::endl;
		return EXIT_FAILURE;
	}

    // Check to see if the file could be opened
	std::ifstream input(argv[1]);
	if (!input.is_open()) {
		std::cerr << "There was a problem opening the file. Please try again." << std::endl;
		return EXIT_FAILURE;
	}

    // Create list object, start main loop
	CustomerList customer_list;
	if (!customer_list.read_file(input)) {
		std::cerr << "The above error occurred when trying to read the file." << std::endl;
		return EXIT_FAILURE;
	};

    // Check for bad bit flipped in file handling
	bool is_bad = input.bad();
	input.close();

	if (is_bad) {
		std::cerr << "There was a problem reading from the file. The file is corrupted." << std::endl;
		return EXIT_FAILURE;
	}
}