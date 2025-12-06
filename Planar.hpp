#ifndef PLANAR_HPP
#define PLANAR_HPP

struct p_t
{
  int x, y;
};

struct frame_t
{
  p_t AA, BB;
};

struct Planar
{
  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abs_sqr() const = 0;
  virtual double area() const = 0;
  virtual frame_t frame() const = 0;
  virtual void print() const = 0;
  virtual ~Planar() = default;
};

#endif
