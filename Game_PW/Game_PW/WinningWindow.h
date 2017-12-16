#pragma once
#include "wx\wx.h" 
#include "PWFrame.h"
class WinningWindow : public wxWindow
{
public:
	WinningWindow(PWFrame *parent);
	~WinningWindow();

	void BackToMainMenu(wxCommandEvent &event);


private:
	PWFrame *parent;
	wxBitmap *mainmenu = nullptr;
	wxBitmap *mainmenuglow = nullptr;

	wxBitmapButton *back;

	void LoadBitmap();

	DECLARE_EVENT_TABLE()
};

