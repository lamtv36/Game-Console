#pragma once
#include "Point2D.h"
#include <vector>
#include<iostream>
using namespace std;
class Snake
{
private:
	vector<Point2D> m_snake;
	unsigned int direction;
	bool live;
	Point2D pos; // position of snake, where start of snake
	int size;
public:
	Snake(Point2D, int);
	Snake(void);
	void set_direction(unsigned int);
	void set_pos(Point2D);
	void eat();
	void move();
	Point2D step_move();
	void set_size(int value);
	const int get_size();
	bool is_live();
	void set_sate_snake(bool state);
	Point2D get_position();
	unsigned int get_direction();
	vector<Point2D> get_m_snake();
	~Snake(void);
};
