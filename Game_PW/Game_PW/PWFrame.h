#pragma once 
#include "wx\wx.h" 
#include "Setting.h"
class PWWindow;
class SettingWindow;
class HTPWindow;
class CreditWindow;

class PWFrame : public wxFrame {
public:
	PWFrame(const wxString &title);

	Setting *setting;
	void InitComponents();
	void ShowMainWindow();
	void ShowSettingWindow();
	void ShowHTPWindow();
	void ShowCreditWindow();

private:
	PWWindow *mainwindow;
	SettingWindow *settingwindow;
	HTPWindow *howtoplaywindow;
	CreditWindow *creditwindow;

	wxBoxSizer* boxSizer;
	void fitwindowSize();
};