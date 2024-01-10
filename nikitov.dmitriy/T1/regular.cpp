#include "regular.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>

nikitov::Regular::Regular(point_t& firstPoint, point_t& secondPoint, point_t& thirdPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{
  double firstLine = pow(firstPoint_.x - secondPoint_.x, 2) + pow(firstPoint_.y - secondPoint_.y, 2);
  double secondLine = pow(thirdPoint_.x - secondPoint_.x, 2) + pow(thirdPoint_.y - secondPoint_.y, 2);
  double thirdLine = pow(firstPoint_.x - thirdPoint_.x, 2) + pow(firstPoint_.y - thirdPoint_.y, 2);
  if (!(firstLine + secondLine == thirdLine || secondLine + thirdLine == firstLine)
    || std::max(sqrt(firstLine), sqrt(thirdLine)) > sqrt(secondLine) * 2)
  {
    throw std::invalid_argument("Error: invalid regular agrugments");
  }
}

nikitov::Regular::~Regular()
{}

double nikitov::Regular::getArea() const
{
  double firstLine = sqrt(pow(firstPoint_.x - secondPoint_.x, 2) + pow(firstPoint_.y - secondPoint_.y, 2));
  double thirdLine = sqrt(pow(firstPoint_.x - thirdPoint_.x, 2) + pow(firstPoint_.y - thirdPoint_.y, 2));

  double circumRadius = std::max(firstLine, thirdLine);
  double inRadius = std::min(firstLine, thirdLine);
  int n = round(-2 * M_PI / (asin(inRadius / circumRadius) * 2 - M_PI));

  double a = 2 * circumRadius * sin(M_PI / n);
  return 0.5 * n * a * inRadius;
}

nikitov::rectangle_t nikitov::Regular::getFrameRect() const
{
  double firstLine = sqrt(pow(firstPoint_.x - secondPoint_.x, 2) + pow(firstPoint_.y - secondPoint_.y, 2));
  double thirdLine = sqrt(pow(firstPoint_.x - thirdPoint_.x, 2) + pow(firstPoint_.y - thirdPoint_.y, 2));

  double circumRadius = std::max(firstLine, thirdLine);
  double inRadius = std::min(firstLine, thirdLine);
  int n = round(-2 * M_PI / (asin(inRadius / circumRadius) * 2 - M_PI));
  double a = 2 * circumRadius * sin(M_PI / n);

  double height = 0;
  double width = 0;
  if (n == 3 || n == 4)
  {
    width = a;
  }
  else if (n % 2 == 0 && n % 4 != 0)
  {
    width = 2 * circumRadius * sin(n * M_PI / 2 / n);
  }
  else if (n % 2 != 0)
  {
    width = 2 * circumRadius * sin(n * M_PI / (2 * n + 1));
  }
  else
  {
    double diagonal = 2 * circumRadius * sin(n * M_PI / 2 / n);
    width = sqrt(pow(diagonal, 2) - pow(a, 2));
  }
  if (n % 2 == 0)
  {
    height = 2 * inRadius;
  }
  else
  {
    height = circumRadius + inRadius;
  }
  return { width, height, firstPoint_ };
}

void nikitov::Regular::move(const point_t& point)
{
  double dx = point.x - firstPoint_.x;
  double dy = point.y - firstPoint_.y;
  move(dx, dy);
}

void nikitov::Regular::move(double dx, double dy)
{
  firstPoint_.x += dx;
  firstPoint_.y += dy;
  secondPoint_.x += dx;
  secondPoint_.y += dy;
  thirdPoint_.x += dx;
  thirdPoint_.y += dy;
}

void nikitov::Regular::scale(double ratio)
{
  secondPoint_.x = firstPoint_.x + (secondPoint_.x - firstPoint_.x) * ratio * ratio;
  secondPoint_.y = firstPoint_.y + (secondPoint_.y - firstPoint_.y) * ratio * ratio;
  thirdPoint_.x = firstPoint_.x + (thirdPoint_.x - firstPoint_.x) * ratio * ratio;
  thirdPoint_.y = firstPoint_.y + (thirdPoint_.y - firstPoint_.y) * ratio * ratio;
}
