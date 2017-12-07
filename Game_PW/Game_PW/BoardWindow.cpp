#include "BoardWindow.h"
#include <wx/stdpaths.h> 
#include <wx/filename.h>
#include "Cell.h"
#include <wx/arrimpl.cpp>
#include <wx/dynarray.h>

WX_DEFINE_ARRAY(Cell *, Objectarray);

BEGIN_EVENT_TABLE(BoardWindow, wxWindow)
	EVT_PAINT(BoardWindow::OnPaint)
	EVT_BUTTON(4001, BoardWindow::BackToMainMenu)
	EVT_BUTTON(4010, BoardWindow::Response)
END_EVENT_TABLE()

Objectarray arr_obj;

BoardWindow::BoardWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY){
	this->SetBackgroundColour(wxColour(*wxBLACK));
	wxInitAllImageHandlers();
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpgLoader);
	this->LoadBitmap();
	this->parent = parent;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			Cell *yuhu;
			yuhu = new Cell(this, (251 + 25 * i), (121 + 25 * j), i, j);
			yuhu->Bind(wxEVT_BUTTON, &BoardWindow::Response, this);
			arr_obj.Add(yuhu);
		}
	}

	buttonmainmenu = new wxBitmapButton(this, 4001, *mainmenu, wxPoint(28, 200), wxDefaultSize, wxBORDER_NONE);
	buttonmainmenu->SetBitmapCurrent(*mainmenuglow);
}


BoardWindow::~BoardWindow(){
	delete mainmenu;
	delete mainmenuglow;
	delete board;
	delete logo;
	delete cellhitamhitam;
	delete cellbirubiru;
	delete buttonmainmenu;
}

void BoardWindow::OnPaint(wxPaintEvent & event){
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*board, wxPoint(250, 120), true);
	pdc.DrawBitmap(*logo, wxPoint(10, 10), true);
}

void BoardWindow::BackToMainMenu(wxCommandEvent & event){
	parent->ShowMainWindow();
}

void BoardWindow::Response(wxCommandEvent & event)
{
	wxMessageOutputDebug().Printf("hehe");

	Cell *temp = wxDynamicCast(event.GetEventObject(), Cell);

	wxMessageOutputDebug().Printf("%d %d",temp->ownership, temp->futureownership);

	temp->ownership = 1;
	temp->futureownership = 1;
	wxMessageOutputDebug().Printf("%d %d %d %d", temp->x, temp->y,temp->ownership, temp->futureownership);
	temp->setColor();
}

void BoardWindow::UpdateCells()
{
	for (unsigned int i = 0; i < arr_obj.GetCount(); i++)
		arr_obj[i]->setColor();
}



void BoardWindow::LoadBitmap(){
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	wxString fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\board.jpg");
	wxString fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenu.jpg");
	wxString fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\mainmenuglow.jpg");
	wxString fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\logo.jpg");
	wxString fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\hitamhitam.jpg");
	wxString fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\birubiru.jpg");

	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);
	wxImage image4(fileLocation4, wxBITMAP_TYPE_JPEG);
	wxImage image5(fileLocation5, wxBITMAP_TYPE_JPEG);
	wxImage image6(fileLocation6, wxBITMAP_TYPE_JPEG);

	board = new wxBitmap(image1);
	logo = new wxBitmap(image4.Scale(200, 200));
	mainmenu = new wxBitmap(image2.Scale(160, 60));
	mainmenuglow = new wxBitmap(image3.Scale(160, 60));
	cellhitamhitam = new wxBitmap(image5);
	cellbirubiru = new wxBitmap(image6);
}


