#include "utilities.h"

#include <iostream>
#include <limits>
#include <ios>

namespace Console
{
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
}