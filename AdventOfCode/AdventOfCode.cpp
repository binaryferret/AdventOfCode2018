#include "stdafx.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <iterator>
#include <unordered_set>
#include <algorithm>

#include "Day1.h"
#include "Day2.h"

int main()
{
	/*std::cout << "Started Advent 1 part 1" << std::endl;
	Advent1_1();
	std::cout << "Started Advent 1 part 2" << std::endl;
	Advent1_2();
	std::cout << "Started Advent 1 part 2_1" << std::endl;
	Advent1_2_1();*/
	/*std::cout << "Started Advent 1 part 2_2" << std::endl;
	Advent1_2_2();*/
	
	/*std::clock_t begin = std::clock();
		Day2Part1();
	std::clock_t end = std::clock();
	double secsGone = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Day 2 Part 1 TOOK {" << secsGone << "}" << std::endl;

	begin = std::clock();
		Day2Part2();
	end = std::clock();
	secsGone = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Day 2 Part 2 TOOK {" << secsGone << "}" << std::endl;*/

	std::clock_t begin = std::clock();
	Day2Part2_1();
	std::clock_t end = std::clock();
	double  secsGone = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Day 2 Part 2_1 TOOK {" << secsGone << "}" << std::endl;

	return 0;
}


