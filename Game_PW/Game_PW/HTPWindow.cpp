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

	scrollnextbutton = new wxBitmapButton(this, 3001, *scrollnext, wxPoint(800, 300), wxDefaultSize, wxBORDER_NONE);
	scrollnextbutton->SetBitmapCurrent(*scrollnextglow);

	scrollprevbutton = new wxBitmapButton(this, 3002, *scrollprev, wxPoint(100, 300), wxDefaultSize, wxBORDER_NONE);
	scrollprevbutton->SetBitmapCurrent(*scrollprevglow);

	back= new wxBitmapButton(this, 3003, *mainmenu, wxPoint(380, 500), wxDefaultSize, wxBORDER_NONE);
	back->SetBitmapCurrent(*mainmenuglow);

	CheckPage();
}


HTPWindow::~HTPWindow()
{
	delete scrollnextbutton;
	delete scrollprevbutton;
	delete scrollnext;
	delete scrollnextglow;
	delete scrollprev;
	delete scrollprevglow;
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
	if (page <= 1) {
		scrollnextbutton->Show(true);
		scrollprevbutton->Show(false);
	}
	else {
		scrollprevbutton->Show(true);
		scrollnextbutton->Show(true);
	}
	Refresh();
}

void HTPWindow::LoadBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenu.jpg");
	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenuglow.jpg");
	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\htpmenu.jpg");
	wxString fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\scrollnext.jpg");
	wxString fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\scrollnextglow.jpg");
	wxString fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\scrollprev.jpg");
	wxString fileLocation7 = wxFileName(fileLocation).GetPath() + wxT("\\scrollprevglow.jpg");

	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);
	wxImage image4(fileLocation4, wxBITMAP_TYPE_JPEG);
	wxImage image5(fileLocation5, wxBITMAP_TYPE_JPEG);
	wxImage image6(fileLocation6, wxBITMAP_TYPE_JPEG);
	wxImage image7(fileLocation7, wxBITMAP_TYPE_JPEG);

	mainmenu = new wxBitmap(image1);
	mainmenuglow = new wxBitmap(image2);
	howtoplay = new wxBitmap(image3);
	scrollnext = new wxBitmap(image4);
	scrollnextglow = new wxBitmap(image5);
	scrollprev = new wxBitmap(image6);
	scrollprevglow = new wxBitmap(image7);
}
