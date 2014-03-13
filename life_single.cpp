#include <iostream>
#include <string>
#include <cstdlib>

#include "datatypes.h"

using namespace std;

void print_usage() {
	cout << "Usage: life_single -i input_file -o output_file" << endl;
}

void parse_arguments_or_die(int argc, char *argv[], 
	string &input_filename, string &output_filename) {
	if (argc != 5) {
		print_usage();
		exit(EXIT_FAILURE);
	}
	
	if (string(argv[1]) != "-i") {
		print_usage();
		exit(EXIT_FAILURE);
	} else {
		input_filename = argv[2];
	}
	
	if (string(argv[3]) != "-o") {
		print_usage();
		exit(EXIT_FAILURE);
	} else {
		output_filename = argv[4];
	}	
}

int main(int argc, char *argv[]) {
	string input_filename, output_filename;
	parse_arguments_or_die(argc, argv, input_filename, output_filename);
	
	cerr << "Reading in the field..." << endl;
	Field *field = Field::readFromFile(input_filename);
	
	cerr << "Writing the result to " << output_filename << endl;
	field->writeToFile(output_filename );
}