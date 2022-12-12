#pragma once
#include <string>
#include <iostream>
#include "utils.h"
class Stations

{
public:
	static int max_cs_id;
	int cs_id;
	std::string name_CS;
	double active_workshop;
	double effiency;
	double workshop;
	double k;
	Stations();
	friend std::ostream& operator << (std::ostream& out, Stations& y);
	friend std::istream& operator >> (std::istream& in, Stations& y);
	friend void Edit_cs(Stations&y);

};

