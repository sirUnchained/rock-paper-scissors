#include <iostream>

int main(int argc, char *argv[])
{
  std::cout << "Hello Player ! \nWelcome to rock paper scissors game !\nYou need to chose how many times we have to play.\n";
  int rounds{0};
  while (rounds <= 0 || rounds > 100)
  {
    std::cout << "Maximum round is \"100\", and it must be larger than \"0\".\n";
    std::cin >> rounds;
  }

  std::cout << "Well ok we are going to play for " << "\"" << rounds << "\" times, just remmember:\n\tRock => 1\n\tPaper => 2\n\tscissors => 3\n";
}
