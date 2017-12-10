#include "PWFrame.h" 
#include "PWWindow.h" 
#include "SettingWindow.h"
#include "HTPWindow.h"
#include "CreditWindow.h"
#include "BoardWindow.h"

PWFrame::PWFrame(const wxString &title) : wxFrame(NULL, wxID_ANY, title)
{
	setting = new Setting;
	this->InitComponents();
}

PWFrame::~PWFrame()
{
	delete setting;
}

void PWFrame::InitComponents()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);

	this->mainwindow=new PWWindow(this);
	this->mainwindow->Show(false);
	this->boxSizer->Add(mainwindow, 1, wxEXPAND, 0);

	this->boardwindow = new BoardWindow(this);
	this->boardwindow->Show(false);
	this->boxSizer->Add(boardwindow, 1, wxEXPAND, 0);

	this->settingwindow = new SettingWindow(this);
	this->settingwindow->Show(false);
	this->boxSizer->Add(settingwindow, 1, wxEXPAND, 0);

	this->howtoplaywindow = new HTPWindow(this);
	this->howtoplaywindow->Show(false);
	this->boxSizer->Add(howtoplaywindow, 1, wxEXPAND, 0);

	this->creditwindow = new CreditWindow(this);
	this->creditwindow->Show(false);
	this->boxSizer->Add(creditwindow, 1, wxEXPAND, 0);

	SetSizer(boxSizer);
	ShowMainWindow();
}

void PWFrame::ShowMainWindow()
{
	this->mainwindow->Show(true);
	this->settingwindow->Show(false);
	this->howtoplaywindow->Show(false);
	this->creditwindow->Show(false);
	this->boardwindow->Show(false);

	this->fitwindowSize();
}

void PWFrame::ShowSettingWindow()
{
	this->mainwindow->Show(false);
	this->settingwindow->Show(true);
	this->howtoplaywindow->Show(false);
	this->creditwindow->Show(false);
	this->boardwindow->Show(false);

	this->fitwindowSize();
}

void PWFrame::ShowBoardWindow()
{
	this->boardwindow->StartGame();

	this->mainwindow->Show(false);
	this->settingwindow->Show(false);
	this->howtoplaywindow->Show(false);
	this->creditwindow->Show(false);
	this->boardwindow->Show(true);

	this->fitwindowSize();
}

void PWFrame::ShowHTPWindow()
{
	this->mainwindow->Show(false);
	this->settingwindow->Show(false);
	this->howtoplaywindow->Show(true);
	this->creditwindow->Show(false);
	this->boardwindow->Show(false);

	this->fitwindowSize();
}

void PWFrame::ShowCreditWindow()
{
	this->mainwindow->Show(false);
	this->settingwindow->Show(false);
	this->howtoplaywindow->Show(false);
	this->creditwindow->Show(true);
	this->boardwindow->Show(false);

	this->fitwindowSize();
}

void PWFrame::fitwindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(1000, 700));
	this->Layout();
}
