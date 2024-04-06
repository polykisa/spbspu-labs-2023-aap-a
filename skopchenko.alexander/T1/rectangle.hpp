#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(point_t & left_down, point_t & right_up);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t position) override;
  void move(double dx, double dy) override;
  void scale(double k) override;
private:
  point_t left_down_;
  point_t right_up_;
};

#endif
