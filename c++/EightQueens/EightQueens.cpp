#include <iostream>
#include <stdlib.h>

void CreateGameboard();
void DeleteGameboard();
void Print();
void Clear();

bool canPlace(int x, int y);
bool ProcessTurn(int N);

char** gameboard;
int N = 8;
int Q1 = 0;

int main()
{
	CreateGameboard();
	// Calls function to check if reclusive solution exists
	if (!ProcessTurn(0))                                   
	{
		std::cout << "\nA solution does not exist" << std::endl;
	}
	Clear();
	
	DeleteGameboard();
	
	std::cin.get();
	return 0;
}

void CreateGameboard() 
{
	gameboard = new char*[N];
	for (int i = 0; i < N; i++)
	{
		gameboard[i] = new char[N];
	}
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			gameboard[x][y] = '-';
		}
	}
}
void DeleteGameboard()
{
	for (int i = 0; i < N; i++)
	{
		delete[] gameboard[i];
	}
	delete gameboard;
}
void Print()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
			std::cout << gameboard[x][y] << "   ";
		std::cout << std::endl;
	}
}
bool canPlace(int x, int y) {

	for (int b = 0; b < N; b++) {
		for (int a = 0; a < N; a++) {
			if (gameboard[a][b] == 'Q')
			{
				if (abs(a) - abs(x) == 0 || abs(b) - abs(y) == 0 || float(abs(b - y)) / float(abs(a - x)) == 1)
				{
					return false; 
				}
			}
		}
	}
	return true;
}
bool ProcessTurn(int y) 
{
	if (y + 1 > N)
	{
		Print();
		if (Q1 + 1 != N)
		{
			Clear();
			Q1++;
			gameboard[Q1][0] = 'Q';
			ProcessTurn(1);
		}
		return true;
	}
	// Run throught the rows
	for (int x = 0; x < N; x++) 
	{

		// Checks if can place queen
		if (canPlace(x, y))
		{
			// Place queen in spot
			gameboard[x][y] = 'Q';

			// Check if the queen queen can be placed in the next column
			if (ProcessTurn(y + 1))
			{
				return true;
			}
			// Otherwise mark with an R to represent a retired spot
			gameboard[x][y] = '-';
		}
		// Move to next row and place queen 
	}
	return false;
}
void Clear()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			gameboard[x][y] = '-';
		}
	}
	std::cout << std::endl;
	//Print();
}
