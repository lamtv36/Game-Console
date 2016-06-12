#include "Snake.h"


Snake::Snake(): pos(Point2D(0, 0)), direction(2), size(3), live(true)
{

};

void Snake::set_direction(unsigned int value)
{
	if(value < 0 || value >3)
	{
		cout << "need set value range [0:3]";
		return;
	}
	direction = static_cast<int>(value);
}

void Snake::set_pos(Point2D new_pos)
{
	pos = new_pos;
	m_snake.push_back(pos);
	for(int i = 0; i < size-1; i ++)
	{
		this->eat();
	}
}

void Snake::eat()
{
	Point2D new_pos;
	if(!m_snake.size())
		new_pos = (*this->m_snake.end());
	else
		new_pos = this->pos;
	/*new_pos.set_x((*this->m_snake.end()).x());
	new_pos.set_y((*this->m_snake.end()).y());*/
	m_snake.push_back(new_pos);
	for(int i = m_snake.size() - 1; i > 0; i--)
		m_snake.at(i) = m_snake.at(i-1);
	*m_snake.begin() += this->step_move();
}

void Snake::move()
{
	if(!m_snake.size())
		return;
	for(int i = m_snake.size()-1; i > 0; i--)
	{
		m_snake.at(i) = m_snake.at(i-1);
	}
	int x = this->step_move().x();
	int y = this->step_move().y();
	m_snake.at(0).move(x, y);
	this->pos.move(x, y);
}

Point2D Snake::step_move()
{
	switch(this->direction)
	{
		// turn left
	case 0:
		return Point2D(-1, 0);
		//turn right
	case 1:
		return Point2D(0, 1);
		//turn up
	case 2:
		return Point2D(1, 0);
		//turn bottom
	case 3:
		return Point2D(0, -1);
	default:return Point2D(0, 0);
	}
}

void Snake::set_size(int value)
{
	if (value < 0)\
		return;
	this->size = value;
}

const int Snake::get_size()
{
	return m_snake.size();
}

bool Snake::is_live()
{
	return live;
}

void Snake::set_sate_snake(bool state)
{
	live = state;
}

Point2D Snake::get_position()
{
	return pos;
}

unsigned int Snake::get_direction()
{
	return this->direction;
}

vector<Point2D> Snake::get_m_snake()
{
	return m_snake;
}

Snake::~Snake(void)
{
}
