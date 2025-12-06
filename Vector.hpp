#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "Planar.hpp"
#include "Point.hpp"

struct Vector: Planar
{
  Vector(Point begin, Point end);
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;
  virtual double area() const override;
  virtual frame_t frame() const override;
  virtual ~Vector() = default;
private:
  Point data[2];
};

#endif

