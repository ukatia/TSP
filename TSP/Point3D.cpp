#include "stdafx.h"
#include "Point3D.h"
#include <cmath>

// Default constructor:  initializes the point to (0, 0, 0).
Point3D::Point3D()
{
	z_coord = 0;
}

Point3D::Point3D(double x, double y, double z):Point(x,y) {
	z_coord = z;
}


Point3D::~Point3D()
{
}

// Mutators:

void Point3D::setZ(double val) {
	z_coord = val;
}

// Accessors:

double Point3D::getZ() {
	return z_coord;
}

// Other methods:

// Calculate distance between this point and another point. 
double Point3D::distanceTo(const Point3D& point) const {
 	double distance = sqrt(pow((x_coord - point.x_coord), 2) + pow((y_coord - point.y_coord), 2) + pow((z_coord - point.z_coord), 2));
	return distance;
}