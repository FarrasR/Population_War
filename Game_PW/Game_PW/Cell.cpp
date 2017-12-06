#include "Cell.h"



Cell::Cell(BoardWindow * window, int koorx, int koory) 
{
	this->parent = window;
	this->koorx = koorx;
	this->koory = koory;
	Create(parent, 4010, *parent->mainmenu, wxPoint(this->koorx, this->koory), wxDefaultSize, wxBORDER_NONE);
}


Cell::~Cell()
{
}


