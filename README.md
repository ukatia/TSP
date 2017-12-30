# TSP
 A console application providing a simple solution to Traveling Salesman Problem using the C++ Standard Template Library

## Build
Microsoft Visual Studio 2017
### Code Structure
```
TSP/
   /Point.h 
   /Point.cpp
   /Point3D.h
   /Point3D.cpp
   /TSP.cpp
```
``` Point.h ``` - 2-dimensional point class declaration  <br/>
``` Point.cpp ``` - 2-dimensional point class implementation <br/>
``` Point3D.h ``` -  3-dimensional point class declaration - derived from Point class <br/>
``` Point3D.cpp ``` -  3-dimensional point class implementation <br/>
``` TSP.cpp ``` -  main function is defined here<br/>
The following functions are defined here: <br/>
``` 
template<class T> vector<int> findShortestPath(const vector<T> &points);
``` 
This function takes a vector of points, and returns a vector that specifies the order to visit all of the points in a single round trip, visiting each point once, to ensure that the trip is as short as possible. 
``` 
template<class T> double getPathLength(const vector<T> &points, const vector<int> &order);
``` 
This function takes a vector of points, and the order in which those points are visited, and it computes the total length of the path when the points are traveled in the specified order. 
The path is a complete round trip.
``` 
template<class T> double computeArea(T &p1, T &p2, T &p3);
``` 
This function takes three points by reference and returns the area within the triangle defined by these points. 

### C++ 11 Features
**auto** - The type of the variable that is being declared will be automatically deduced from its initializer.
``` 
auto print = [](const int& n) { std::cout << " " << n; };
``` 
**for_each** - iterate over vector
``` 
std::for_each(order.begin(), order.end(), print);
``` 
**template<class T>** - template not instatiated by the compiler
``` 
template<class T> double computeArea(T &p1, T &p2, T &p3);
``` 
**std::vector** - move constructor and initializer list constructor added
``` 
vector<int> order;
``` 
**std::next_permutation**  - find the next possible lexicographically permutation of elements
``` 
std::next_permutation(order.begin(), order.end())
``` 
### Use case
The user is asked to enter a number of 3D points and give the coordinates for each point.<br/>
The program returns the shortest distance to traverse these points and the order in which they should be visited.<br/>
If three points are given, the program also prints the area within the triangle defined by these points. <br/>
**Note**: This program implements a simple brute-force solution that will work for a small number of points, but it will be too slow for a large number of points as this problem belongs to the class of NP-complete problems.
#### Example - run
``` 
How many points? 3
Point1:
x: 6
y: 7
z: 2
Point2:
x: 4
y: 1
z: 6
Point3: 
x: 8
y: 4
z: 5
Shortest Distance: 17.2728
Shortest Path is [ 0 2 1 ]
Area is : 11.79
``` 
``` 
How many points? 5
Point1:
x: 2
y: 4
z: 6
Point2:
x: 5
y: 3
z: 2
Point3: 
x: 6
y: 7
z: 6
Point4: 
x: 2
y: 5
z: 6
Point5: 
x: 7
y: 9
z: 1
Shortest Distance: 22.4515
Shortest Path is [ 0 1 4 2 3 ]
``` 
