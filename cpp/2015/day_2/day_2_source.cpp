#include "console_tools.h"
#include "arr_tools.h"
#include "Math_tools.h"
#include <iostream>
#include <fstream>


int main()
{
	// opening file
	std::ifstream file;

	file.open("day_2_input.txt");
	if (!file.is_open())
	{
		std::cerr << "Failed to open a file\n";
		return 1;
	}


	// core loop
	constexpr int size{ 50 };
	char line[size]{};

	int paper{ 0 };
	int ribbon{ 0 };

	while (file.getline(line, size))
	{
		int left{ 0 };
		int right{ 0 };

		// search for index of delimeter and setting up value

		right = { Arr_tools::index_of_delimeter(line, right, 'x', size) - 1 };

		int x{ Arr_tools::convertSubarrayToInt(line, left, right) };

		// adjustment
		right += 2;
		left = { right };

		// search for index of delimeter and setting up value

		right = { Arr_tools::index_of_delimeter(line, right, 'x', size) - 1 };

		int y{ Arr_tools::convertSubarrayToInt(line, left, right) };

		// adjustment
		right += 2;
		left = { right };

		// search for index of delimeter and setting up value

		right = { Arr_tools::index_of_delimeter(line, right, '\0', size) - 1 };

		int z{ Arr_tools::convertSubarrayToInt(line, left, right) };

		int min1{ Math_tools::min_value(x, y, z) };
		int min2{};
		if (min1 == x)
		{
			min2 = { Math_tools::min_value(y, z) };
		}
		else if (min1 == y)
		{
			min2 = { Math_tools::min_value(x, z) };
		}
		else
		{
			min2 = { Math_tools::min_value(x, y) };
		}

		paper += Math_tools::cuboid_surface(x, y, z);
		paper += min1 * min2;

		ribbon += (2 * min1) + (2 * min2);
		ribbon += x * y * z;
	}


	// answer
	std::cout << "Total ammount of wrapping paper elf needs is equal to " << paper << " square feet\n";
	std::cout << "and the total ammoun of ribbon elf needs is equal to " << ribbon << " feet\n";

	// closing file
	file.close();

	Console_tools::wait_for_enter();

	return 0;
}
