#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

struct Point {
  double x, y;
  Point()
  { set(0,0); }

  Point(const double xPos, const double yPos)
  { set(xPos, yPos); }

  void set(const double xPos, const double yPos)
  { x = xPos;
    y = yPos; }

  static const double distance(const Point p1, const Point p2)
  { return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); }

  static const double angle(const Point p1, const Point p2, const Point p3, const Point p4)
  { const double dx1 = p2.x - p1.x;
    const double dy1 = p2.y - p1.y;
    const double dx2 = p4.x - p3.x;
    const double dy2 = p4.y - p3.y;
    const double m1 = sqrt(dx1 * dx1 + dy1 * dy1);
    const double m2 = sqrt(dx2 * dx2 + dy2 * dy2);
    const double temp = (dx1 * dx2 + dy1 * dy2) / (m1 * m2);
    cout << "temp = " << temp << endl;
    const double angle = acos(temp) * (180 / acos(-1));
    return (dy1 < dy2) ? angle + 180 : angle; }

  static const double angle_from_origin(const Point p1, const Point p2)
  { Point::angle(p1, p2, Point(0, 0), Point(0, 1)); }

  static const bool collision(const Point p1, const Point p2, const Point p3, const Point p4, Point & inter, const double tolerance = 0.001)
  { const double tmp = (p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x);
    if (tmp == 0)
      return false;
    const double uA = ((p4.x - p3.x)*(p1.y - p3.y) - (p4.y - p3.y)*(p1.x - p3.x))
                      / ((p4.y - p3.y)*(p2.x - p1.x) - (p4.x - p3.x)*(p2.y - p1.y));
    const double uB = ((p2.x - p1.x)*(p1.y - p3.y) - (p2.y - p1.y)*(p1.x - p3.x))
                      / ((p4.y - p3.y)*(p2.x - p1.x) - (p4.x - p3.x)*(p2.y - p1.y));
    inter.set(p1.x + (uA * (p2.x - p1.x)), p1.y + (uA * (p2.y - p1.y))); // intercept
    return (uA >= 0 && uA <= 1 && uB >= 0 + tolerance && uB <= 1 - tolerance); }
};


double Angle(Point p1, Point p2)
{ double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  double angl = atan(dy / dx) * (180 / acos(-1));
  if (dx < 0)
    angl += 180;
  else if
    (dy < 0) angl += 360;
  cout << "angle = " << angl << endl;
  return angl; }

void lineAngle(Point p1, Point p2, Point p3, Point p4)
{ double angl1 = Angle(p1, p2);
  double angl2 = Angle(p3, p4);
  cout << "line angle = " << (angl1 - angl2) << endl; }

void testFileAngles(string fileName)
{ ifstream fin(fileName.c_str());
  if(fin.fail())
  { cout<<"error opening "<<fileName<<endl;
    exit(-1); }
  int x1, y1, x2, y2, x3, y3, x4, y4;
  while(true)
  { fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if(fin.fail()) break;
    lineAngle(Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4)); }
  fin.close(); }

struct Line {
  Point p1;
  Point p2;
  Line()
  { set(0, 0, 0, 0); }

  Line(const double x1, const double y1, const double x2, const double y2)
  { set(x1, y1, x2, y2); }

  void set(const double x1, const double y1, const double x2, const double y2)
  { p1 = Point(x1, y1);
    p2 = Point(x2, y2); }

  void draw()
  { move_to(p1.x, p1.y);
    draw_to(p2.x, p2.y); }

  static const double angle(Line line1, Line line2)
  { return Point::angle(line1.p1, line1.p2, line2.p1, line2.p2); }

  static const bool collision(Line line1, Line line2, Point & inter, const double tolerance = 0.001)
  { return Point::collision(line1.p1, line1.p2, line2.p1, line2.p2, inter, tolerance); }

};

int main(int argc, char * argv[])
{ cout << "line angle..................\n";
  testFileAngles(argv[1]);
//  lineAngle(Point(0, 1), Point(0, 0), Point(0, 0), Point(-1, 0));
  return 0; }

