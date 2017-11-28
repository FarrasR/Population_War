#include "HTPWindow.h"
#include <wx/stdpaths.h> 
#include <wx/filename.h> 

BEGIN_EVENT_TABLE(HTPWindow, wxWindow)
	EVT_PAINT(HTPWindow::OnPaint)
	EVT_BUTTON(3001, HTPWindow::NextPage)
	EVT_BUTTON(3002, HTPWindow::PreviousPage)
	EVT_BUTTON(3003, HTPWindow::BackToMainMenu)
END_EVENT_TABLE()

HTPWindow::HTPWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->parent = parent;
	this->LoadBitmap();
	page = 1;

	nextbutton = new wxButton(this, 3001, wxT("NextPage"), wxPoint(800, 400), wxDefaultSize, 0, wxDefaultValidator, wxT("killemall"));
	Previousbutton = new wxButton(this, 3002, wxT("PreviousPage"), wxPoint(100, 400), wxDefaultSize, 0, wxDefaultValidator, wxT("killemall"));
	
	back= new wxBitmapButton(this, 3003, *mainmenu, wxPoint(380, 500), wxDefaultSize, wxBORDER_NONE);
	back->SetBitmapCurrent(*mainmenuglow);

	CheckPage();
}


HTPWindow::~HTPWindow()
{
	delete nextbutton;
	delete Previousbutton;
	delete back;
	delete mainmenu;
	delete mainmenuglow;
	delete howtoplay;
}

void HTPWindow::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*howtoplay, wxPoint(290, 10), true);
}

void HTPWindow::NextPage(wxCommandEvent & event)
{
	this->page += 1;
	CheckPage();
}

void HTPWindow::PreviousPage(wxCommandEvent & event)
{
	this->page -= 1;
	CheckPage();
}

void HTPWindow::BackToMainMenu(wxCommandEvent & event)
{
	parent->ShowMainWindow();
}

void HTPWindow::CheckPage()
{
	if(page==1)Previousbutton->Show(false);
	else Previousbutton->Show(true);
	Refresh();
}

void HTPWindow::LoadBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenu.jpg");
	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenuglow.jpg");
	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\htpmenu.jpg");

	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);

	mainmenu = new wxBitmap(image1);
	mainmenuglow = new wxBitmap(image2);
	howtoplay = new wxBitmap(image3);
}
