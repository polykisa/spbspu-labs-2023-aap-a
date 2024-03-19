#include "lowercase.h"
#include <cstring>

char *skopchenko::convertToLowerCase(char *string)
{
  for (size_t i = 0; string[i] != 0; i++)
  {
    if (string[i] >= 'A' && string[i] <= 'Z')
    {
      string[i] += 32;
    }
  }
  return string;
}
