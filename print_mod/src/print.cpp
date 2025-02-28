#include "include/print.h"
#include <iostream>

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