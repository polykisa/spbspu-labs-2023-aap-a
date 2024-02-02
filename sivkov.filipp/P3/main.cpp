#include "inputString.hpp"
#include "removing_spaces.hpp"
#include "copyNum.hpp"

#include <iostream>
#include <exception>

int main()
{
  using namespace sivkov;
  char* string1 = nullptr;
  char* string2 = nullptr;
  char* inputString = nullptr;
  char inputString2[13] = {"h3ll0 w0r1d!"};
  try
  {
    inputString = addString(std::cin);
    string1 = deleteSpace(inputString);
    string2 = copyNum(inputString, inputString2);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation failed: " << e.what() << '\n';
    return 1;
  }
  catch (...)
  {    
    std::cerr << "line error\n";  
    if (inputString != nullptr)
    {
      delete[] inputString;
    }
    if (string1 != nullptr)
    {
      delete[] string1;
    }
    if (string2 != nullptr)
    {
      delete[] string2;
    }
    return 1;
  }
  std::cout << "\n[SPC-RMV]: " << string1 << '\n';
  std::cout << "[DGT-SND]: " << string2 << '\n';
  
  delete[] inputString;
  delete[] string1;
  delete[] string2;
  return 0;
}
