#include <iostream>
#include <cstdlib>
#include <ctime>

int get_check_user_chose();
int get_pc_chose();
char compare_choses(int user_chose, int pc_chose);
void set_point(int points[], int &currentIndex, char result);
void congratulations(int points[], int rounds);

int main(int argc, char *argv[])
{
  std::cout << "Hello Player ! \nWelcome to rock paper scissors game !\nYou need to chose how many times we have to play.\n";
  int rounds{0};
  while (rounds <= 0 || rounds > 100)
  {
    std::cout << "Maximum round is \"100\", and it must be larger than \"0\".\n";
    std::cin >> rounds;
    if (std::cin.fail())
    {
      std::cerr << "Seems like you enter an incorrect input, so proccess terminated.";
      exit(1);
    }
  }

  std::cout << "Well ok we are going to play for \" " << rounds << "\" times, just remmember:\n\tRock => 1\n\tPaper => 2\n\tScissors => 3\n";

  // * 0 is point for pc 1 is for user
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
    std::cerr << "Seems like you enter an incorrect input, so proccess terminated.";
    exit(1);
  }

  return chose;
}

int get_pc_chose()
{
  std::srand(std::time(0));
  // formula => rand() % (max - min + 1) + min
  int chose = std::rand() % ((3 - 1) + 1) + 1;

  return chose;
}

void set_point(int points[], int &currentIndex, char result)
{
  if (result == '+')
  {
    points[currentIndex] = 1;
    std::cout << "You won this round !\n";
    currentIndex++;
  }
  else if (result == '-')
  {
    points[currentIndex] = 0;
    std::cout << "You losed this round !\n";
    currentIndex++;
  }
  else
  {
    std::cout << "No clear winner.\n";
  }
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

void congratulations(int points[], int rounds)
{
  int user_wins{0};
  for (size_t i = 0; i < rounds; i++)
  {
    if (points[i] == 1)
    {
      user_wins++;
    }
  }

  std::cout << "User get \" " << user_wins << "\" points.\nI get \" " << rounds - user_wins << " \" points.";
}
