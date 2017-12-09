#include "BoardWindow.h"
#include <wx/stdpaths.h> 
#include <wx/filename.h>
#include "Cell.h"
#include <wx/arrimpl.cpp>
#include <wx/dynarray.h>


BEGIN_EVENT_TABLE(BoardWindow, wxWindow)
	EVT_PAINT(BoardWindow::OnPaint)
	EVT_BUTTON(4001, BoardWindow::BackToMainMenu)
	EVT_BUTTON(4010, BoardWindow::Response)
END_EVENT_TABLE()


BoardWindow::BoardWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY){
	this->SetBackgroundColour(wxColour(*wxBLACK));
	wxInitAllImageHandlers();
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpgLoader);
	this->LoadBitmap();
	this->parent = parent;

	for (int i = 0; i < 20; i++) {
		vector<Cell*>temp2;
		myboard.push_back(temp2);
		for (int j = 0; j < 20; j++) {
			Cell *yuhu;
			yuhu = new Cell(this, (251 + 25 * i), (121 + 25 * j), i, j);
			yuhu->Bind(wxEVT_BUTTON, &BoardWindow::Response, this);

			myboard[i].push_back(yuhu);
		}
	}

	buttonmainmenu = new wxBitmapButton(this, 4001, *mainmenu, wxPoint(28, 200), wxDefaultSize, wxBORDER_NONE);
	buttonmainmenu->SetBitmapCurrent(*mainmenuglow);
	Current_Player = 1;
	Count = 0;
	Total_Count = 0;
	this->First_Phase = true;
}


BoardWindow::~BoardWindow(){
	delete mainmenu;
	delete mainmenuglow;
	delete board;
	delete logo;
	delete cell00;
	delete cell11;
	delete cell22;
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
	Cell *temp = wxDynamicCast(event.GetEventObject(), Cell);

	if(this->First_Phase==true)FirstPhase(temp);

	UpdateCells();
}


void BoardWindow::UpdateCells()
{
	for (int i = 0; i < myboard.size(); i++)
	{
		for (int j = 0; j < myboard[i].size(); j++)
			myboard[i][j]->setColor();
	}
}

void BoardWindow::Update_Cell_Future_Ownership(Coordinates search)
{
	Nearby temp=Get_Nearby_Cell(search);
	temp.fugu();
	if (myboard[search.x][search.y]->Get_Ownership() != 0)
	{
		if(temp.living==2 || temp.living==3)myboard[search.x][search.y]->Set_Future_Ownership(myboard[search.x][search.y]->Get_Ownership());
		else myboard[search.x][search.y]->Set_Future_Ownership(0);
	}
	else myboard[search.x][search.y]->Set_Future_Ownership(temp.live());
}

void BoardWindow::Update_Board()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			Coordinates temp(i, j);
			Update_Cell_Future_Ownership(temp);
		}
	}
	UpdateCells();
}

int BoardWindow::Get_Cell_Ownership(Coordinates search)
{
	return myboard[search.x][search.y]->Get_Ownership();
}

int BoardWindow::Get_Future_Ownership(Coordinates search)
{
	return myboard[search.x][search.y]->Get_Future_Ownership();
}

Nearby BoardWindow::Get_Nearby_Cell(Coordinates search)
{
	int tempx[8] = { -1,0,1,-1,1,-1,0,1 };
	int tempy[8] = { 1,1,1,0,0,-1,-1,-1 };
	Nearby kol;
	for (int i = 0; i < 8; i++)
	{
		if (search.x + tempx[i] < 20 && search.x + tempx[i] >= 0 && search.y + tempy[i] < 20 && search.y + tempy[i] >= 0)
		{
			Coordinates temp(search.x + tempx[i], search.y + tempy[i]);
			kol.player[Get_Cell_Ownership(temp)]++;
		}
	}
	return kol;
}

void BoardWindow::Set_Current_Cell(Coordinates target, int player)
{
	myboard[target.x][target.y]->Set_Current_Ownership(player);
}

void BoardWindow::Set_Future_Cell(Coordinates target, int player)
{
	myboard[target.x][target.y]->Set_Future_Ownership(player);
}

void BoardWindow::FirstPhase(Cell * cari)
{
	if (cari->Get_Ownership() != 0)return;
	if (Count == 5)
	{
		if (this->Current_Player == 1)this->Current_Player = 2;
		else this->Current_Player = 1;
		Count = 0;
	}
	wxMessageOutputDebug().Printf("Player %d", this->Current_Player);
	Count++;
	Total_Count++;
	cari->Set_Current_Ownership(this->Current_Player);
	cari->Set_Future_Ownership(this->Current_Player);

	if (Total_Count == 10)Update_Board();

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
	wxString fileLocation7 = wxFileName(fileLocation).GetPath() + wxT("\\merahmerah.jpg");

	wxString fileLocation8 = wxFileName(fileLocation).GetPath() + wxT("\\merahhitam.jpg");
	wxString fileLocation9 = wxFileName(fileLocation).GetPath() + wxT("\\biruhitam.jpg");
	wxString fileLocation10 = wxFileName(fileLocation).GetPath() + wxT("\\hitammerah.jpg");
	wxString fileLocation11 = wxFileName(fileLocation).GetPath() + wxT("\\hitambiru.jpg");


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


	board = new wxBitmap(image1);
	logo = new wxBitmap(image4.Scale(200, 200));
	mainmenu = new wxBitmap(image2.Scale(160, 60));
	mainmenuglow = new wxBitmap(image3.Scale(160, 60));
	cell00 = new wxBitmap(image5);
	cell11 = new wxBitmap(image6);
	cell22 = new wxBitmap(image7);
	cell20 = new wxBitmap(image8);
	cell10 = new wxBitmap(image9);
	cell01 = new wxBitmap(image11);
	cell02 = new wxBitmap(image10);
}


