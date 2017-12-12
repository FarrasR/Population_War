#include "PWWindow.h" 
#include <wx/stdpaths.h> 
#include <wx/filename.h> 

BEGIN_EVENT_TABLE(PWWindow, wxWindow)
	EVT_PAINT(PWWindow::OnPaint)
	EVT_BUTTON(1001, PWWindow::ClickPlay)//click play id
	EVT_BUTTON(1002, PWWindow::ClickSetting)
	EVT_BUTTON(1003, PWWindow::ClickHTP)
	EVT_BUTTON(1004, PWWindow::ClickCredit)
END_EVENT_TABLE()

PWWindow::PWWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY) {
	this->SetBackgroundColour(wxColour(*wxBLACK));
	wxInitAllImageHandlers();
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpgLoader);
	this->LoadMainBitmap();
	this->parent = parent;

	button1 = new wxBitmapButton(this, 1001, *playbutton, wxPoint(425, 350), wxDefaultSize, wxBORDER_NONE);
	button2 = new wxBitmapButton(this, 1002, *settingbutton, wxPoint(207.5, 530), wxDefaultSize, wxBORDER_NONE);
	button3 = new wxBitmapButton(this, 1003, *htpbutton, wxPoint(407.5, 530), wxDefaultSize, wxBORDER_NONE);
	button4 = new wxBitmapButton(this, 1004, *creditbutton, wxPoint(607.5, 530), wxDefaultSize, wxBORDER_NONE);
	
	button4->SetBitmapCurrent(*creditbuttonglow);
	button3->SetBitmapCurrent(*htpbuttonglow);
	button2->SetBitmapCurrent(*settingbuttonglow);
	button1->SetBitmapCurrent(*playbuttonglow);
}

PWWindow::~PWWindow() {
	delete newbackground;
	delete playbutton;
	delete settingbutton;
	delete htpbutton;
	delete creditbutton;
	delete playbuttonglow;
	delete settingbuttonglow;
	delete htpbuttonglow;
	delete creditbuttonglow;

	delete button1;
	delete button2;
	delete button3;
	delete button4;
}

void PWWindow::LoadMainBitmap() {
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\play.jpg");
	wxString fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\settext.jpg");
	wxString fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\htptext.jpg");
	wxString fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\cretext.jpg");
	wxString fileLocation7 = wxFileName(fileLocation).GetPath() + wxT("\\cretextglow.jpg");
	wxString fileLocation8 = wxFileName(fileLocation).GetPath() + wxT("\\htptextglow.jpg");
	wxString fileLocation9 = wxFileName(fileLocation).GetPath() + wxT("\\settextglow.jpg");
	wxString fileLocation10 = wxFileName(fileLocation).GetPath() + wxT("\\playglow.jpg");
	wxString fileLocation11 = wxFileName(fileLocation).GetPath() + wxT("\\backgroundpw.jpg");
	
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);
	wxImage image4(fileLocation4, wxBITMAP_TYPE_JPEG);
	wxImage image5(fileLocation5, wxBITMAP_TYPE_JPEG);
	wxImage image6(fileLocation6, wxBITMAP_TYPE_JPEG);
	wxImage image7(fileLocation7, wxBITMAP_TYPE_JPEG);
	wxImage image8(fileLocation8, wxBITMAP_TYPE_JPEG);
	wxImage image9(fileLocation9, wxBITMAP_TYPE_JPEG);
	wxImage image10(fileLocation10, wxBITMAP_TYPE_JPEG);
	wxImage image11(fileLocation11, wxBITMAP_TYPE_JPEG);

	playbutton = new wxBitmap(image3);
	playbuttonglow = new wxBitmap(image10);
	settingbutton = new wxBitmap(image4);
	settingbuttonglow = new wxBitmap(image9);
	htpbutton = new wxBitmap(image5);
	htpbuttonglow = new wxBitmap(image8);
	creditbutton = new wxBitmap(image6);
	creditbuttonglow = new wxBitmap(image7);
	newbackground = new wxBitmap(image11);
}

void PWWindow::OnPaint(wxPaintEvent &event) {
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*newbackground, wxPoint(-10, 0), true);
}

void PWWindow::ClickPlay(wxCommandEvent & event){
	parent->ShowBoardWindow();
}

void PWWindow::ClickSetting(wxCommandEvent & event)
{
	parent->ShowSettingWindow();
}

void PWWindow::ClickHTP(wxCommandEvent & event)
{
	parent->ShowHTPWindow();
}

void PWWindow::ClickCredit(wxCommandEvent & event)
{
	parent->ShowCreditWindow();
}
