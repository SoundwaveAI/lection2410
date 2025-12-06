#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "Planar.hpp"
#include "Point.hpp"

struct Square : Planar
{
  Square(Point p, int side);
  virtual int x() const override;
  virtual int y() const override;
  virtual int abs_sqr() const override;
  virtual double area() const override;
  virtual frame_t frame() const override;
  virtual void print() const override;
  virtual ~Square() = default;
private:
  Point corner_;
  int side_;
};

#endif
