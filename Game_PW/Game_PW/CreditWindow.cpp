#include "CreditWindow.h"
#include <wx/stdpaths.h> 
#include <wx/filename.h>

BEGIN_EVENT_TABLE(CreditWindow, wxWindow)
	EVT_BUTTON(1031, CreditWindow::BackToMainMenu)
END_EVENT_TABLE()


CreditWindow::CreditWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->parent = parent;
	this->LoadBitmap();

	buttonmainmenu = new wxBitmapButton(this, 1031, *mainmenu, wxPoint(380, 500), wxDefaultSize, wxBORDER_NONE);
	buttonmainmenu->SetBitmapCurrent(*mainmenuglow);
}


CreditWindow::~CreditWindow()
{
	delete mainmenu;
	delete mainmenuglow;

	delete buttonmainmenu;
}

void CreditWindow::BackToMainMenu(wxCommandEvent &event)
{
	parent->ShowMainWindow();
}

void CreditWindow::LoadBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenu.jpg");
	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenuglow.jpg");

	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);

	mainmenu = new wxBitmap(image1);
	mainmenuglow = new wxBitmap(image2);
}
