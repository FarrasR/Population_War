#include "SettingWindow.h"
#include <wx/stdpaths.h> 
#include <wx/filename.h>

BEGIN_EVENT_TABLE(SettingWindow, wxWindow)
	EVT_PAINT(SettingWindow::OnPaint)
	EVT_BUTTON(2001, SettingWindow::EnableKill)
	EVT_BUTTON(2002, SettingWindow::EnableConvert)
	EVT_BUTTON(2003, SettingWindow::EnableSacrifice)
	EVT_BUTTON(2004, SettingWindow::EnableRelocate)
	EVT_BUTTON(2005, SettingWindow::BackToMainMenu)
END_EVENT_TABLE()


SettingWindow::SettingWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	wxInitAllImageHandlers();
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpgLoader);
	this->LoadBitmap();
	this->parent = parent;

	buttonkill = new wxBitmapButton(this, 2001, *checkboxfalse, wxPoint(360, 215), wxDefaultSize, wxBORDER_NONE);
	buttonconvert = new wxBitmapButton(this, 2002, *checkboxfalse, wxPoint(360, 265), wxDefaultSize, wxBORDER_NONE);
	buttonsacrifice = new wxBitmapButton(this, 2003, *checkboxfalse, wxPoint(360, 315), wxDefaultSize, wxBORDER_NONE);
	buttonrelocate = new wxBitmapButton(this, 2004, *checkboxfalse, wxPoint(360, 365), wxDefaultSize, wxBORDER_NONE);
	
	this->CheckSetting();
}


SettingWindow::~SettingWindow()
{
	delete abilitybox;
	delete checkboxfalse;
	delete checkboxtrue;
	delete logo;
	delete buttonkill;
	delete buttonconvert;
	delete buttonsacrifice;
	delete buttonrelocate;
}

void SettingWindow::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*abilitybox, wxPoint(100, 100), true);
	pdc.DrawBitmap(*logo, wxPoint(500, 100), true);
}

void SettingWindow::EnableKill(wxCommandEvent & event)
{
	if (parent->setting->kill == true)parent->setting->kill = false;
	else parent->setting->kill = true;
	this->CheckSetting();
}

void SettingWindow::EnableSacrifice(wxCommandEvent & event)
{
	if (parent->setting->sacrifice == true)parent->setting->sacrifice = false;
	else parent->setting->sacrifice = true;
	this->CheckSetting();
}

void SettingWindow::EnableRelocate(wxCommandEvent & event)
{
	if (parent->setting->relocate == true)parent->setting->relocate = false;
	else parent->setting->relocate = true;
	this->CheckSetting();
}

void SettingWindow::EnableConvert(wxCommandEvent & event)
{
	if (parent->setting->convert == true)parent->setting->convert = false;
	else parent->setting->convert = true;
	this->CheckSetting();
}

void SettingWindow::BackToMainMenu(wxCommandEvent & event)
{
	parent->ShowMainWindow();
}

void SettingWindow::LoadBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\abilitybox.jpg");
	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\ceklisno.jpg");
	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\ceklisyes.jpg");
	wxString fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\logo.jpg");

	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);
	wxImage image4(fileLocation4, wxBITMAP_TYPE_JPEG);

	abilitybox = new wxBitmap(image1);
	checkboxfalse = new wxBitmap(image2);
	checkboxtrue = new wxBitmap(image3);
	logo = new wxBitmap(image4.Scale(300, 300));

}

void SettingWindow::CheckSetting()
{
	if (parent->setting->kill == true)buttonkill->SetBitmap(*checkboxtrue);
	else buttonkill->SetBitmap(*checkboxfalse);

	if (parent->setting->sacrifice == true)buttonsacrifice->SetBitmap(*checkboxtrue);
	else buttonsacrifice->SetBitmap(*checkboxfalse);

	if (parent->setting->convert == true)buttonconvert->SetBitmap(*checkboxtrue);
	else buttonconvert->SetBitmap(*checkboxfalse);

	if (parent->setting->relocate == true)buttonrelocate->SetBitmap(*checkboxtrue);
	else buttonrelocate->SetBitmap(*checkboxfalse);
}


