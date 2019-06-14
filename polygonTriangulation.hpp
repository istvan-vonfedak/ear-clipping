#ifndef POLYGONTRIANGULATION_HPP
#define POLYGONTRIANGULATION_HPP

#include "Point.hpp"
#include <vector>
#include <iostream>
#include <cmath>


// calculates the determinant of two vectors
float determinant(const Point & u, const Point & v);

// calculates the distance between the two vectors
float vectorDistance(const Point & v1, const Point & v2);

// tests if triangle abc contains a point within it
// this is done by calculating if the point is at the left side of each edge
// going arround in a counter clockwise direction
bool pointIsWithinTriangle(const Point & a, const Point & b,
	const Point & c, const Point & point);

std::vector<Point> triangulate(const std::vector<Point> & initialPoints);


#endif /* POLYGONTRIANGULATION_HPP */
