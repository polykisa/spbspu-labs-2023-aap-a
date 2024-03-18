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
}
