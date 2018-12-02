#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>

//Day 2 Part 1 Result = 7904
//Day 2 Part 1 TOOK{ 0.074 }
//Day 2 Part 2 Result = wugbihckpoymcpaxefotvdzns
//Day 2 Part 2 TOOK{ 8.51 }
//Day 2 Part 2_1 Result = wugbihckpoymcpaxefotvdzns
//Day 2 Part 2_1 TOOK{ 0.109 }

void Day2Part1()
{
	std::ifstream file("data/input2.txt");
	std::string strLine;

	int twoCount = 0;
	int threeCount = 0;

	std::map<char, int> tmpMap;
	while (std::getline(file, strLine))
	{
		tmpMap.clear();
		bool twos = false, threes = false;

		// Increase the characters 'count' everytime 
		// it is used.
		for (char& c : strLine)
		{			
			tmpMap[c] = ++tmpMap[c];
		}

		for (auto const&[key, val] : tmpMap)
		{
			if (val == 2) twos = true;
			else  if (val == 3) threes = true;
		}

		if (twos) twoCount++;
		if (threes) threeCount++;
	}

	int result = twoCount * threeCount;

	std::cout << "Day 2 Part 1 Result = " << result << std::endl;
}

// I make use of the Levenshtein distance algorithm for computing difference between two strings.
// please note I followed wikipedia page https://en.wikipedia.org/wiki/Levenshtein_distance and then 
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C++ 
// because I do not know the algorithm off by heart :P
int LevenshteinDistance(const std::string &s1, const std::string &s2)
{
	// To change the type this function manipulates and returns, change
	// the return type and the types of the two variables below.
	int s1len = s1.size();
	int s2len = s2.size();

	auto column_start = (decltype(s1len))1;

	auto column = new decltype(s1len)[s1len + 1];
	std::iota(column + column_start - 1, column + s1len + 1, column_start - 1);

	for (auto x = column_start; x <= s2len; x++) {
		column[0] = x;
		auto last_diagonal = x - column_start;
		for (auto y = column_start; y <= s1len; y++) {
			auto old_diagonal = column[y];
			auto possibilities = {
				column[y] + 1,
				column[y - 1] + 1,
				last_diagonal + (s1[y - 1] == s2[x - 1] ? 0 : 1)
			};
			column[y] = std::min(possibilities);
			last_diagonal = old_diagonal;
		}
	}
	auto result = column[s1len];
	delete[] column;
	return result;
}

void Day2Part2()
{
	std::ifstream file("data/input2.txt");
	std::string strLine;
	std::vector<std::string> lines;
	
	while (std::getline(file, strLine))
	{
		lines.push_back(strLine);
	}

	int indexOfBestMatching1 = -1;
	int indexOfBestMatching2 = -1;
	int valueOfBestMatching = std::numeric_limits<int>::max();

	for (unsigned int i = 0; i < lines.size() / 2; i++)
	{
		std::string str1 = lines[i];
		for (unsigned int j = i + 1; j < lines.size(); j++)
		{
			int distance = LevenshteinDistance(str1, lines[j]);
			// Special case if 0 then it's matching!
			if (distance == 0)
			{
				std::cout << "Found Precise match: " << lines[i];
				return;
			}
			else if (distance < valueOfBestMatching)
			{
				indexOfBestMatching1 = i;
				indexOfBestMatching2 = j;
				valueOfBestMatching = distance;
			}
		}
	}

	std::stringstream strStream;
	std::string matching1 = lines[indexOfBestMatching1];
	std::string matching2 = lines[indexOfBestMatching2];
	for (unsigned int i = 0; i < matching1.length(); i++)
	{
		if (matching1[i] == matching2[i])
		{
			strStream << matching1[i];
		}
	}

	std::cout << "Day 2 Part 2 Result = " << strStream.str() << std::endl;
}

// Overcomplicated my initial attempt to get it done. 
// Rather than taking 8 seconds, this way (cleaner as well) takes less than 0.11secs
// Just use the power of sets out of the box.

void Day2Part2_1()
{
	std::ifstream file("data/input2.txt");

	std::vector<std::string> items;

	std::copy(std::istream_iterator<std::string>(file),
		std::istream_iterator<std::string>(),
		std::back_inserter(items));

	// Ordering isn't important, so use an unordered_set just to save a wee bit of time. 
	std::vector<std::unordered_set<std::string>> substrings(items.size());

	for (const auto& item : items)
	{
		for (unsigned int i = 0; i < item.size(); ++i)
		{
			// We want to go through each subset of character possibilities 
			// in an item from the data set. 
			std::string subStr = item.substr(0, i) + item.substr(i + 1);
			
			// If we were unable to store it! That means we've found a match as we've inserted
			// this set of characters before.
			if (!substrings[i].insert(subStr).second)
			{
				std::cout << "Day 2 Part 2_1 Result = " << subStr << std::endl;  

				return;
			}
		}
	}
}
