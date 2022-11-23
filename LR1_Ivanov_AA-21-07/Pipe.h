#pragma once
#include <iostream>
#include <string>
#include "utils.h"
using namespace std;
class Pipe
{
public:
		string name;
		int pipe_id;
		double length;
		double diametr;
		bool repair;
		static int max_pipe_id;

	Pipe();
	friend std::ostream& operator << (std::ostream& out, Pipe& t);
	friend std::istream& operator >> (std::istream& in, Pipe& t);
	
};

