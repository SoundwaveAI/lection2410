#include "functions.hpp"
#include "Point.hpp"
#include "Vector.hpp"
#include "Square.hpp"
#include <iostream>
#include <algorithm>

Planar* make(std::istream& is)
{
  char cmd[3] = {0};
  is >> std::ws;
  if (!(is >> cmd[0] >> cmd[1]))
  {
    throw std::logic_error("EOF");
  }
  int data[4] = {};
  if (cmd[0] == "P" && cmd[1] == "T")
  {
    if (is >> data[0] >> data[1])
    {
      return new  Point(data[0], data[1]);
    }
  }
  else if (cmd[0] == "V" && cmd[1] == "T")
  {
    if (is >> data[0] >> data[1] >> data[2] >> data[3])
    {
      return new Vector(Point(data[0], data[1]), Point(data[2], data[3]));
    }
  }
  else if (cmd[0] == 'S' && cmd[1] == 'Q')
  {
    if (is >> data[0] >> data[1] >> data[2])
    {
      return new Square(Point(data[0], data[1]), data[2]);
    }
  }
  throw std::logic_error("bad cmd");
}

void free_planars(Planar** pls, size_t k)
{
  for (size_t i = 0; i < k; ++i)
  {
    delete[] pls[i];
  }
}

void draw(Planar* pl)
{
  if (pl)
  {
    pl->print();
    std::cout << "\n";
  }
}

Planar** mostleft(Planar** pls, size_t k)
{
  if (!k)
  {
    return pls;
  }
  Planar** res = pls;
  for (size_t i = 1; i < k; ++i)
  {
    if (pls[i]->x() < (*res)->x())
    {
      res = &pls[i];
    }
  }
  return res;
}

Planar* max_area(Planar** pls, size_t k)
{
  if (k == 0)
  {
    return nullptr;
  }
  Planar* max_p = pls[0];
  for(size_t i = 1; i < k; ++i)
  {
    if (pls[i]->area() > max_p->area())
    {
      max_p = pls[i];
    }
  }
  return max_p;
}

long long intersection_area(const frame_t& a, const frame_t& b)
{
  int left = std::max(a.AA.x, b.AA.x);
  int right = std::min(a.BB.x, b.BB.x);
  int bottom = std::max(a.AA.y, b.AA.y);
  int top = std::min(a.BB.y, b.BB.y);
  if (left < right && bottom < top)
  {
    return (long long)(right - left) * (top - bottom);
  }
  return 0;
}

PlanarPair max_frame_sects(Planar** pls, size_t k)
{
  PlanarPair result = {nullptr, nullptr};
  if (k < 2)
  {
    return result;
  }
  long long max_s = -1;
  for (size_t i = 0; i < k; ++i)
  {
    for (size_t j = i + 1; j < k; ++j)
    {
      long long current_s = section_area(pls[i]->frame(), pls[j]->frame());
      if (current_s > max_s)
      {
        max_s = current_s;
        result.fir = pls[i];
        result.sec = pls[j];
       }
     }
  }
  return result;
}
