#pragma once
class Setting
{
public:
	Setting();
	~Setting();

	bool kill;
	bool sacrifice;
	bool convert;
	bool relocate;
	int colorp1 = 1; // 1 blue, 2 red, 3 yellow, 4 green;
	int colorp2 = 2;

	int yangmenang;
};

