#include "console_tools.h"
#include "arr_tools.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

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
    constexpr int size{50};
    char line[size]{};

    int paper{0};
    int ribbon{0};

    while (file.getline(line, size))
    {
        // getting first value
        int left{0};
        int right{0};

        right = {Arr_tools::index_of_delimeter(line, right, 'x', size) - 1};

        int x{Arr_tools::convertSubarrayToInt(line, left, right)};

        // getting second value
        right += 2;
        left = {right};

        right = {Arr_tools::index_of_delimeter(line, right, 'x', size) - 1};

        int y{Arr_tools::convertSubarrayToInt(line, left, right)};

        // getting third value
        right += 2;
        left = {right};

        right = {Arr_tools::index_of_delimeter(line, right, '\0', size) - 1};

        int z{Arr_tools::convertSubarrayToInt(line, left, right)};

        // caluclating 2 smallest values
        int min1{std::min(std::min(x, y), z)};
        int min2{(x + y + z) - min1 - std::max(std::max(x, y), z)};

        // calculating paper
        paper += 2 * ((x * y) + (y * z) + (x * z));
        paper += min1 * min2;

        // calculating ribbon
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
