#include "stringinput.h"

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
    std::cerr << "Bad input\n";
    return 1;
  }

  delete [] inputString;
  delete [] additionalString;

}
