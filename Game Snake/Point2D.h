#pragma once
#include <iostream>
using namespace std;
class Point2D
{
private:
	int xval;
	int yval;
public:
	Point2D(void);
	Point2D(int, int);
	int x();
	int y();
	void set_x(int value);
	void set_y(int value);
	Point2D operator+(Point2D other);
	Point2D operator+=(Point2D other);
	bool operator==(Point2D other);
	Point2D operator-(Point2D other);
	Point2D operator=(const Point2D other);
	void move(int, int);
	~Point2D(void);
};

