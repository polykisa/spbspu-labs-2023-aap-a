#include "ellipse.hpp"
#include <stdexcept>

stepanov::Ellipse::Ellipse(const point_t &center, double radiusY, double radiusX):
  center_(center),
  radiusY_(radiusY),
  radiusX_(radiusX)
{
  if ((radiusY <= 0.0) || (radiusX <= 0.0))
  {
    throw std::invalid_argument("Radius must be positive");
  }
}

double stepanov::Ellipse::getArea() const
{
  return 3.14 * radiusY_ * radiusX_;
}

stepanov::rectangle_t stepanov::Ellipse::getFrameRect() const
{
  return {2 * radiusX_, 2 * radiusY_, center_};
}

void stepanov::Ellipse::move(const point_t& p)
{
  center_ = p;
}

void stepanov::Ellipse::move(const double dx, const double dy)
{
  center_ = {center_.x + dx, center_.y + dy};
}

void stepanov::Ellipse::scale(const double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("The ratio must be positive");
  }
  radiusY_ *= ratio;
  radiusX_ *= ratio;
}

