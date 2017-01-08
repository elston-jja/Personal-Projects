#include <iostream>

int players;

int main()
{
	while(1)
	{
		std::cout << "Players: ";
		std::cin >> players;
		std::cout << "The number of players are: " << players << std::endl;

		if (players > 99)
		{
			std::cout << "Err Number out of range\n";
			exit(0);
		}
		else if(players < 4)
		{
			std::cout << "0\n";
			exit(0);
		}
	}
	return 0;
}
