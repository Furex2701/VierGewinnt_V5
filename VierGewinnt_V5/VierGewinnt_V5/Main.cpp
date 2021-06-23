#include <iostream>
#include <vector>

#include "Functions.h"

bool fourinarow = false;
int turns = 0;
std::vector<char> buffer{' '};
char winner;

int main()
{
	
	
	
	
	while (!fourinarow)
	{
		BuildArea();
		int userInput = GetInput();

	
			
		char mark = Char_pb(buffer);
		buffer.push_back(mark);
		while (true)
		{
			if (SetMark(userInput, mark) == true)
			{
			
				break;
			}
			else
			{
				userInput = GetInput();
			}

		}
		
		
		winner = FourinarowCheck();
		if (winner == 'x' || winner == 'o')
		{
			
			fourinarow = true;
		}

		turns = turns + 1;
	}
	
	BuildArea();
	std::cout << winner << " has won!" <<std::endl;
	
}