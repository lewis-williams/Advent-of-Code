// Advent of Code Day 1 Part 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <algorithm>
#include <numeric>

void get_modules(std::vector<int>& module_list)
{ 
    std::ifstream f("Module Input.txt");
    std::string temp = "";
    
    if (f.is_open())
    {
        while(std::getline(f, temp))
        {
            //std::cout << temp << " saved to vector";
            const int& value = std::stoi(temp);
            module_list.push_back(value);
        }

        f.close();

    }

}

void additional_fuel(int& fuel_rounded) //PART 2
{
    std::vector<int> sep_fuel_list;
    int current_fuel = fuel_rounded;

    while (std::floor(current_fuel / 3) - 2 > 0)
    {
        sep_fuel_list.push_back(current_fuel);
        current_fuel = std::floor(current_fuel / 3) - 2;
    }

    sep_fuel_list.push_back(current_fuel);

    fuel_rounded = std::accumulate(sep_fuel_list.begin(), sep_fuel_list.end(), 0);

}

void sort_fuel (const std::vector<int> module_list, int& fuel_overall) //PART 1
{
    
    for (const auto module : module_list)
    {
        int total_fuel = std::floor(module / 3) - 2;
        if( std::floor(total_fuel / 3) - 2 > 0 )
        {
            additional_fuel(total_fuel);
        }

        fuel_overall += total_fuel;
    }

    
}



int main()
{
    std::vector<int> module_list;
    get_modules(module_list);
    int fuel_overall = 0;
    sort_fuel(module_list, fuel_overall);

    std::cout << "fuel required: " << fuel_overall << std::endl;

  }


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
