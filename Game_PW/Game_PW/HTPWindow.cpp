#include "HTPWindow.h"

BEGIN_EVENT_TABLE(HTPWindow, wxWindow)
	EVT_PAINT(HTPWindow::OnPaint)
	EVT_BUTTON(3001, HTPWindow::NextPage)
	EVT_BUTTON(3002, HTPWindow::PreviousPage)
END_EVENT_TABLE()

HTPWindow::HTPWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	this->parent = parent;
	page = 1;
	nextbutton = new wxButton(this, 3001, wxT("NextPage"), wxPoint(300, 400), wxDefaultSize, 0, wxDefaultValidator, wxT("killemall"));
	Previousbutton = new wxButton(this, 3002, wxT("PreviousPage"), wxPoint(300, 450), wxDefaultSize, 0, wxDefaultValidator, wxT("killemall"));
	CheckPage();
}


HTPWindow::~HTPWindow()
{

}

void HTPWindow::OnPaint(wxPaintEvent & event)
{
	wxMessageOutputDebug().Printf("Page %d", this->page);
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

void HTPWindow::CheckPage()
{
	if(page==1)Previousbutton->Show(false);
	else Previousbutton->Show(true);
	Refresh();
}
