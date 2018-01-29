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

	back = new wxBitmapButton(this, 3003, *mainmenu, wxPoint(407.5, 550), wxDefaultSize, wxBORDER_NONE);
	back->SetBitmapCurrent(*mainmenuglow);

	playerwin = new wxStaticBitmap(this, wxID_ANY, *playerdraw, wxPoint(200, 175), wxDefaultSize, wxBORDER_NONE);
	congratsstatic = new wxStaticBitmap(this, wxID_ANY, *congrats, wxPoint(200, 100), wxDefaultSize, wxBORDER_NONE);
}


WinningWindow::~WinningWindow()
{
	delete mainmenu;
	delete mainmenuglow;
	delete back;
	delete player1win;
	delete player2win;
	delete playerdraw;
	delete congrats;
	delete congratsstatic;
}

void WinningWindow::BackToMainMenu(wxCommandEvent & event)
{
	parent->ShowMainWindow();
}

void WinningWindow::WhoWin()
{

	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	delete p1char;
	delete p2char;
	delete playercharwin;

	wxString fileLocation6;
	wxString fileLocation7;

	if (parent->setting->colorp1 == 1)
		fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\charblue.jpg");
	else if (parent->setting->colorp1 == 2)
		fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\charred.jpg");
	else if (parent->setting->colorp1 == 3)
		fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\charyellow.jpg");
	else if (parent->setting->colorp1 == 4)
		fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\chargreen.jpg");

	if (parent->setting->colorp2 == 1)
		fileLocation7 = wxFileName(fileLocation).GetPath() + wxT("\\charblue.jpg");
	else if (parent->setting->colorp2 == 2)
		fileLocation7 = wxFileName(fileLocation).GetPath() + wxT("\\charred.jpg");
	else if (parent->setting->colorp2 == 3)
		fileLocation7 = wxFileName(fileLocation).GetPath() + wxT("\\charyellow.jpg");
	else if (parent->setting->colorp2 == 4)
		fileLocation7 = wxFileName(fileLocation).GetPath() + wxT("\\chargreen.jpg");
	
	wxImage image6(fileLocation6, wxBITMAP_TYPE_JPEG);
	wxImage image7(fileLocation7, wxBITMAP_TYPE_JPEG);

	p1char = new wxBitmap(image6.Scale(250, 250));
	p2char = new wxBitmap(image7.Scale(250, 250));

	playercharwin = new wxStaticBitmap(this, wxID_ANY, *p1char, wxPoint(375.5, 270), wxDefaultSize, wxBORDER_NONE);

	if (parent->setting->yangmenang == 1)
	{
		playerwin->SetBitmap(*player1win);
		playercharwin->SetBitmap(*p1char);
	}
	else if (parent->setting->yangmenang == 2)
	{
		playerwin->SetBitmap(*player2win);
		playercharwin->SetBitmap(*p2char);
	}
	else if (parent->setting->yangmenang == 3)
	{
		playerwin->SetBitmap(*playerdraw);
		playercharwin->Show(false);
	}
}

void WinningWindow::LoadBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenu.jpg");
	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenuglow.jpg");

	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\player1win.jpg");
	wxString fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\player2win.jpg");
	wxString fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\draw.jpg");

	wxString fileLocation8 = wxFileName(fileLocation).GetPath() + wxT("\\congratz.jpg");

	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);
	wxImage image4(fileLocation4, wxBITMAP_TYPE_JPEG);
	wxImage image5(fileLocation5, wxBITMAP_TYPE_JPEG);
	wxImage image8(fileLocation8, wxBITMAP_TYPE_JPEG);

	mainmenu = new wxBitmap(image1);
	mainmenuglow = new wxBitmap(image2);
	player1win = new wxBitmap(image3);
	player2win = new wxBitmap(image4);
	playerdraw = new wxBitmap(image5);
	congrats = new wxBitmap(image8);
}
