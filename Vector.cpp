#include "Vector.hpp"
#include <iostream>
#include <algorithm>

Vector::Vector(Point begin, Point end):
  Planar(),
  data{begin, end}
{}

int Vector::x() const
{
  return data[1].x() - data[0].x();
}

int Vector::y() const
{
  return data[1].y() - data[0].y();
}

int Vector::abs_sqr() const
{
 return x()*x() + y()*y();
}

double Vector::area() const
{
  return 0.0;
}

frame_t Vector::frame() const
{
  int x1 = data[0].x();
  int y1 = data[0].y();
  int x2 = data[1].x();
  int y2 = data[1].y();
  return
  {
    {std::min(x1,x2), std::min(y1,y2)},
    {std::max(x1,x2), std::max(y1,y2)}
  };
}

void Vector::print() const
{
  std::cout << "Vector [" << data[0].x() << ";" << data[0].y() << " - " << data[1].x() << ";" << data[1].y() << "]" << "\n";
}
