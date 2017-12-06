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

	wxBitmap *mainmenu;
	wxBitmap *mainmenuglow;
	wxBitmap *howtoplay;
	wxBitmap *scrollnext = nullptr;
	wxBitmap *scrollnextglow = nullptr;
	wxBitmap *scrollprev = nullptr;
	wxBitmap *scrollprevglow = nullptr;

	wxBitmapButton *back;
	wxBitmapButton *scrollnextbutton;
	wxBitmapButton *scrollprevbutton;

	int page = 1;
	void LoadBitmap();
	DECLARE_EVENT_TABLE()
};

