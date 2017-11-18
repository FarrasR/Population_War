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

PWWindow::PWWindow(wxFrame *parent) : wxWindow(parent, wxID_ANY) {

	this->SetBackgroundColour(wxColour(*wxBLACK));
	//wxImage::wxInitAllImageHandlers();
	wxInitAllImageHandlers();
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpgLoader);

	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\play.jpg");
	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	playbutton = new wxBitmap(image1);
	button1 = new wxBitmapButton(this, 1001, *playbutton, wxPoint(380, 420), wxDefaultSize, wxBORDER_NONE);


	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\settext.jpg");
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	settingbutton = new wxBitmap(image2);
	button2 = new wxBitmapButton(this, 1002, *settingbutton, wxPoint(200, 530), wxDefaultSize, wxBORDER_NONE);


	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\htptext.jpg");
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);
	htpbutton = new wxBitmap(image3);
	button3 = new wxBitmapButton(this, 1003, *htpbutton, wxPoint(400, 530), wxDefaultSize, wxBORDER_NONE);


	wxString fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\cretext.jpg");
	wxImage image4(fileLocation4, wxBITMAP_TYPE_JPEG);
	creditbutton = new wxBitmap(image4);
	button4 = new wxBitmapButton(this, 1004, *creditbutton, wxPoint(600, 530), wxDefaultSize, wxBORDER_NONE);

	this->LoadMainBitmap();
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



	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	logoBitmap = new wxBitmap(image1.Scale(350, 350));
	textpwBitmap = new wxBitmap(image2);
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
