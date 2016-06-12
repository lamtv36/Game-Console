#include "Point2D.h"


Point2D::Point2D(int x=0, int y=0):xval(x), yval(y)
{
}

Point2D::Point2D(void): xval(0), yval(0)
{

}

int Point2D::x()
{
	return this->xval;
}

int Point2D::y()
{
	return yval;
}

void Point2D::set_x(int value)
{
	xval = value;
}

void Point2D::set_y(int value)
{
	yval = value;
}

Point2D Point2D::operator+(Point2D other)
{
	return Point2D(xval + other.xval, yval + other.yval);
}

Point2D Point2D::operator+=(Point2D other)
{
	this->xval += other.xval;
	this->yval += other.yval;
	return (*this);
}

bool Point2D::operator==(Point2D other)
{
	return ((xval == other.x()) &&(yval == other.y()));
}

Point2D Point2D::operator-(Point2D other)
{
	return Point2D(xval - other.xval, yval - other.yval);
}

Point2D Point2D::operator=(const Point2D other)
{
	this->xval = other.xval;
	this->yval = other.yval;
	return (*this);
}

// move coordinate
void Point2D::move(int dx, int dy)
{
	xval += dx;
	yval += dy;
}

Point2D::~Point2D(void)
{
}
