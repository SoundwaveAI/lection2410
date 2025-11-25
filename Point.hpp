#ifndef POINT_HPP
#define POINT_HPP
#include "Planar.hpp"

struct Point: Planar
{
  Point(int xx, int yy);
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;
  virtual ~Point() = default;
private:
  int data[2];
};

#endif


