#pragma once
#include <wx\wx.h>
#include "BoardWindow.h"


class Cell : public wxBitmapButton
{
public:
	Cell(BoardWindow * window, int koorx, int koory);
	~Cell();
	int koorx, koory;
	int x, y;
private:
	
	BoardWindow *parent;
};

