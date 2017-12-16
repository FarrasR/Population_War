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
	scrollprevbutton = new wxBitmapButton(this, 3002, *scrollprev, wxPoint(100, 300), wxDefaultSize, wxBORDER_NONE);
	back = new wxBitmapButton(this, 3003, *mainmenu, wxPoint(380, 550), wxDefaultSize, wxBORDER_NONE);

	htptextstatic = new wxStaticBitmap(this, wxID_ANY, *htppage1, wxPoint(270, 100), wxDefaultSize, wxBORDER_NONE);
	
	back->SetBitmapCurrent(*mainmenuglow);
	scrollnextbutton->SetBitmapCurrent(*scrollnextglow);
	scrollprevbutton->SetBitmapCurrent(*scrollprevglow);
	CheckPage();
}


HTPWindow::~HTPWindow()
{
	delete mainmenu;
	delete mainmenuglow;
	delete howtoplay;
	delete scrollnext;
	delete scrollprev;
	delete scrollnextglow;
	delete scrollprevglow;
	delete htppage1;
	delete htppage2;
	delete htppage3;
	delete htppage4;
	delete htppage5;
	delete htppage6;
	delete htppage7;
	delete htppage8;
	delete htppage9;

	delete htptextstatic;
	delete back;
	delete scrollnextbutton;
	delete scrollprevbutton;

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
	else if (page >= 9) {
		scrollnextbutton->Show(false);
		scrollprevbutton->Show(true);
	}
	else {
		scrollprevbutton->Show(true);
		scrollnextbutton->Show(true);
	}

	if (page == 1) htptextstatic->SetBitmap(*htppage1);
	else if (page == 2) htptextstatic->SetBitmap(*htppage2);
	else if (page == 3) htptextstatic->SetBitmap(*htppage3);
	else if (page == 4) htptextstatic->SetBitmap(*htppage4);
	else if (page == 5) htptextstatic->SetBitmap(*htppage5);
	else if (page == 6) htptextstatic->SetBitmap(*htppage6);
	else if (page == 7) htptextstatic->SetBitmap(*htppage7);
	else if (page == 8) htptextstatic->SetBitmap(*htppage8);
	else if (page == 9) htptextstatic->SetBitmap(*htppage9);

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
	wxString fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\scrollprev.jpg");
	wxString fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\scrollnextglow.jpg");
	wxString fileLocation7 = wxFileName(fileLocation).GetPath() + wxT("\\scrollprevglow.jpg");
	wxString fileLocation8 = wxFileName(fileLocation).GetPath() + wxT("\\htppage1.jpg");
	wxString fileLocation9 = wxFileName(fileLocation).GetPath() + wxT("\\htppage2.jpg");
	wxString fileLocation10 = wxFileName(fileLocation).GetPath() + wxT("\\htppage3.jpg");
	wxString fileLocation11 = wxFileName(fileLocation).GetPath() + wxT("\\htppage4.jpg");
	wxString fileLocation12 = wxFileName(fileLocation).GetPath() + wxT("\\htppage5.jpg");
	wxString fileLocation13 = wxFileName(fileLocation).GetPath() + wxT("\\htppage6.jpg");
	wxString fileLocation14 = wxFileName(fileLocation).GetPath() + wxT("\\htppage7.jpg");
	wxString fileLocation15 = wxFileName(fileLocation).GetPath() + wxT("\\htppage8.jpg");
	wxString fileLocation16 = wxFileName(fileLocation).GetPath() + wxT("\\htppage9.jpg");

	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);
	wxImage image4(fileLocation4, wxBITMAP_TYPE_JPEG);
	wxImage image5(fileLocation5, wxBITMAP_TYPE_JPEG);
	wxImage image6(fileLocation6, wxBITMAP_TYPE_JPEG);
	wxImage image7(fileLocation7, wxBITMAP_TYPE_JPEG);
	wxImage image8(fileLocation8, wxBITMAP_TYPE_JPEG);
	wxImage image9(fileLocation9, wxBITMAP_TYPE_JPEG);
	wxImage image10(fileLocation10, wxBITMAP_TYPE_JPEG);
	wxImage image11(fileLocation11, wxBITMAP_TYPE_JPEG);
	wxImage image12(fileLocation12, wxBITMAP_TYPE_JPEG);
	wxImage image13(fileLocation13, wxBITMAP_TYPE_JPEG);
	wxImage image14(fileLocation14, wxBITMAP_TYPE_JPEG);
	wxImage image15(fileLocation15, wxBITMAP_TYPE_JPEG);
	wxImage image16(fileLocation16, wxBITMAP_TYPE_JPEG);

	mainmenu = new wxBitmap(image1);
	mainmenuglow = new wxBitmap(image2);
	howtoplay = new wxBitmap(image3);
	scrollnext = new wxBitmap(image4);
	scrollprev = new wxBitmap(image5);
	scrollnextglow = new wxBitmap(image6);
	scrollprevglow = new wxBitmap(image7);
	htppage1 = new wxBitmap(image8.Scale(450, 450));
	htppage2 = new wxBitmap(image9.Scale(450, 450));
	htppage3 = new wxBitmap(image10.Scale(450, 450));
	htppage4 = new wxBitmap(image11.Scale(450, 450));
	htppage5 = new wxBitmap(image12.Scale(450, 450));
	htppage6 = new wxBitmap(image13.Scale(450, 450));
	htppage7 = new wxBitmap(image14.Scale(450, 450));
	htppage8 = new wxBitmap(image15.Scale(450, 450));
	htppage9 = new wxBitmap(image16.Scale(450, 450));
}
