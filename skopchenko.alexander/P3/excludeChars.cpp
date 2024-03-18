#include "excludeChars.h"
#include <iostream>

void skopchenko::excludeCharacters(char *str1, char *str2)
{
  int asciiMap[256] = {0};

  while (*str2 != '\0')
  {
    asciiMap[(int)*str2] = 1;
    str2++;
  }

  char *result = new char[10000];

  int i = 0;
  while (*str1 != '\0')
  {
    if (asciiMap[(int)*str1] == 0) {
      result[i] = *str1;
      i++;
    }
    str1++;
  }
  result[i] = '\0';
  std::cout << result << '\n';
  delete[] result;
}
