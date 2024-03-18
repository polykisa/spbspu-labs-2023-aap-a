#include "stringinput.h"
#include "excludeChars.h"
#include "lowercase.h"


int main()
{
  char *inputString = nullptr;
  char *additionalString = nullptr;

  try
  {
    inputString = skopchenko::stringInput(std::cin);
    additionalString = skopchenko::stringInput(std::cin);
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  if (inputString[0] == '\0')
  {
    delete[] inputString;
    delete[] additionalString;
    std::cerr << "Empty input!\n";
    return 1;
  }

  char *excludedChars = new char[1000];
  char *lowercase = nullptr;

  excludedChars = skopchenko::excludeCharacters(inputString, additionalString, excludedChars);
  lowercase = skopchenko::convertToLowerCase(inputString);
  std::cout << excludedChars << '\n';
  std::cout << lowercase << '\n';

  delete[] inputString;
  delete[] additionalString;
  delete[] excludedChars;
  delete[] lowercase;

}
