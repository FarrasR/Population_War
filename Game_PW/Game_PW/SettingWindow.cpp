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
	EVT_BUTTON(2006, SettingWindow::AbilityMenu)
	EVT_BUTTON(2007, SettingWindow::CellMenu)
	EVT_BUTTON(2008, SettingWindow::NextColor1)
	EVT_BUTTON(2009, SettingWindow::NextColor2)
	EVT_BUTTON(2010, SettingWindow::EnableSound)
END_EVENT_TABLE()


SettingWindow::SettingWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	wxInitAllImageHandlers();
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(jpgLoader);
	wxImage::AddHandler(pngLoader);
	this->LoadBitmap();
	this->parent = parent;

	buttonkill = new wxBitmapButton(this, 2001, *checkboxfalse, wxPoint(360, 215), wxDefaultSize, wxBORDER_NONE);
	buttonconvert = new wxBitmapButton(this, 2002, *checkboxfalse, wxPoint(360, 267), wxDefaultSize, wxBORDER_NONE);
	buttonsacrifice = new wxBitmapButton(this, 2003, *checkboxfalse, wxPoint(360, 319), wxDefaultSize, wxBORDER_NONE);
	buttonrelocate = new wxBitmapButton(this, 2004, *checkboxfalse, wxPoint(360, 371), wxDefaultSize, wxBORDER_NONE);
	menutextstatic = new wxStaticBitmap(this, wxID_ANY, *abilitytext, wxPoint(130, 175), wxDefaultSize, wxBORDER_NONE);
	
	buttonnextcolor1 = new wxBitmapButton(this, 2008, *nextcolor, wxPoint(357, 259), wxDefaultSize, wxBORDER_NONE);
	buttonnextcolor2 = new wxBitmapButton(this, 2009, *nextcolor, wxPoint(357, 348), wxDefaultSize, wxBORDER_NONE);
	
	player1color = new wxStaticBitmap(this, wxID_ANY, *cellbluecolor, wxPoint(295, 258), wxDefaultSize, wxBORDER_NONE);
	player2color = new wxStaticBitmap(this, wxID_ANY, *cellredcolor, wxPoint(295, 344), wxDefaultSize, wxBORDER_NONE);

	buttonmainmenu = new wxBitmapButton(this, 2005, *mainmenu, wxPoint(550, 400), wxDefaultSize, wxBORDER_NONE);
	buttonmainmenu->SetBitmapCurrent(*mainmenuglow);
	buttonabilitymenu = new wxBitmapButton(this, 2006, *abilitymenu, wxPoint(126, 120), wxDefaultSize, wxBORDER_NONE);
	buttonabilitymenu->SetBitmapCurrent(*abilitymenuglow);
	buttoncellmenu = new wxBitmapButton(this, 2007, *cellmenu, wxPoint(275, 120), wxDefaultSize, wxBORDER_NONE);
	buttoncellmenu->SetBitmapCurrent(*cellmenuglow);
	
	soundnow = new wxBitmapButton(this, 2010, *soundon, wxPoint(150, 500), wxDefaultSize, wxBORDER_NONE);

	buttonnextcolor1->Show(false);
	buttonnextcolor2->Show(false);
	player1color->Show(false);
	player2color->Show(false);

	this->CheckSetting();
}
SettingWindow::~SettingWindow()
{
	delete settingbox;
	delete checkboxfalse;
	delete checkboxtrue;
	delete logo;
	delete mainmenu;
	delete mainmenuglow;
	delete abilitymenu;
	delete abilitymenuglow;
	delete cellmenu;
	delete cellmenuglow;
	delete abilitytext;
	delete celltext;
	delete cellbluecolor;
	delete cellredcolor;
	delete cellyellowcolor;
	delete cellgreencolor;
	delete nextcolor;

	delete menutextstatic;
	delete player1color;
	delete player2color;
	delete buttonkill;
	delete buttonconvert;
	delete buttonsacrifice;
	delete buttonrelocate;
	delete buttonmainmenu;
	delete buttonabilitymenu;
	delete buttoncellmenu;
	delete buttonnextcolor1;
	delete buttonnextcolor2;
}

void SettingWindow::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*settingbox, wxPoint(100, 100), true);
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

void SettingWindow::EnableSound(wxCommandEvent & event)
{
	if (soundhit == 1) {

		wxStandardPaths &stdPaths = wxStandardPaths::Get();
		wxString fileLocation = stdPaths.GetExecutablePath();
		wxString filelocation1 = wxFileName(fileLocation).GetPath() + wxT("\\test.wav");

		soundhit = 0;
		PlaySound(filelocation1, NULL, SND_ASYNC);
		soundnow->SetBitmap(*soundon);
	}
	else if (soundhit == 0) {
		soundhit = 1;
		PlaySound(0,0,0);
		soundnow->SetBitmap(*soundoff);
	}
}

void SettingWindow::EnableConvert(wxCommandEvent & event)
{
	if (parent->setting->convert == true)parent->setting->convert = false;
	else parent->setting->convert = true;
	this->CheckSetting();
}

void SettingWindow::BackToMainMenu(wxCommandEvent & event)
{

	//wxMessageOutputDebug().Printf("%d %d", parent->setting->colorp1, parent->setting->colorp2);
	//return;
	if (parent->setting->colorp1 == parent->setting->colorp2)
	{
		wxString tempo;
		tempo.Printf(wxT("Player 1 Color Can't be same as Player 2"));
		int ans = wxMessageBox(tempo, "ERROR", wxOK);
	}
	else parent->ShowMainWindow();
}

void SettingWindow::AbilityMenu(wxCommandEvent & event)
{
	this->CheckSetting();
	menutextstatic->SetBitmap(*abilitytext);
	buttonnextcolor1->Show(false);
	buttonnextcolor2->Show(false);
	player1color->Show(false);
	player2color->Show(false);

	buttonkill->Show(true);
	buttonconvert->Show(true);
	buttonsacrifice->Show(true);
	buttonrelocate->Show(true);
}

void SettingWindow::CellMenu(wxCommandEvent & event)
{
	menutextstatic->SetBitmap(*celltext);
	buttonnextcolor1->Show(true);
	buttonnextcolor2->Show(true);
	this->CheckSetting();
	player1color->Show(true);
	player2color->Show(true);

	buttonkill->Show(false);
	buttonconvert->Show(false);
	buttonsacrifice->Show(false);
	buttonrelocate->Show(false);
}

void SettingWindow::NextColor1(wxCommandEvent & event)
{
	parent->setting->colorp1 = (parent->setting->colorp1) % 4 + 1;
	this->CheckSetting();
}

void SettingWindow::NextColor2(wxCommandEvent & event)
{
	parent->setting->colorp2 = (parent->setting->colorp2) % 4 + 1;
	this->CheckSetting();
}

void SettingWindow::LoadBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\settingbox.jpg");
	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\ceklisno.jpg");
	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\ceklisyes.jpg");
	wxString fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\logo.jpg");
	wxString fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenu.jpg");
	wxString fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenuglow.jpg");
	wxString fileLocation7 = wxFileName(fileLocation).GetPath() + wxT("\\abilitybutton.jpg");
	wxString fileLocation8 = wxFileName(fileLocation).GetPath() + wxT("\\abilitybuttonglow.jpg");
	wxString fileLocation9 = wxFileName(fileLocation).GetPath() + wxT("\\cellbutton.jpg");
	wxString fileLocation10 = wxFileName(fileLocation).GetPath() + wxT("\\cellbuttonglow.jpg");
	wxString fileLocation11 = wxFileName(fileLocation).GetPath() + wxT("\\abilitytext.jpg");
	wxString fileLocation12 = wxFileName(fileLocation).GetPath() + wxT("\\celltext.jpg");
	wxString fileLocation13 = wxFileName(fileLocation).GetPath() + wxT("\\bluecolorcell.jpg");
	wxString fileLocation14 = wxFileName(fileLocation).GetPath() + wxT("\\redcolorcell.jpg");
	wxString fileLocation15 = wxFileName(fileLocation).GetPath() + wxT("\\yellowcolorcell.jpg");
	wxString fileLocation16 = wxFileName(fileLocation).GetPath() + wxT("\\greencolorcell.jpg");
	wxString fileLocation17 = wxFileName(fileLocation).GetPath() + wxT("\\nextcolor.jpg");
	wxString fileLocation18 = wxFileName(fileLocation).GetPath() + wxT("\\soundon.jpg");
	wxString fileLocation19 = wxFileName(fileLocation).GetPath() + wxT("\\soundoff.jpg");

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
	wxImage image17(fileLocation17, wxBITMAP_TYPE_JPEG);
	wxImage image18(fileLocation18, wxBITMAP_TYPE_JPEG);
	wxImage image19(fileLocation19, wxBITMAP_TYPE_JPEG);

	settingbox = new wxBitmap(image1);
	checkboxfalse = new wxBitmap(image2);
	checkboxtrue = new wxBitmap(image3);
	logo = new wxBitmap(image4.Scale(300, 300));
	mainmenu = new wxBitmap(image5);
	mainmenuglow = new wxBitmap(image6);
	abilitymenu = new wxBitmap(image7);
	abilitymenuglow = new wxBitmap(image8);
	cellmenu = new wxBitmap(image9);
	cellmenuglow = new wxBitmap(image10);
	abilitytext = new wxBitmap(image11);
	celltext = new wxBitmap(image12);
	cellbluecolor = new wxBitmap(image13);
	cellredcolor = new wxBitmap(image14);
	cellyellowcolor = new wxBitmap(image15);
	cellgreencolor = new wxBitmap(image16);
	nextcolor = new wxBitmap(image17);
	soundon = new wxBitmap(image18);
	soundoff = new wxBitmap(image19);
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

	if (parent->setting->colorp1 == 1) player1color->SetBitmap(*cellbluecolor);
	else if (parent->setting->colorp1 == 2) player1color->SetBitmap(*cellredcolor);
	else if (parent->setting->colorp1 == 3) player1color->SetBitmap(*cellyellowcolor);
	else if (parent->setting->colorp1 == 4) player1color->SetBitmap(*cellgreencolor);

	if (parent->setting->colorp2 == 1) player2color->SetBitmap(*cellbluecolor);
	else if (parent->setting->colorp2 == 2) player2color->SetBitmap(*cellredcolor);
	else if (parent->setting->colorp2 == 3) player2color->SetBitmap(*cellyellowcolor);
	else if (parent->setting->colorp2 == 4) player2color->SetBitmap(*cellgreencolor);
}


