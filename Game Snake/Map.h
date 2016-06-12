#pragma once
#include "Point2D.h"
#include <vector>
using namespace std;
class Map
{
private:
	int width_size;
	int height_size;
	vector<Point2D> array_map;
	void _init_map();
public:
	Map(void);
	int get_width();
	int get_height();
	void set_size(int width, int height);
	void set_arry(vector<Point2D> new_array);
	vector<Point2D> get_map();
	~Map(void);
};

