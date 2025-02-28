#include "print_mod/include/print.h"

#include <iostream>
#include <limits>
#include <random>

int get_check_user_chose();
int get_pc_chose();
char compare_choses(int user_chose, int pc_chose);
void clearInput();

std::mt19937 r_n{std::random_device{}()};

int main(int argc, char *argv[])
{
	std::cout << "Hello Player ! \nWelcome to rock paper scissors game !\nYou need to chose how many times we have to play.\n";
	int rounds{0};
	while (rounds <= 0 || rounds > 100)
	{
		std::cout << "Maximum round is \"100\", and it must be larger than \"0\".\n";
		std::cin >> rounds;
		if (std::cin.fail())
			clearInput();
	}

	std::cout << "Well ok we are going to play for \" " << rounds << "\" times, just remmember:\n\tRock => 1\n\tPaper => 2\n\tScissors => 3\n";

	// * 0 is point for pc, 1 is for user
	int points[rounds];
	for (int i = 0; i < rounds;)
	{
		int user_chose{get_check_user_chose()};
		int pc_chose{get_pc_chose()};
		char result{compare_choses(user_chose, pc_chose)};
		set_point(points, i, result);
	}

	congratulations(points, rounds);
}

int get_check_user_chose()
{
	int chose{0};
	std::cout << "Enter your chose:\n";
	std::cin >> chose;

	if (std::cin.fail() || chose <= 0 || chose > 3)
	{
		std::cout << "Seems like you enter an incorrect input, so try again.\n.";
		clearInput();
	}

	return chose;
}

int get_pc_chose()
{
	int chose = r_n() % 3 + 1;

	return chose;
}

char compare_choses(int user_chose, int pc_chose)
{
	if (user_chose == 1 && pc_chose == 3)
	{
		return '+';
	}
	else if (user_chose == 2 && pc_chose == 1)
	{
		return '+';
	}
	else if (user_chose == 3 && pc_chose == 2)
	{
		return '+';
	}
	else if (user_chose == pc_chose)
	{
		return '=';
	}
	return '-';
}

void clearInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
