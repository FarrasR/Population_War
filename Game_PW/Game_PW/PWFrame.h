#pragma once 
#include "wx\wx.h" 
#include "Setting.h"

class PWWindow;
class SettingWindow;
class HTPWindow;
class CreditWindow;
class BoardWindow;
class WinningWindow;

class PWFrame : public wxFrame {
public:
	PWFrame(const wxString &title);
	~PWFrame();
	Setting *setting;
	void InitComponents();
	void ShowMainWindow();
	void ShowBoardWindow();
	void ShowSettingWindow();
	void ShowHTPWindow();
	void ShowCreditWindow();
	void ShowWinningWindow();

private:
	PWWindow *mainwindow;
	SettingWindow *settingwindow;
	HTPWindow *howtoplaywindow;
	CreditWindow *creditwindow;
	BoardWindow *boardwindow;
	WinningWindow *winningwindow;
	wxBoxSizer* boxSizer;
	void fitwindowSize();
};