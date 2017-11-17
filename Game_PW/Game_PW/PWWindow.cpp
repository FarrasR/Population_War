#include "PWWindow.h" 
#include <wx/stdpaths.h> 
#include <wx/filename.h> 

BEGIN_EVENT_TABLE(PWWindow, wxWindow)
EVT_PAINT(PWWindow::OnPaint)
END_EVENT_TABLE()

PWWindow::PWWindow(wxFrame *parent) : wxWindow(parent, wxID_ANY) {
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpgLoader);
	this->LoadMainBitmap();
	this->SetBackgroundColour(wxColour(*wxBLACK));
}

PWWindow::~PWWindow() {
	delete logoBitmap;
	delete textpwBitmap;
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