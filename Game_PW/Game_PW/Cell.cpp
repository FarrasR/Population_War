#include "Cell.h"

Cell::Cell(BoardWindow * window, int koorx, int koory, int x, int y) 
{
	this->parent = window;
	this->koorx = koorx;
	this->koory = koory;
	this->x = x;
	this->y = y;
	Create(parent, wxID_ANY, *parent->cell00, wxPoint(this->koorx, this->koory), wxDefaultSize, wxBORDER_NONE);
	Set_Current_Ownership(0);
	Set_Future_Ownership(0);
}


Cell::~Cell()
{
}

void Cell::Set_Current_Ownership(int player)
{
	this->Current_Ownership = player;
}

void Cell::Set_Future_Ownership(int player)
{
	this->Future_Ownership = player;
}

int Cell::Get_Ownership()
{
	return this->Current_Ownership;
}

int Cell::Get_Future_Ownership()
{
	return this->Future_Ownership;
}

void Cell::Update_Current_Ownership()
{
	this->Current_Ownership = this->Future_Ownership;
}



void Cell::setColor()
{
	if (this->Current_Ownership == 0 && Future_Ownership == 0)this->SetBitmap(*parent->cell00);
	else if (Current_Ownership == 1 && Future_Ownership == 1)this->SetBitmap(*parent->cell11);
	else if (Current_Ownership == 2 && Future_Ownership == 2)this->SetBitmap(*parent->cell22);

}



