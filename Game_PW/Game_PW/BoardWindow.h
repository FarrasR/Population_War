#pragma once 
#include "wx\wx.h" 
#include "PWFrame.h"
#include <wx/app.h>
#include <wx/arrimpl.cpp>
#include <wx/dynarray.h>
#include <wx/dcbuffer.h>

class Cell;

class BoardWindow : public wxWindow{
public:
	BoardWindow(PWFrame *parent);
	~BoardWindow();
	
	void OnPaint(wxPaintEvent &event);
	void BackToMainMenu(wxCommandEvent &event);
	void Response(wxCommandEvent &event);
	void UpdateCells();


	Cell *cell;
	wxBitmap *cellhitamhitam = nullptr;
	wxBitmap *cellbirubiru = nullptr;
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

