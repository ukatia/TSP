// TSP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Point3D.h"
#include <algorithm>
#include <cmath>
#include <iomanip> 
#include <iostream>
#include <vector>

using namespace std;

// Compute area within the triangle defined by three 3d points using the Heron's Formula 
template<class T> double computeArea(T &p1, T &p2, T &p3) {
	double a = p1.distanceTo(p2);
	double b = p2.distanceTo(p3);
	double c = p3.distanceTo(p1);
	double s = (a + b + c) / 2;
	double area = sqrt(s*(s - a) * (s - b)*(s - c));
	return area;
}

template<class T> double getPathLength(const vector<T> &points, const vector<int> &order) {
	double distance = 0;
	for (int i = 0; i < order.size(); i++) {
		if (i == (order.size() - 1))
			distance += points[order[i]].distanceTo(points[order[0]]);
		else
			distance += points[order[i]].distanceTo(points[order[i+1]]);
	}
	return distance;
}


template<class T> vector<int> findShortestPath(const vector<T> &points) {
	vector<int> order;
	for (int i = 0; i < points.size(); i++) {
		order.push_back(i);
	}
	double shortestDistance = getPathLength(points, order);
	vector<int> shortestPath = order;
	while (std::next_permutation(order.begin(), order.end())) {
		double distance = getPathLength(points, order);
		if (distance < shortestDistance) {
			shortestDistance = distance;
			shortestPath = order;
		}
	}
	cout << "Shortest Distance: " << shortestDistance << endl;
	return shortestPath;
}

int main()
{
	std::vector<Point3D> points;
	double x, y, z;
	int nPoints;
	cout << "How many points? ";
	cin >> nPoints;
	for (int i = 0; i < nPoints; i++) {
		cout << "Point " << i+1 << ":\n";
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		cout << "z: ";
		cin >> z;
		Point3D p(x, y, z);
		points.push_back(p);
	}

	vector<int> order = findShortestPath(points);

	cout << "Shortest Path is [";
	auto print = [](const int& n) { std::cout << " " << n; };
	std::for_each(order.begin(), order.end(), print);
	cout << " ]" << endl;

	// If 3 points given print the area inside the triangle defined by the three points
	if (nPoints == 3) {
		// set decimal precision to 2
		cout << "Area is: " << std::setprecision(2) << std::fixed << computeArea(points[0], points[1], points[2]);
	}
	// Keep console window open 
	char c;
	cin >> c;
    return 0;
}

