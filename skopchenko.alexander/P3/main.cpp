#include "stringinput.h"
#include "excludeChars.h"


int main() {
  char *inputString = nullptr;
  char *additionalString = nullptr;

  try {
    inputString = skopchenko::stringInput(std::cin);
    additionalString = skopchenko::stringInput(std::cin);
  }
  catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  if (inputString[0] == '\0') {
    delete[] inputString;
    delete[] additionalString;
    std::cerr << "Empty input!\n";
    return 1;
  }

  char *result = new char[1000];

  skopchenko::excludeCharacters(inputString, additionalString, result);
  std::cout << result << '\n';

  delete[] inputString;
  delete[] additionalString;
  delete[] result;

}
