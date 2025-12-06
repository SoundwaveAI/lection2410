#include <iostream>
#include "Planar.hpp"
#include "functions.hpp"

int main()
{
  size_t count = 0;
  size_t capacity = 20;
  Planar** pls = new Planar*[capacity];
  while (true)
  {
    if (std::cin.eof())
    {
      break;
    }
    try
    {
      Planar* pl = make(std::cin);
      if (count == capacity)
      {
        Planar** epls = new Planar*[capacity*2];
        for (size_t i = 0; i < count; ++i)
        {
          epls[i] = pls[i];
        }
        delete[] pls;
        pls = epls;
        capacity *= 2;
      }
      pls[count++] = pl;
    }
    catch (...)
    {
      break;
    }
  }
  if (count == 0)
  {
    delete[] pls;
    return 0;
  }

  Planar** ml = mostleft(pls, count);
  std::cout << "The most left" << "\n";
  draw(*ml);

  Planar* ma = max_area(pls, count);
  std::cout << "Max area" << "\n";
  if (ma)
  {
    draw(ma);
    std::cout << "Area: " << ma->area() << "\n";
  }

  PlanarPair p_int = max_frame_sects(pls, count);
  std::cout << "Max frame section" << "\n";
  if (p_int.fir && p_int.sec)
  {
    draw(p_int.fir);
    draw(p_int.sec);
  }
  else
  {
    std::cout << "No section" << "\n";
  }
  free_planars(pls, count);
  delete[] pls;
  return 0;
}
