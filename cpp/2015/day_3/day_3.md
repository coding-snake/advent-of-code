### Day 3, 2015

## Part 1/2
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

template <typename T, typename U>
T** allocate_memory_of_2d_array(U rows, U cols) {
	// Allocate memory for the array of pointers 
	T** arr = new T * [rows];

	// Each pointer points to array of values
	for (U i = 0; i < rows; ++i) {
		arr[i] = new T[cols];
	}

	return arr;
}

template <typename T, typename U>
void deallocate_memory_of_2d_array(T** arr, U size)
{
	// delete arrays pointed by each pointer
	for (U i{ 0 }; i < size; ++i)
	{
		delete[] arr[i];
	}

	// delete array of pointers
	delete[] arr;
}

template <typename T, typename U>
void fill_2d_array_with_value(T** arr, U rows, U cols, T value)
{
	for (U i{ 0 }; i < rows; ++i)
	{
		for (U j{ 0 }; j < cols; ++j)
		{
			arr[i][j] = { value };
		}
	}
}


int main()
{
	// size for array
	constexpr int size{ 10000 };

	std::ifstream file;
	file.open("input_day_3.txt");

	if (!file.is_open())
	{
		std::cerr << "Failed to open input file\n";
		return 1;
	}


	int** grid = allocate_memory_of_2d_array<int>(size, size);

	fill_2d_array_with_value(grid, size, size, 0);


	char* line = new char[size];
	file.getline(line, size);

	// we set coords in the middle of grid
	int x{ size / 2 };
	int y{ size / 2 };

	// Santa starts from a house where he delivered first present
	++grid[x][y];
	for (int i{ 0 }; line[i] != '\0'; ++i)
	{
		switch (line[i])
		{
		case '^':
			++y;
			break;
		case '>':
			++x;
			break;
		case 'v':
			--y;
			break;
		case '<':
			--x;
			break;
		default: break;
		}
		++grid[x][y];
	}

	delete[] line;

	int houses{ 0 };

	for (int i{ 0 }; i < size; ++i)
	{
		for (int j{ 0 }; j < size; ++j)
		{
			if (grid[i][j] > 0)
			{
				++houses;
			}
		}
	}

	deallocate_memory_of_2d_array(grid, size);

	std::cout << "The number of houses that received at least one present ammounts to " << houses << '\n';
	file.close();


	wait_for_enter();
	return 0;
}
```

## Part 2/2

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

template <typename T, typename U>
T** allocate_memory_of_2d_array(U rows, U cols) {
	// Allocate memory for the array of pointers 
	T** arr = new T * [rows];

	// Each pointer points to array of values
	for (U i = 0; i < rows; ++i) {
		arr[i] = new T[cols];
	}

	return arr;
}

template <typename T, typename U>
void deallocate_memory_of_2d_array(T** arr, U size)
{
	// delete arrays pointed by each pointer
	for (U i{ 0 }; i < size; ++i)
	{
		delete[] arr[i];
	}

	// delete array of pointers
	delete[] arr;
}

template <typename T, typename U>
void fill_2d_array_with_value(T** arr, U rows, U cols, T value)
{
	for (U i{ 0 }; i < rows; ++i)
	{
		for (U j{ 0 }; j < cols; ++j)
		{
			arr[i][j] = { value };
		}
	}
}


int main()
{
	// size for array
	constexpr int size{ 10000 };

	std::ifstream file;
	file.open("input_day_3.txt");

	if (!file.is_open())
	{
		std::cerr << "Failed to open input file\n";
		return 1;
	}


	int** grid = allocate_memory_of_2d_array<int>(size, size);

	fill_2d_array_with_value(grid, size, size, 0);


	char* line = new char[size];
	file.getline(line, size);

	// we set coords in the middle of grid for Santa
	int x{ size / 2 };
	int y{ size / 2 };

	// we set coords in the middle of grid for RoboSanta
	int rx{ size / 2 };
	int ry{ size / 2 };

	// is it Robo-Santa turn ?
	bool roboSanta{ false };

	// Santa's start from a house where they delivered first present
	grid[x][y] += 2;
	for (int i{ 0 }; line[i] != '\0'; ++i)
	{
		if (!roboSanta)
		{
			switch (line[i])
			{
			case '^':
				++y;
				break;
			case '>':
				++x;
				break;
			case 'v':
				--y;
				break;
			case '<':
				--x;
				break;
			}
			++grid[x][y];
			roboSanta = { true };
		}
		else
		{
			switch (line[i])
			{
			case '^':
				++ry;
				break;
			case '>':
				++rx;
				break;
			case 'v':
				--ry;
				break;
			case '<':
				--rx;
				break;
			}
			++grid[rx][ry];
			roboSanta = { false };
		}

	}

	delete[] line;

	int houses{ 0 };

	for (int i{ 0 }; i < size; ++i)
	{
		for (int j{ 0 }; j < size; ++j)
		{
			if (grid[i][j] > 0)
			{
				++houses;
			}
		}
	}

	deallocate_memory_of_2d_array(grid, size);

	std::cout << "The number of houses that received at least one present ammounts to " << houses << '\n';
	file.close();



	wait_for_enter();
	return 0;
}
```
