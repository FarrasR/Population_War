#include "CreditWindow.h"

BEGIN_EVENT_TABLE(CreditWindow, wxWindow)
END_EVENT_TABLE()


CreditWindow::CreditWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	this->parent = parent;
}


CreditWindow::~CreditWindow()
{

}
