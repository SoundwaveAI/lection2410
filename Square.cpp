#include "Square.hpp"
#include <iostream>

Square::Square(Point p, int side) :
  Planar(),
  corner_(p),
  side_(side)
{}

int Square::x() const
{
  return corner_.x();
}

int Square::y() const
{
  return corner_.y();
}

int Square::abs_sqr() const
{
  return corner_.abs_sqr();
}

double Square::area() const
{
  return (double)side_ * side_;
}

frame_t Square::frame() const
{
  int x1 = corner_.x();
  int y1 = corner_.y();
  return {
    {x1, y1},
    {x1 + side_, y1 + side_}
  };
}

void Square::print() const {
  std::cout << "Square [Corner: (" << x() << "; " << y()
            << "), Side: " << side_ << "]" << "\n";
}
