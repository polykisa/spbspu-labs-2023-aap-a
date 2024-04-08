#include "scaling.hpp"
#include <stdexcept>

void scale(Shape* shape, point_t point, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("k shouldn't be under 0");
  }
  point_t pos{ shape->getFrameRectangle().pos.x, shape->getFrameRectangle().pos.y};
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  shape->move(dx, dy);
  dx = -dx * k;
  dy = -dy * k;
  shape->scale(k);
  shape->move(dx, dy);
}