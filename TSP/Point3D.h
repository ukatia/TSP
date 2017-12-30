#ifndef __POINT3D_H_INCLUDED__
#define __POINT3D_H_INCLUDED__

#include "Point.h"

// A 3-dimensional point class derived from 2D point!

class Point3D: Point {
	protected:
		double z_coord;
	public:
		Point3D();    // default constructor
		Point3D(double x, double y, double z);    // three-argument constructor

	~Point3D();

	// Mutator method
	void setZ(double val);

	// Accessor methods
	double getZ();

	//Calculate distance method
	double distanceTo(const Point3D&point) const;
};

#endif   // __POINT3D_H_INCLUDED__ 
