#include "rectangle.hpp"
#include <stdexcept>

skopchenko::Rectangle::Rectangle(const point_t &left_down, const point_t &right_up):
  rectangle _{right_up.x - left_down.x, right_up.y - left_down.y, {(left_down.x + right_up.x)/2, (left_down.y + right_up.y)/2}}
{
  if (left_down.x >= right_up || left_down.y >= right_up.y)
  {
    throw std::invalid_argument();
  }
}