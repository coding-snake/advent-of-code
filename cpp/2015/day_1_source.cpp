#include "console_tools.h"

#include <iostream>
#include <fstream>


int main()
{
	std::ifstream file;

	file.open("day_1_input.txt");
	if (!file.is_open())
	{
		std::cerr << "Failed to open a file\n";
		return 1;
	}

	constexpr int size{ 10000 };

	char line[size]{};
	file.getline(line, size);

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
	file.close();

	char key{};

	Console_tools::wait_for_enter();

	return 0;
}
