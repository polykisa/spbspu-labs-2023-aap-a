#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "scaling.hpp"

int main()
{
  std::string shape = "";
  point_t point{};
  double k = 1;
  Shape* shape1 = nullptr;
  try
  {
    std::cin >> shape;
    if (shape == "RECTANGLE")
    {
      double args[4]{};
      std::cin >> args[0] >> args[1] >> args[2] >> args[3];
      shape1 = new Rectangle({args[0], args[1]}, {args[2], args[3]});
    }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << "\n";
  }
  scale(shape1, point, k);
}
