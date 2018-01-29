#include "CreditWindow.h"
#include <wx/stdpaths.h> 
#include <wx/filename.h>

BEGIN_EVENT_TABLE(CreditWindow, wxWindow)
	EVT_TIMER(1032, CreditWindow::OnTimer)
	EVT_BUTTON(1031, CreditWindow::BackToMainMenu)
END_EVENT_TABLE()


CreditWindow::CreditWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	wxInitAllImageHandlers();
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpgLoader);
	this->parent = parent;
	this->LoadBitmap();

	buttonmainmenu = new wxBitmapButton(this, 1031, *mainmenu, wxPoint(400, 590), wxDefaultSize, wxBORDER_NONE);
	buttonmainmenu->SetBitmapCurrent(*mainmenuglow);
	newbg = new wxStaticBitmap(this, wxID_ANY, *creditsbg, wxPoint(-10, -15), wxDefaultSize, wxBORDER_NONE);

	timer = new wxTimer(this, 1032);
	timer->Start(2000);
}


CreditWindow::~CreditWindow()
{
	delete mainmenu;
	delete mainmenuglow;
	delete creditsbg;
	delete creditsbg2;
	delete buttonmainmenu;

	timer->Stop();
	delete timer;
}

void CreditWindow::BackToMainMenu(wxCommandEvent &event)
{
	parent->ShowMainWindow();
}

void CreditWindow::OnTimer(wxTimerEvent & event)
{
	if (this->hit == 0) this->hit = 1;
	else this->hit = 0;

	if (this->hit == 0) newbg->SetBitmap(*creditsbg);
	else newbg->SetBitmap(*creditsbg2);
}

void CreditWindow::LoadBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenu.jpg");
	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenuglow.jpg");
	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\credits.jpg");
	wxString fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\credits2.jpg");

	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);
	wxImage image4(fileLocation4, wxBITMAP_TYPE_JPEG);

	mainmenu = new wxBitmap(image1);
	mainmenuglow = new wxBitmap(image2);
	creditsbg = new wxBitmap(image3);
	creditsbg2 = new wxBitmap(image4);
}
