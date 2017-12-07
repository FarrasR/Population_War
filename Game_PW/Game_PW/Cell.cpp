#include "Cell.h"

Cell::Cell(BoardWindow * window, int koorx, int koory, int x, int y) 
{
	this->parent = window;
	this->koorx = koorx;
	this->koory = koory;
	this->x = x;
	this->y = y;
	Create(parent, wxID_ANY, *parent->cellhitamhitam, wxPoint(this->koorx, this->koory), wxDefaultSize, wxBORDER_NONE);
	
}


Cell::~Cell()
{
}

void Cell::setColor()
{
	if (ownership == 0 && futureownership == 0)this->SetBitmap(*parent->cellhitamhitam);
	else if (ownership == 1 && futureownership == 1)this->SetBitmap(*parent->cellbirubiru);
}



