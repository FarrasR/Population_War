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

	wxBitmap *mainmenu = nullptr;
	wxBitmap *mainmenuglow = nullptr;
	wxBitmap *howtoplay = nullptr;
	wxBitmap *scrollnext = nullptr;
	wxBitmap *scrollprev = nullptr;
	wxBitmap *scrollnextglow = nullptr;
	wxBitmap *scrollprevglow = nullptr;
	wxBitmap *htppage1 = nullptr;
	wxBitmap *htppage2 = nullptr;
	wxBitmap *htppage3 = nullptr;
	wxBitmap *htppage4 = nullptr;
	wxBitmap *htppage5 = nullptr;
	wxBitmap *htppage6 = nullptr;
	wxBitmap *htppage7 = nullptr;
	wxBitmap *htppage8 = nullptr;
	wxBitmap *htppage9 = nullptr;

	wxStaticBitmap *htptextstatic;
	wxBitmapButton *back;
	wxBitmapButton *scrollnextbutton;
	wxBitmapButton *scrollprevbutton;

	int page = 1;
	void LoadBitmap();
	DECLARE_EVENT_TABLE()
};

