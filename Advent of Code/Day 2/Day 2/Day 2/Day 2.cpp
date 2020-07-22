// Day 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <algorithm>
#include <numeric>

void get_modules(std::vector<int>& code_list)
{
	std::ifstream f("Oppcode.txt");
	std::string temp = "";

	if (f.is_open())
	{
		while (std::getline(f, temp, ','))
		{
			temp.erase(std::remove(temp.begin(), temp.end(), ','), temp.end());
			//std::cout << temp << " saved to vector";
			const int& value = std::stoi(temp);
			code_list.push_back(value);
		}

		f.close();

	}

}

void calculate_list(std::vector<int> code_list, int input, bool& solution_found)
{

	for (int i = 0; i <= code_list.size(); i += 4) //switch over for for efficiency
	{
		int noun = code_list[code_list[i + 1]];
		int verb = code_list[code_list[i + 2]];
		if (code_list[i] == 1)
		{
			code_list[code_list[i + 3]] = noun + verb;
		}

		else if (code_list[i] == 2)
		{
			code_list[code_list[i + 3]] = noun * verb;
		}

		else if (code_list[i] == 99)
		{
			break;
		}

	}

	if (code_list[0] == input)
	{
		solution_found = true;
	}

}



int main()
{
	int input = 19690720;
	bool solution_found = false;
	std::vector<int> code_list;

	get_modules(code_list);

	//code_list[1] = 12;
	//code_list[2] = 4;

	for (int i = 1; i <= 99; ++i)
	{
		code_list[1] = i;

		for (int j = 1; j <= 99; ++j)
		{
			code_list[2] = j;
			calculate_list(code_list, input, solution_found);

			if (solution_found) 
			{
				break;
			}
		}

		if (solution_found)
		{
			break;
		}
	}

	const int result = 100 * code_list[1] + code_list[2];
	
	std::cout << "First record is: " << result << std::endl;

}

//Intcode program
// 99 ends the program, 1 means to add together two numbers from two positions and stores them in the third..
//The three integers immediately after the opcode tell you these three positions.
// the first two indicate the positions from which you should read the input values, and the third indicates the position at which the output should be stored.
//Opcode 2 works exactly like opcode 1, except it multiplies the two inputs instead of adding them.
//Once you're done processing an opcode, move to the next one by stepping forward 4 positions.