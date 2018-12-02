#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <ctime>

// Output
// Started Advent 1 part 1
// Advent 1 - Frequency Result = 466
// Started Advent 1 part 2
// TOOK{ 3.455 }Advent 1 part 2 - First Frequency reached twice = 750
// Started Advent 1 part 2_1
// TOOK{ 2.994 }Advent 1 part 2_1 - First Frequency reached twice = 750

// TODO Have a look at doing a smarter implemention rather than a 'brute force just get it done' approach. 

void Advent1_1()
{
	int frequency = 0;

	std::ifstream fileIn("data/input1.txt");
	std::string strLine;
	while (std::getline(fileIn, strLine))
	{
		frequency += std::stoi(strLine);
	}
	std::cout << "Advent 1 - Frequency Result = " << frequency << std::endl;
}


void Advent1_2()
{
	using namespace std;
	clock_t begin = clock();

	int frequency = 0;
	int frequencySeenTwice = 0;
	bool found = false;

	std::map<int, int> freqMap;

	while (!found)
	{
		std::ifstream fileIn("data/input1.txt");
		std::string strLine;
		while (std::getline(fileIn, strLine))
		{
			frequency += std::stoi(strLine);
			// If key doesn't exist yet, then we get a 0 anyway.
			int existing = freqMap[frequency];
			existing++;
			freqMap[frequency] = existing;
			if (freqMap[frequency] == 2)
			{
				found = true;
				frequencySeenTwice = frequency;
				break;
			}
		}
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "TOOK {" << elapsed_secs << "}Advent 1 part 2 - First Frequency reached twice = " << frequencySeenTwice << std::endl;

}

// Attempting to speed up 1_2 a little just playing around.
void Advent1_2_1()
{

	using namespace std;
	clock_t begin = clock();

	int frequency = 0;
	int frequencySeenTwice = 0;
	bool found = false;

	std::map<int, int> freqMap;

	// Read in the file once.
	std::vector<int> dataValues;
	std::ifstream fileIn("data/input1.txt");
	std::string strLine;

	// Let't not read from the file each time we're going through the main loop. 
	// Let's also just do the stoi call once so store the numbers in a vec.
	while (std::getline(fileIn, strLine))
	{
		dataValues.push_back(std::stoi(strLine));
	}

	while (!found)
	{
		for (auto i = 0u; i < dataValues.size(); i++)
		{
			frequency += dataValues[i];
			// If key doesn't exist yet, then we get a 0 anyway.
			int existing = freqMap[frequency];
			existing++;
			freqMap[frequency] = existing;
			if (freqMap[frequency] == 2)
			{
				found = true;
				frequencySeenTwice = frequency;
				break;
			}
		}
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "TOOK {" << elapsed_secs << "}Advent 1 part 2_1 - First Frequency reached twice = " << frequencySeenTwice << std::endl;
}