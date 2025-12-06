#ifndef POINT_HPP
#define POINT_HPP
#include "Planar.hpp"

struct Point: Planar
{
  Point(): data{0, 0}
  {}
  Point(int xx, int yy);
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;
  virtual double area() const override;
  virtual frame_t frame() const override;
  virtual void print() const override;
  virtual ~Point() = default;
private:
  int data[2];
};

#endif


