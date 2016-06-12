#include "Map.h"


void Map::_init_map()
{
	array_map.push_back(Point2D(0, 0));
	for(int i = 1; i < width_size; i ++)
		array_map.push_back(Point2D(i, 0));
	for(int j = 1; j < height_size; j++)
		array_map.push_back(Point2D(0, height_size));
}

Map::Map(void):width_size(20), height_size(20)
{
}


int Map::get_width()
{
	return width_size;
}

int Map::get_height()
{
	return height_size;
}

void Map::set_size(int width, int height)
{
	this->width_size = width;
	this->height_size = height;
}

void Map::set_arry(vector<Point2D> new_array)
{

}

vector<Point2D> Map::get_map()
{
	return this->array_map;
}

Map::~Map(void)
{
}
