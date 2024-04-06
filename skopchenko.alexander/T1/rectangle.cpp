#include "rectangle.hpp"
#include <stdexcept>
#include "functions.h"

Rectangle::Rectangle(point_t left_down, point_t right_up):
  left_down_(left_down),
  right_up_(right_up)
{}

rectangle_t Rectangle::getFrameRectangle() const
{
  point_t side = {right_up_.x - left_down_.x, right_up_.y - left_down_.y};
  point_t position = {(left_down_.x + right_up_.x) / 2, (left_down_.y + right_up_.y) / 2};
  return {side.x, side.y, position};
}

double Rectangle::getArea() const
{
  double area_rectangle = getFrameRectangle().width * getFrameRectangle().height;
  return area_rectangle;
}

void Rectangle::move(double dx, double dy)
{
  left_down_ = suppFunctions::findSummVector(left_down_, dx, dy);
  right_up_ = suppFunctions::findSummVector(right_up_, dx, dy);
}

void Rectangle::move(point_t position)
{
  point_t diff = suppFunctions::findDifference(position, getFrameRectangle().position);
  move(diff.x, diff.y);
}

void Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("k under zero");
  }
  point_t center = getFrameRectangle().position;
  left_down_ = suppFunctions::makeScale(left_down_, center, k);
  right_up_ = suppFunctions::makeScale(right_up_, center, k);
}

