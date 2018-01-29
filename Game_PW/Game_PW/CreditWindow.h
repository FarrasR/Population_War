#pragma once
#include "wx\wx.h" 
#include "PWFrame.h"

class CreditWindow : public wxWindow
{
public:
	CreditWindow(PWFrame *parent);
	~CreditWindow();
	void BackToMainMenu(wxCommandEvent &event);
	void OnTimer(wxTimerEvent &event);

private:
	wxBitmap *mainmenu = nullptr;
	wxBitmap *mainmenuglow = nullptr;
	wxBitmap *creditsbg = nullptr;
	wxBitmap *creditsbg2 = nullptr;

	wxStaticBitmap *newbg;
	wxBitmapButton *buttonmainmenu;
	PWFrame *parent;
	wxTimer *timer;

	void LoadBitmap();
	DECLARE_EVENT_TABLE()

	int hit = 0;
};

