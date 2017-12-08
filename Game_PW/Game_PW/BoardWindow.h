#pragma once 
#include "wx\wx.h" 
#include "PWFrame.h"
#include <wx/app.h>
#include <wx/arrimpl.cpp>
#include <wx/dynarray.h>
#include <wx/dcbuffer.h>
#include <vector>
#include "CellTools.h"
using namespace std;


class Cell;

class BoardWindow : public wxWindow{
public:
	BoardWindow(PWFrame *parent);
	~BoardWindow();
	void OnPaint(wxPaintEvent &event);
	void BackToMainMenu(wxCommandEvent &event);
	void Response(wxCommandEvent &event);
	void UpdateCells();


	vector<vector <Cell*> >myboard;

	//Getter
	int Get_Cell_Ownership(Coordinates search);
	int Get_Future_Ownership(Coordinates search);
	Nearby Get_Nearby_Cell(Coordinates search);



	//set Ownership
	void Set_Current_Cell(Coordinates target, int player);
	void Set_Future_Cell(Coordinates target, int player);


	wxBitmap *cell00 = nullptr;
	wxBitmap *cell11 = nullptr;



	wxBitmap *mainmenu = nullptr;
	wxBitmap *mainmenuglow = nullptr;
	
private:
	PWFrame *parent;
	
	wxBitmap *board = nullptr;
	wxBitmap *logo = nullptr;
	
	wxBitmapButton *buttonmainmenu;
	wxBitmapButton *buttoncellcoba;

	void LoadBitmap();
	DECLARE_EVENT_TABLE()
};

