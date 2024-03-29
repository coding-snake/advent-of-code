#include "math_tools.h"

namespace Math_tools
{

	int min_value(int a, int b)
	{
		if (a <= b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}

	int min_value(int a, int b, int c)
	{
		if (a <= b && a <= c)
		{
			return a;
		}
		else if (b <= c)
		{
			return b;
		}
		else
		{
			return c;
		}
	}

	int cuboid_surface(int x, int y, int z)
	{
		return 2 * ((x * y) + (y * z) + (x * z));
	}
}