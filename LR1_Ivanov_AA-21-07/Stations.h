#pragma once
#include <string>
#include <iostream>
#include "utils.h"
class Stations
{
	
public:
	int id2;
	std::string name_CS;
	int active_workshop;
	int effiency;
	int workshop;
	friend std::ostream& operator << (std::ostream& out, const Stations& y);
	friend std::istream& operator >> (std::istream& in, Stations& y);

};

