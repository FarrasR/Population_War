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
	int idx;

	//setter
	void Set_Current_Ownership(int player);
	void Set_Future_Ownership(int player);


	//getter
	int Get_Ownership();
	int Get_Future_Ownership();

	//updater
	void Update_Current_Ownership();

	void setColor();

private:
	//ownership
	//0=mati, 1=player1, 2=player2
	int Current_Ownership;
	int Future_Ownership;


	BoardWindow *parent;
};

