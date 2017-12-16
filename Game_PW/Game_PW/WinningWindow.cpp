#include "WinningWindow.h"
#include <wx/stdpaths.h> 
#include <wx/filename.h> 

BEGIN_EVENT_TABLE(WinningWindow, wxWindow)
	EVT_BUTTON(3003, WinningWindow::BackToMainMenu)

END_EVENT_TABLE()



WinningWindow::WinningWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxGREEN));
	this->parent = parent;
	this->LoadBitmap();


	back = new wxBitmapButton(this, 3003, *mainmenu, wxPoint(380, 550), wxDefaultSize, wxBORDER_NONE);
	back->SetBitmapCurrent(*mainmenuglow);

}


WinningWindow::~WinningWindow()
{
	delete mainmenu;
	delete mainmenuglow;
	delete back;
}

void WinningWindow::BackToMainMenu(wxCommandEvent & event)
{
	parent->ShowMainWindow();
}

void WinningWindow::LoadBitmap()
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
