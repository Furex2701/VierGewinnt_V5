#include <iostream>
#include "Functions.h"
#include <vector>

using namespace std;
		//    y  x  
char fieldArr[7][7] = { {' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
					    {' ', ' ', ' ', ' ', ' ', ' ', ' ' },
					    {' ', ' ', ' ', ' ', ' ', ' ', ' ' },
					    {' ', ' ', ' ', ' ', ' ', ' ', ' ' },
					    {' ', ' ', ' ', ' ', ' ', ' ', ' ' },
					    {' ', ' ', ' ', ' ', ' ', ' ', ' ' },
					    {' ', ' ', ' ', ' ', ' ', ' ', ' ' } };

void BuildArea()
{
	cout << "   " << "1" << " " << " " << "2" << " " << " " << "3" << " " << " " << "4" << " " << " " << "5" << " " << " " << "6" << " " << " " << "7" << " " << endl;

	for (int i = 1; i < 7; i++)
	{
		cout << "  ";
		for (int a = 0; a < 7; a++)
		{
			cout << '(' << fieldArr[i][a] << ')';
		}
		cout << endl;
	}
	cout << "_________________________" << endl;
	
}




int GetInput()
{
	int input;
	cin >> input;
	
	if (input < 1 || input > 7)
	{
		bool again = true;
		cout << "invalid input" << endl;
		while (true)
		{
			cin >> input;
			if (input < 1 || input > 7)
			{
				cout << "invalid input" << endl;
				return input;
			}
			else 
			{
				break;
				
			}
		}
	}
	
	return input;
}


char Char_pb(vector<char> vector)
{

		
	int size = vector.size();
	
		if (vector[size - 1] == 'x')
		{
			
			return 'o';
		}
		else if(vector[size - 1] == 'o' || vector[size - 1] == ' ')
		{
			
			return 'x';
		}
		return 0;
}

int Height(int p)
{

	int height = 6;
	if (fieldArr[height][p] != ' ')
	{
		height = 5;
		if (fieldArr[height][p] != ' ')
		{
			height = 4;
			if (fieldArr[height][p] != ' ')
			{
				height = 3;
				if (fieldArr[height][p] != ' ')
				{
					height = 2;
					if (fieldArr[height][p] != ' ')
					{
						height = 1;
						if (fieldArr[height][p] != ' ')
						{
							height = 0;
							if (height == 0)
							{
								cout << "split is filled completely already" << endl;
							}
						}
					}
				}
			}
		}
	}
	return height;
}

bool SetMark(int input, char k)
{

	if (Height(input - 1) != 0)
	{
		fieldArr[Height(input - 1)][input -1] = k;
	
		return true;
	}
	else
	{
		BuildArea();
		cout << "Please enter another number" << endl;
		
		return false;
	}
	
}

char FourinarowCheck()
{
	
	for (int first = 6; first >= 1; first--)
	{


		for (int second = 0; second < 7; second++)
		{
			if (second + 3 < 7)
			{
				if (fieldArr[first][second] == 'x' && fieldArr[first][second + 1] == 'x' && fieldArr[first][second + 2] == 'x' && fieldArr[first][second + 3] == 'x')
				{
					return 'x';
				}
				else if (fieldArr[first][second] == 'o' && fieldArr[first][second + 1] == 'o' && fieldArr[first][second + 2] == 'o' && fieldArr[first][second + 3] == 'o')
				{
					return 'o';
				}
			}
			else 
			{
				break;
			}
		}
	}
	
	
	for (int second = 0; second < 7; second++)
	{


		for (int first = 6; first > 0; first--)
		{
		
				if (fieldArr[first][second] == 'x' && fieldArr[first + 1][second] == 'x' && fieldArr[first + 2][second] == 'x' && fieldArr[first + 3][second] == 'x')
				{
					return 'x';
				}
				else if (fieldArr[first][second] == 'o' && fieldArr[first + 1][second] == 'o' && fieldArr[first + 2][second] == 'o' && fieldArr[first + 3][second] == 'o')
				{
					return 'o';
				}
			
		}
	}



	for (int first = 6; first > 1; first--)
	{


		for (int second = 0; second < 7; second++)
		{
			
				if (fieldArr[first][second] == 'x' && fieldArr[first + 1][second + 1] == 'x' && fieldArr[first + 2][second + 2] == 'x' && fieldArr[first + 3][second + 3] == 'x')
				{
					return 'x';
				}
				else if (fieldArr[first][second] == 'x' && fieldArr[first + 1][second - 1] == 'x' && fieldArr[first + 2][second - 2] == 'x' && fieldArr[first + 3][second - 3] == 'x')
				{
					return 'x';
				}

				else if (fieldArr[first][second] == 'o' && fieldArr[first + 1][second + 1] == 'o' && fieldArr[first + 2][second + 2] == 'o' && fieldArr[first + 3][second + 3] == 'o')
				{
					return 'o';
				}
				else if (fieldArr[first][second] == 'o' && fieldArr[first + 1][second - 1] == 'o' && fieldArr[first + 2][second - 2] == 'o' && fieldArr[first + 3][second - 3] == 'o')
				{
					return 'o';
				}
		}
	}
	return 0;
}
