#pragma once 
#include "wx\wx.h" 
#include "PWFrame.h"

class Cell;


class BoardWindow : public wxWindow{
public:
	BoardWindow(PWFrame *parent);
	~BoardWindow();
	
	void OnPaint(wxPaintEvent &event);
	void BackToMainMenu(wxCommandEvent &event);
	void Response(wxCommandEvent &event);


	Cell *cell;
	wxBitmap *cellcoba = nullptr;
	wxBitmap *mainmenu = nullptr;
	wxBitmap *mainmenuglow = nullptr;
	
private:
	PWFrame *parent;

	
	
	wxBitmap *board = nullptr;
	wxBitmap *logo = nullptr;
	
	wxBitmapButton *buttonmainmenu;

	void LoadBitmap();
	DECLARE_EVENT_TABLE()
};

