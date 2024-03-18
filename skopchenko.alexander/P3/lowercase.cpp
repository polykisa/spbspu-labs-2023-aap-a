#include "lowercase.h"
#include <cstring>

char *skopchenko::convertToLowerCase(char *string)
{
  char* result = new char[strlen(string) + 1];
  strcpy(result, string);
  for (int i = 0; result[i] != '\0'; ++i)
  {
    if (result[i] >= 'A' && result[i] <= 'Z')
    {
      result[i] = result[i] - 'A' + 'a';
    }
  }
  return result;
}
