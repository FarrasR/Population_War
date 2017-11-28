#include "SettingWindow.h"
#include <wx/stdpaths.h> 
#include <wx/filename.h>

BEGIN_EVENT_TABLE(SettingWindow, wxWindow)
	EVT_PAINT(SettingWindow::OnPaint)
	EVT_CHECKBOX(2001, SettingWindow::EnableKill)
	EVT_CHECKBOX(2002, SettingWindow::EnableSacrifice)
	EVT_BUTTON(2004, SettingWindow::BackToMainMenu)
END_EVENT_TABLE()


SettingWindow::SettingWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	wxInitAllImageHandlers();
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpgLoader);
	this->LoadBitmap();
	this->parent = parent;



}


SettingWindow::~SettingWindow()
{

}

void SettingWindow::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*abilitybox, wxPoint(100, 100), true);
}

void SettingWindow::EnableKill(wxCommandEvent & event)
{

}

void SettingWindow::EnableSacrifice(wxCommandEvent & event)
{

}

void SettingWindow::BackToMainMenu(wxCommandEvent & event)
{
	//parent->setting->kill = killbutton->GetValue();
	//parent->setting->sacrifice = sacrificebutton->GetValue();
	//parent->setting->convert = convertbutton->GetValue();

	parent->ShowMainWindow();
}

void SettingWindow::LoadBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\abilitybox.jpg");
	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\ceklisno.jpg");
	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\ceklisyes.jpg");

	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);

	abilitybox = new wxBitmap(image1);
	checkboxfalse = new wxBitmap(image2);
	checkboxtrue = new wxBitmap(image3);

}


