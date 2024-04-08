#include "functions.hpp"

point_t suppFunctions::findSummVector(point_t point, double dx, double dy)
{
  point.x += dx;
  point.y += dy;
  return point;
}

point_t suppFunctions::findDifference(point_t position, point_t rect)
{
  return {position.x - rect.x, position.y - rect.y};
}

point_t suppFunctions::makeScale(point_t point, point_t center, double k)
{
  point.x = center.x + (point.x - center.x) * k;
  point.y = center.y + (point.y - center.y) * k;
  return point;
}
