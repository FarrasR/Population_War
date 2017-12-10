#pragma once
class Coordinates
{
public:
	Coordinates();
	Coordinates(int x, int y);
	int x;
	int y;
};

class Nearby
{
public:
	Nearby()
	{
		this->player[0] = 0;
		this->player[1] = 0;
		this->player[2] = 0;
		this->living = 0;
	}

	void fugu()
	{
		living = player[1] + player[2];
	}

	int live()
	{
		living = player[1] + player[2];
		if (living == 3)
		{
			if (player[1] > player[2])
				future_player = 1;
			else
				future_player = 2;
		}
		else future_player = 0;

		return future_player;
	}
	int player[3];
	int living;
	int future_player;
};

