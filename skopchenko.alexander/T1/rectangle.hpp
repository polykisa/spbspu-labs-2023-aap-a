#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

namespace skopchenko
{
  class Rectangle: public Shape
  {
   public:
    Rectangle(const point_t & left_down, const point_t & right_up);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & position) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  };
}

#endif
