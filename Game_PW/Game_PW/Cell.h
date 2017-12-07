#pragma once
#include <wx\wx.h>
#include "BoardWindow.h"


class Cell : public wxBitmapButton
{
public:
	Cell(BoardWindow * window, int koorx, int koory, int x, int y);
	~Cell();
	int koorx, koory;
	int x, y;
	int tipe;
	int idx;

	int ownership = 0;
	int futureownership = 0;

	void setColor();

private:
	BoardWindow *parent;
};

