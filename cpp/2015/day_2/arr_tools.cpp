#include "arr_tools.h"

namespace Arr_tools
{
	int index_of_delimeter(char arr[], int start, char key, int size)
	{
		int i{};
		for (i = { start }; arr[i] != key && i < size; ++i){}
		return i;
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
}