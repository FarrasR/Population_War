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

	button1 = new wxBitmapButton(this, 1001, *playbutton, wxPoint(380, 420), wxDefaultSize, wxBORDER_NONE);
	button2 = new wxBitmapButton(this, 1002, *settingbutton, wxPoint(200, 530), wxDefaultSize, wxBORDER_NONE);
	button3 = new wxBitmapButton(this, 1003, *htpbutton, wxPoint(400, 530), wxDefaultSize, wxBORDER_NONE);
	button4 = new wxBitmapButton(this, 1004, *creditbutton, wxPoint(600, 530), wxDefaultSize, wxBORDER_NONE);
	//button5 = new wxBitmapButton(this, 1005, *playbuttonglow, wxPoint(380, 420), wxDefaultSize, wxBORDER_NONE);
	//button6 = new wxBitmapButton(this, 1006, *settingbuttonglow, wxPoint(200, 530), wxDefaultSize, wxBORDER_NONE);
	//button7 = new wxBitmapButton(this, 1007, *htpbuttonglow, wxPoint(400, 530), wxDefaultSize, wxBORDER_NONE);
	//button8 = new wxBitmapButton(this, 1008, *creditbuttonglow, wxPoint(600, 530), wxDefaultSize, wxBORDER_NONE);
	
	button4->SetBitmapCurrent(*creditbuttonglow);
	button3->SetBitmapCurrent(*htpbuttonglow);
	button2->SetBitmapCurrent(*settingbuttonglow);
	button1->SetBitmapCurrent(*playbuttonglow);
}

PWWindow::~PWWindow() {
	delete logoBitmap;
	delete textpwBitmap;
	delete playbutton;
	delete htpbutton;
	delete settingbutton;
	delete creditbutton;
	delete button1;
	delete button2;
	delete button3;
	delete button4;
}

void PWWindow::LoadMainBitmap() {
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\logo.jpg");
	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\textpw.jpg");
	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\play.jpg");
	wxString fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\settext.jpg");
	wxString fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\htptext.jpg");
	wxString fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\cretext.jpg");
	wxString fileLocation7 = wxFileName(fileLocation).GetPath() + wxT("\\cretextglow.jpg");
	wxString fileLocation8 = wxFileName(fileLocation).GetPath() + wxT("\\htptextglow.jpg");
	wxString fileLocation9 = wxFileName(fileLocation).GetPath() + wxT("\\settextglow.jpg");
	wxString fileLocation10 = wxFileName(fileLocation).GetPath() + wxT("\\playglow.jpg");
	
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


	logoBitmap = new wxBitmap(image1.Scale(350, 350));
	textpwBitmap = new wxBitmap(image2);
	playbutton = new wxBitmap(image3);
	playbuttonglow = new wxBitmap(image10);
	settingbutton = new wxBitmap(image4);
	settingbuttonglow = new wxBitmap(image9);
	htpbutton = new wxBitmap(image5);
	htpbuttonglow = new wxBitmap(image8);
	creditbutton = new wxBitmap(image6);
	creditbuttonglow = new wxBitmap(image7);

}

void PWWindow::OnPaint(wxPaintEvent &event) {
	wxPaintDC pdc1(this), pdc2(this);
	if (logoBitmap != nullptr)
		pdc1.DrawBitmap(*logoBitmap, wxPoint(325, 10), true);
	if (logoBitmap != nullptr)
		pdc2.DrawBitmap(*textpwBitmap, wxPoint(200, 330), true);
}

void PWWindow::ClickPlay(wxCommandEvent & event)
{
}

void PWWindow::ClickSetting(wxCommandEvent & event)
{
}

void PWWindow::ClickHTP(wxCommandEvent & event)
{
}

void PWWindow::ClickCredit(wxCommandEvent & event)
{
}
