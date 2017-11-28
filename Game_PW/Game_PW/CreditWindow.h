#pragma once
#include "wx\wx.h" 
#include "PWFrame.h"

class CreditWindow : public wxWindow
{
public:
	CreditWindow(PWFrame *parent);
	~CreditWindow();
	void BackToMainMenu(wxCommandEvent &event);

private:
	PWFrame *parent;

	wxBitmap *mainmenu = nullptr;
	wxBitmap *mainmenuglow = nullptr;

	wxBitmapButton *buttonmainmenu;

	void LoadBitmap();
	DECLARE_EVENT_TABLE()
};

