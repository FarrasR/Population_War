#include "WinningWindow.h"
#include <wx/stdpaths.h> 
#include <wx/filename.h> 

BEGIN_EVENT_TABLE(WinningWindow, wxWindow)
	EVT_BUTTON(3003, WinningWindow::BackToMainMenu)
END_EVENT_TABLE()



WinningWindow::WinningWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));

	wxInitAllImageHandlers();
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImageHandler *gifLoader = new wxGIFHandler();
	wxImage::AddHandler(jpgLoader);
	wxImage::AddHandler(gifLoader);
	this->parent = parent;
	this->LoadBitmap();


	back = new wxBitmapButton(this, 3003, *mainmenu, wxPoint(380, 550), wxDefaultSize, wxBORDER_NONE);
	back->SetBitmapCurrent(*mainmenuglow);

	playerwin=new wxStaticBitmap(this, wxID_ANY, *playerdraw, wxPoint(130, 175), wxDefaultSize, wxBORDER_NONE);
}


WinningWindow::~WinningWindow()
{
	delete mainmenu;
	delete mainmenuglow;
	delete back;
	delete player1win;
	delete player2win;
	delete playerdraw;
}

void WinningWindow::BackToMainMenu(wxCommandEvent & event)
{
	parent->ShowMainWindow();
}

void WinningWindow::WhoWin()
{
	if (parent->setting->yangmenang == 1)
	{
		playerwin->SetBitmap(*player1win);
	}
	else if (parent->setting->yangmenang == 2)
	{
		playerwin->SetBitmap(*player2win);
	}
	else if (parent->setting->yangmenang == 3)
	{
		playerwin->SetBitmap(*playerdraw);
	}
}

void WinningWindow::LoadBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenu.jpg");
	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenuglow.jpg");

	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\abilitybutton.jpg");
	wxString fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\convertability.jpg");
	wxString fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\cretext.jpg");


	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);
	wxImage image4(fileLocation4, wxBITMAP_TYPE_JPEG);
	wxImage image5(fileLocation5, wxBITMAP_TYPE_JPEG);

	mainmenu = new wxBitmap(image1);
	mainmenuglow = new wxBitmap(image2);
	player1win = new wxBitmap(image3);
	player2win = new wxBitmap(image4);
	playerdraw = new wxBitmap(image5);
}
