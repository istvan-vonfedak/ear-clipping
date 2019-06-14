#include "polygonTriangulation.hpp"
#include <iostream>

using namespace std;

void printPoint(const Point & p)
{ cout<<"("<<p.x<<","<<p.y<<")\n"; }

void testPoints()
{ printPoint(Point(4, 12));
  printPoint(Point(2, 3));
  printPoint(Point(4, 12) + Point(2, 3));
  printPoint(Point(4, 12) - Point(2, 3));
  printPoint(Point(4, 12) * Point(2, 3));
  printPoint(Point(4, 12) / Point(2, 3)); }

void printPoints(vector<Point> points)
{ for(unsigned int i = 0; i < points.size(); i ++)
    printPoint(points[i]); }

void testTriangulation()
{ vector<Point> points;
  points.push_back(Point(0, 0));
  points.push_back(Point(0, 1));
  points.push_back(Point(1, 1));
  points.push_back(Point(1, 0));

  cout<<"not triangulated\n";
  printPoints(points);
  cout<<"triangulated\n";
  printPoints(triangulate(points)); }

int main(int argc, char * argv[])
{ testTriangulation();
  return 0; }
