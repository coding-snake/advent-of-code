```cpp
#include <iostream>
#include <limits>
#include <ios>

#include <fstream>
#include <algorithm>

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

int convertSubarrayToInt(char arr[], int left, int right)
{
	int value{ 0 };

	for (; left <= right; ++left)
	{
		// we move all numbers 1 to left
		value *= 10;

		// we add converted int to the value
		value += static_cast<int>(arr[left] - '0');
	}

	return value;
}

int main()
{
	// opening file
	std::ifstream file;

	file.open("input_day_2.txt");
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

	int left{ 0 };
	int right{ 0 };

	while (file.getline(line, size))
	{
		left = { 0 };
		right = { 0 };

		for (; line[right] != 'x' && right < size; ++right) {}
		--right;

		int x{ convertSubarrayToInt(line, left, right) };

		// getting second value
		right += 2;
		left = { right };

		for (; line[right] != 'x' && right < size; ++right) {}
		--right;

		int y{ convertSubarrayToInt(line, left, right) };

		// getting third value
		right += 2;
		left = { right };

		for (; line[right] != '\0' && right < size; ++right) {}
		--right;

		int z{ convertSubarrayToInt(line, left, right) };


		// smallest, largest and medium value
		int min{ std::min(std::min(x, y), z) };
		int max{ std::max(std::max(x, y), z) };

		int medium{ (x + y + z) - min - max };

		// calculating paper
		paper += 2 * ((x * y) + (y * z) + (x * z));
		paper += min * medium;

		// calculating ribbon
		ribbon += (2 * min) + (2 * medium);
		ribbon += x * y * z;
	}

	// answer
	std::cout << "Total ammount of wrapping paper elf needs is equal to " << paper << " square feet\n";
	std::cout << "and the total ammoun of ribbon elf needs is equal to " << ribbon << " feet\n";

	// closing file
	file.close();

	wait_for_enter();
	return 0;
}
```