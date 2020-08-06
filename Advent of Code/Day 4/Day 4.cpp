// Day 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>  

#define RANGE_START (402328);
#define RANGE_END (864247);
#define SIZE_OF_PASSWORD (6);

//It is a six - digit number.
//The value is within the range given in your puzzle input.
//Two adjacent digits are the same( like 22 in 122345 ).
//Going from left to right, the digits never decrease; they only ever increase or stay the same( like 111123 or 135679 ).


int part_1_loop()
{
	const int range_start = RANGE_START;
	const int range_end = RANGE_END;
	const int pasword_size = SIZE_OF_PASSWORD;
	int possible_passwords = 0;

	for ( int i = range_start; i <= range_end; ++i )
	{
		bool is_legal = true;
		bool dupe_include = false;
		std::string temp = std::to_string( i );
		int last_char = 0;
		int left_char = 0;

		for ( char c : temp )
		{
			int first = 0;
			int second = last_char;
			int third = left_char;

			first = c - '0';

			if ( first == second )
			{
				dupe_include = true;
			}


			if ( first < second )
			{
				is_legal = false;
				break;
			}

			left_char = last_char;
			last_char = first;
		}

		if ( is_legal && dupe_include )
		{
			possible_passwords += 1;
		}


	}

	return possible_passwords;
}


int part_2_loop()
{
	const int range_start = RANGE_START;
	const int range_end = RANGE_END;
	const int pasword_size = SIZE_OF_PASSWORD;
	int possible_passwords = 0;

	for ( int i = range_start; i <= range_end; ++i )
	{
		bool is_legal = true;
		bool dupe_include = false;
		std::string temp = std::to_string( i );
		int last_char = 0;
		int left_char = 0;
		int streak = 0, duplicates = 0;
		bool in_streak = false;

		for ( char c : temp )
		{
			int first = 0;
			int second = last_char;
			int third = left_char;

			first = c - '0'; 
			
			if ( first < second )
			{
				is_legal = false;
				break;
			}

			if ( first == second )
			{

				if ( !in_streak )
				{
					in_streak = true;
					streak++;
					duplicates++;
				}

				else
				{
					streak++;
					duplicates = 0;
					
				}

			}

			else
			{
				in_streak = false;

				if( streak == 1 )
				{
					dupe_include = true;	
				}

				streak = 0;
			}


			left_char = last_char;
			last_char = first;
		}

		if( duplicates > 0 )
		{
			dupe_include = true;
		}

		if ( is_legal && dupe_include )
		{
			possible_passwords++;
		}


	}

	return possible_passwords;

}



int main()
{

    std::cout << "Number of combinations: " << part_1_loop() << std::endl; 
    std::cout << "Number of combinations: " << part_2_loop() << std::endl; 
	
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
