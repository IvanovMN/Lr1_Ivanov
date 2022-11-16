#pragma once
#include <iostream>
#include <string>
class Pipe
{
	
public:
	std::string name;
	int id1;
	float length;
	float diametr;
	bool repair;
	friend std::ostream& operator << (std::ostream& out, const Pipe& t);
	friend std::istream& operator >> (std::istream& in, Pipe& t);
	
};

