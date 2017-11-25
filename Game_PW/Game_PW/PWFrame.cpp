#include "PWFrame.h" 
#include "PWWindow.h" 
#include "SettingWindow.h"
#include "HTPWindow.h"
#include "CreditWindow.h"

PWFrame::PWFrame(const wxString &title) : wxFrame(NULL, wxID_ANY, title) {
	setting = new Setting;
	//this->mainwindow = new PWWindow(this);
	this->creditwindow = new CreditWindow(this);
	//this->settingwindow = new SettingWindow(this);
	//this->howtoplaywindow = new HTPWindow(this);

	this->SetInitialSize(wxSize(1000, 700));
}