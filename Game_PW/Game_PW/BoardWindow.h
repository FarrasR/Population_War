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
	void Response(wxCommandEvent &event);	//RESPONSE CUMA BUAT INPUT, DIPROSES SAMA FUNGSI LAIN!!!
	void UpdateCells();



	vector<vector <Cell*> >myboard;

	//Updater
	void Update_Cell_Future_Ownership(Coordinates search);
	void Update_Board();


	//Getter
	int Get_Cell_Ownership(Coordinates search);
	int Get_Future_Ownership(Coordinates search);
	Nearby Get_Nearby_Cell(Coordinates search);

	//set Ownership
	void Set_Current_Cell(Coordinates target, int player);
	void Set_Future_Cell(Coordinates target, int player);
	


	//Func
	void FirstPhase(Cell* cari);


	wxBitmap *cell00 = nullptr;
	wxBitmap *cell11 = nullptr;
	wxBitmap *cell22 = nullptr;
	wxBitmap *cell01 = nullptr;
	wxBitmap *cell02 = nullptr;
	wxBitmap *cell10 = nullptr;
	wxBitmap *cell20 = nullptr;



	wxBitmap *mainmenu = nullptr;
	wxBitmap *mainmenuglow = nullptr;
	
private:
	PWFrame *parent;
	
	wxBitmap *board = nullptr;
	wxBitmap *logo = nullptr;
	
	wxBitmapButton *buttonmainmenu;
	wxBitmapButton *buttoncellcoba;

	bool First_Phase;


	int Current_Player;
	int Count;
	int Total_Count;

	void LoadBitmap();
	DECLARE_EVENT_TABLE()
};

