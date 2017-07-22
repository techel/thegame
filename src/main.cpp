#include "app.hpp"

#include <stdexcept>
#include <iostream>

int main()
{
	try
	{
		App();
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what();
		std::cin.get();
	}
}