### Day 1, 2015
```cpp
#include <iostream>
#include <limits>
#include <ios>

#include <fstream>

void wait_for_enter()
{
	char key{};

	do
	{
		std::cout << "Press enter to end program...\n";

		std::cin.get(key);

		if (key != '\n')
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	} while (key != '\n');

}

int main()
{
	// opening file
	std::ifstream file;

	file.open("input_day_1.txt");
	if (!file.is_open())
	{
		std::cerr << "Failed to open a file\n";
		return 1;
	}


	// core loop
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

	// answer
	std::cout << "Correct floor was on level " << level << ", Santa entered basement at character position " << basement << '\n';

	// closing file
	file.close();

	wait_for_enter();
	return 0;
}
```