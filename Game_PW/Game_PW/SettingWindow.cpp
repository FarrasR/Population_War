#include "SettingWindow.h"

BEGIN_EVENT_TABLE(SettingWindow, wxWindow)
	EVT_CHECKBOX(2001, SettingWindow::EnableKill)
	EVT_CHECKBOX(2002, SettingWindow::EnableSacrifice)
	EVT_BUTTON(2004, SettingWindow::BackToMainMenu)
END_EVENT_TABLE()


SettingWindow::SettingWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	this->parent = parent;
	
	killbutton = new wxCheckBox(this, 2001, wxT("Enable Kill"), wxPoint(300, 300), wxDefaultSize, 0, wxDefaultValidator, wxT("yo man"));
	sacrificebutton = new wxCheckBox(this, 2002, wxT("Enable Sacrifice"), wxPoint(300, 325), wxDefaultSize, 0, wxDefaultValidator, wxT("yo man"));
	convertbutton = new wxCheckBox(this, 2003, wxT("Enable Convert"), wxPoint(300, 350), wxDefaultSize, 0, wxDefaultValidator, wxT("yo man"));

	button4 = new wxButton(this, 2004, wxT("Back To Main Menu"), wxPoint(300, 400), wxDefaultSize, 0, wxDefaultValidator, wxT("killemall"));

	killbutton->SetValue(this->parent->setting->kill);
	sacrificebutton->SetValue(this->parent->setting->sacrifice);
	convertbutton->SetValue(this->parent->setting->convert);
}


SettingWindow::~SettingWindow()
{

}

void SettingWindow::EnableKill(wxCommandEvent & event)
{

}

void SettingWindow::EnableSacrifice(wxCommandEvent & event)
{

}

void SettingWindow::BackToMainMenu(wxCommandEvent & event)
{
	parent->setting->kill = killbutton->GetValue();
	parent->setting->sacrifice = sacrificebutton->GetValue();
	parent->setting->convert = convertbutton->GetValue();
}
