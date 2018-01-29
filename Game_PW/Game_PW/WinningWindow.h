#pragma once
#include "wx\wx.h" 
#include "PWFrame.h"
class WinningWindow : public wxWindow
{
public:
	WinningWindow(PWFrame *parent);
	~WinningWindow();

	void BackToMainMenu(wxCommandEvent &event);
	void WhoWin();

private:
	PWFrame *parent;
	wxBitmap *mainmenu = nullptr;
	wxBitmap *mainmenuglow = nullptr;
	wxBitmap *p1char = nullptr;
	wxBitmap *p2char = nullptr;
	wxBitmap *congrats = nullptr;

	wxStaticBitmap *congratsstatic;
	wxStaticBitmap *playercharwin;
	wxStaticBitmap *playerwin;
	wxBitmap *player1win = nullptr;
	wxBitmap *player2win = nullptr;
	wxBitmap *playerdraw = nullptr;

	wxBitmapButton *back;

	void LoadBitmap();

	DECLARE_EVENT_TABLE()
};

