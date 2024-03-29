#include "utilities.h"
#include <iostream>
#include <fstream>

int main()
{
	constexpr int size{ 10'000 };

	std::ifstream input;

	input.open("day_1_input.txt");
	if (!input.is_open())
	{
		std::cerr << "Faile to open a file\n";
		return 1;
	}

	char line[size]{};
	input.getline(line, size);

	int level{ 0 };
	int basement{ -1 };

	for (int i{ 0 }; line[i] != '\0'; ++i)
	{
		if (line[i] == '(')
		{
			++level;
		}
		else
		{
			--level;
		}

		if ((basement == -1) && (level == basement))
		{
			basement = { i + 1 };
		}
	}

	std::cout << "Correct floor was on level " << level << ", Santa entered basement at character position " << basement << '\n';
	input.close();


	Console::wait_for_enter();

	return 0;
}
