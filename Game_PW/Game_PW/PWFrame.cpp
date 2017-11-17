#include "PWFrame.h" 
#include "PWWindow.h" 

PWFrame::PWFrame(const wxString &title) : wxFrame(NULL, wxID_ANY, title) {
	this->window = new PWWindow(this);
	this->SetInitialSize(wxSize(1000, 700));
}