#include "datatypes.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Field::Field(int n, int m)
	: _n(n), _m(m) {
	cerr << "Field() called" << endl;
	_data = new byte[n * m];
}

Field* Field::readFromFile(const std::string &filename) {
	ifstream fin;
	fin.open(filename.c_str());
	int n, m;
	fin >> n >> m;
	
	Field *field = new Field(n, m);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			int el;
			fin >> el;
			field->_data[i * m + j] = el;
		}
		
	fin.close();
	return field;
}

void Field::writeToFile(const std::string &filename) const {
	ofstream fout;
	fout.open(filename.c_str());
	fout << _n << ' ' << _m << '\n';
	
	for (int i = 0; i < _n; i++) {
		for (int j = 0; j < _m; j++) 
			fout << (int) _data[i * _m + j] << ' ';
		fout << '\n';
	}
		
	fout.close();
}