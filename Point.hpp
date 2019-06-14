#ifndef POINT_HPP
#define POINT_HPP

struct Point {
  double x, y;

  Point(): x(0), y(0) {}
  
  Point(const Point & p): x(p.x), y(p.y) {}
  
  Point(double px, double py): x(px), y(py) {}
  
  Point operator + (const Point & p) const
  { return Point(x + p.x, y + p.y); }
  
  Point operator - (const Point & p) const
  { return Point(x - p.x, y - p.y); }
  
  Point operator * (const Point & p) const
  { return Point(x * p.x, y * p.y); }
  
  Point operator / (const Point & p) const
  { return Point(x / p.x, y / p.y); }

};

#endif /* POINT_HPP */
