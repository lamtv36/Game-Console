#include "GameSnake.h"


GameSnake::GameSnake(void): speed(400)
{
}


GameSnake::~GameSnake(void)
{
}

void GameSnake::set_map(Map new_map)
{
	map = new_map;
}

void GameSnake::set_snake(Snake new_snake)
{
	snake = new_snake;
}

void GameSnake::set_speed(int value)
{
	if(value < 0)
	{
		cout << " can't set up time smaller zero" << endl;
		return;
	}
	speed = value;
}

void GameSnake::update_view()
{
	system("cls");
}

void GameSnake::change_direction(char ch)
{
	switch(ch)
	{
		// turn left
	case 'w':
		if(snake.get_direction()== 2)
			break;
		snake.set_direction(0);
		break;
		//turn right
	case 'd':
		if(snake.get_direction()== 3)
			break;
		snake.set_direction(1);
		break;
		//turn up
	case 's':
		if(snake.get_direction() == 0)
			break;
		snake.set_direction(2);
		break;
		//turn bottom
	case 'a':
		if(snake.get_direction()== 1)
			break;
		snake.set_direction(3);
		break;
	default:
		break;
	}
}

void GameSnake::control_snake()
{
	if(_kbhit())
	{
		this->change_direction(_getch());
	}
	Point2D head_pos;
	head_pos = *snake.get_m_snake().begin();
	int x , y;
	x = head_pos.x();
	y = head_pos.y();
	if(x==0 || y == 0 || x==map.get_width() || y == map.get_height())
		snake.set_sate_snake(false);
}

void GameSnake::generate_food()
{
	bool check= false;
	Point2D new_pos;
	srand(time(NULL));
	while(!check)
	{
		check= false;
		int x = rand()%map.get_width()-1 + 1;
		int y = rand()%map.get_height()-1 + 1;
		new_pos.set_x(x);
		new_pos.set_y((y));
		for(unsigned int i = 0; i < snake.get_m_snake().size(); i++)
			if(new_pos == snake.get_m_snake().at(i))
				check= true;
		if(!check)
			check = true;
	}
	this->pos_food = new_pos;
}

void GameSnake::run()
{
	snake.set_pos(Point2D(5, 5));
	map.set_size(20, 20);
	snake.set_size(5);
	this->generate_food();
	this->speed = 300;
	while(snake.is_live())
	{
		this->update_view();
		this->control_snake();
		if ( *snake.get_m_snake().begin() == this->pos_food)
		{
			generate_food();
			snake.eat();
		}
		else
			snake.move();
		this->draw();
		Sleep(this->speed);

	}
	this->update_view();
	cout <<"\n\n\n\n"<<endl;
	cout << " GAME OVER" << endl;
	cout << " Your Score: "<< snake.get_m_snake().size() << endl;
	cout <<endl;
}

void GameSnake::draw()
{
	// draw map
	int width = map.get_width();
	int height = map.get_height();
	for (int i=0; i<=width; i ++)
	{
		for(int j=0; j<=height; j++)
		{
			// draw frame of map
			if(i==0 || j==0 || i==width || j==height)
				printf("%c", 219);
			else if(this->_check_pos(Point2D(i, j)))
				printf("%c", 167);
			else if(this->pos_food == Point2D(i, j))
				cout <<'M';
			else
				cout <<' ';
		}
		cout << endl;
	}
}

bool GameSnake::_check_pos(Point2D pos)
{
	for(unsigned int k = 0; k < snake.get_m_snake().size(); k++)
	{
		if(snake.get_m_snake().at(k)==pos)
			return true;
	}
	return false;
}
