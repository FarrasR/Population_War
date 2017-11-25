#pragma once 
#include "wx\wx.h" 
#include "PWFrame.h"

class SettingWindow : public wxWindow
{
public:
	SettingWindow(PWFrame *parent);
	~SettingWindow();

	void EnableKill(wxCommandEvent& event);
	void EnableSacrifice(wxCommandEvent& event);
	void BackToMainMenu(wxCommandEvent &event);



private:
	PWFrame *parent;
	wxCheckBox *killbutton;
	wxCheckBox *sacrificebutton;
	wxCheckBox *convertbutton;
	wxButton *button4;
	DECLARE_EVENT_TABLE()
};

