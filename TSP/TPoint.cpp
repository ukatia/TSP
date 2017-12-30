#include "stdafx.h"
#include "TPoint.h"


TPoint::TPoint(const T pt[n])
{
	cp(pt);
}


TPoint::~TPoint()
{
}

void TPoint::cp(const Point<T, n> &p)
{
	memcpy(mat, p.mat, n * sizeof(T));
}

void TPoint::cp(const T p[n]);
{
	memcpy(mat, p, n * sizeof(T));
}
