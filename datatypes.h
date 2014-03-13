#ifndef DATATYPES_H
#define DATATYPES_H

#include <string>

typedef unsigned char byte;

class Field {
public:
	Field(int n, int m);
	static Field* readFromFile(const std::string &filename);
	void writeToFile(const std::string &filename) const;	
	
private:
	byte *_data;
	int _n;
	int _m;
};

#endif // DATATYPES_H