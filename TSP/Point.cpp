#include "stdafx.h"
#include "Point.h"
#include <cmath>


// Default constructor:  initializes the point to (0, 0).
Point::Point() {
  x_coord = 0;
  y_coord = 0;
}

// Initializes the point to (x, y).
Point::Point(double x, double y) {
  x_coord = x;
  y_coord = y;
}

// Destructor - Point allocates no dynamic resources.
Point::~Point() {
  // no-op
}

// Mutators:

void Point::setX(double val) {
  x_coord = val;
}

void Point::setY(double val) {
  y_coord = val;
}


// Accessors:

double Point::getX() {
  return x_coord;
}

double Point::getY() {
  return y_coord;
}


// Other methods:

// Calculate distance between this point and another point. 
double Point::distanceTo(const Point& point) const {
	double distance = sqrt(pow((x_coord - point.x_coord), 2) + pow((y_coord - point.y_coord), 2));
	return distance;
}