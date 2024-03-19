#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include "base-types.hpp"

namespace skopchenko
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t) = 0;
    virtual void move(double, double) = 0;
    virtual void scale(double ratio) = 0;
  };
}

#endif
