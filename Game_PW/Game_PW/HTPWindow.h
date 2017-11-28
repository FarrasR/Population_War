#pragma once
#include "wx\wx.h" 
#include "PWFrame.h"

class HTPWindow : public wxWindow
{
public:
	HTPWindow(PWFrame *parent);
	~HTPWindow();
	void OnPaint(wxPaintEvent &event);
	void NextPage(wxCommandEvent &event);
	void PreviousPage(wxCommandEvent &event);
	void BackToMainMenu(wxCommandEvent &event);
	void CheckPage();

private:
	PWFrame *parent;
	wxButton *nextbutton;
	wxButton *Previousbutton;
	wxBitmapButton *back;

	wxBitmap *mainmenu;
	wxBitmap *mainmenuglow;
	wxBitmap *howtoplay;

	int page;
	void LoadBitmap();
	DECLARE_EVENT_TABLE()
};

