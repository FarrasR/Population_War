#include "BoardWindow.h"
#include <wx/stdpaths.h> 
#include <wx/filename.h>
#include "Cell.h"
#include <wx/arrimpl.cpp>
#include <wx/dynarray.h>
#include <sstream>
using namespace std;


BEGIN_EVENT_TABLE(BoardWindow, wxWindow)
	EVT_PAINT(BoardWindow::OnPaint)
	EVT_BUTTON(4001, BoardWindow::BackToMainMenu)
	EVT_BUTTON(4002, BoardWindow::SacrificeAbility)
	EVT_BUTTON(4003, BoardWindow::RelocateAbility)
	EVT_BUTTON(4004, BoardWindow::KillAbility)
	EVT_BUTTON(4005, BoardWindow::ConvertAbility)
	EVT_BUTTON(4006, BoardWindow::GoPlay)
	EVT_BUTTON(4007, BoardWindow::SkipAbility)
	EVT_BUTTON(4010, BoardWindow::Response)
END_EVENT_TABLE()


BoardWindow::BoardWindow(PWFrame *parent) : wxWindow(parent, wxID_ANY){
	this->SetBackgroundColour(wxColour(*wxBLACK));
	wxInitAllImageHandlers();
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImageHandler *gifLoader = new wxGIFHandler();
	wxImage::AddHandler(jpgLoader);
	wxImage::AddHandler(gifLoader);
	this->parent = parent;
	this->LoadBitmap();
	buttonmainmenu = new wxBitmapButton(this, 4001, *mainmenu, wxPoint(28, 200), wxDefaultSize, wxBORDER_NONE);
	buttonsacrifice = new wxBitmapButton(this, 4002, *sacrifice, wxPoint(780, 200), wxDefaultSize, wxBORDER_NONE);
	buttonrelocate = new wxBitmapButton(this, 4003, *relocate, wxPoint(780, 255), wxDefaultSize, wxBORDER_NONE);
	buttonkill = new wxBitmapButton(this, 4004, *kill, wxPoint(780, 310), wxDefaultSize, wxBORDER_NONE);
	buttonconvert = new wxBitmapButton(this, 4005, *convert, wxPoint(780, 365), wxDefaultSize, wxBORDER_NONE);
	buttonskip=new wxBitmapButton(this, 4007, *skip, wxPoint(780, 420), wxDefaultSize, wxBORDER_NONE);

	buttongoplay = new wxBitmapButton(this, 4006, *goplay, wxPoint(825, 470), wxDefaultSize, wxBORDER_NONE);
	playerturn = new wxStaticBitmap(this, wxID_ANY, *player1turn, wxPoint(300, 15), wxDefaultSize, wxBORDER_NONE);
	
	buttonmainmenu->SetBitmapCurrent(*mainmenuglow);
	buttonsacrifice->SetBitmapCurrent(*sacrificeglow);
	buttonrelocate->SetBitmapCurrent(*relocateglow);
	buttonkill->SetBitmapCurrent(*killglow);
	buttonconvert->SetBitmapCurrent(*convertglow);
	buttonskip->SetBitmapCurrent(*skipglow);
	buttongoplay->SetBitmapCurrent(*goplayglow);
}


BoardWindow::~BoardWindow(){
	delete mainmenu;
	delete mainmenuglow;
	delete board;
	delete logo;
	delete sacrifice;
	delete sacrificeglow;
	delete relocate;
	delete relocateglow;
	delete kill;
	delete killglow;
	delete convert;
	delete convertglow;
	delete skip;
	delete skipglow;
	delete player1turn;
	delete player2turn;
	delete score;
	delete goplay;
	delete goplayglow;
	delete playerturn;
	delete buttonmainmenu;
	delete buttonsacrifice;
	delete buttonrelocate;
	delete buttonkill;
	delete buttonskip;
	delete buttonconvert;
	delete buttoncellcoba;
	delete buttongoplay;
	delete cell00;
	delete cell11;
	delete cell22;
	delete cell01;
	delete cell02;
	delete cell10;
	delete cell20;
}

void BoardWindow::StartGame()
{
	this->JumlahCellp1 = 0;
	this->JumlahCellp2 = 0;
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	wxString fileLocation1;
	wxString fileLocation2;
	wxString fileLocation3;
	wxString fileLocation4;
	wxString fileLocation5;
	wxString fileLocation6;

	if (parent->setting->colorp1 == 1)
	{
		fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\birubiru.jpg");
		fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\biruhitam.jpg");
		fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\hitambiru.jpg");
	}
	else if (parent->setting->colorp1 == 2)
	{
		fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\merahmerah.jpg");
		fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\merahhitam.jpg");
		fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\hitammerah.jpg");
	}
	else if (parent->setting->colorp1 == 3)
	{
		fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\kuningkuning.jpg");
		fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\kuninghitam.jpg");
		fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\hitamkuning.jpg");
	}
	else if (parent->setting->colorp1 == 4)
	{
		fileLocation1 = wxFileName(fileLocation).GetPath() + wxT("\\hijauhijau.jpg");
		fileLocation2 = wxFileName(fileLocation).GetPath() + wxT("\\hijauhitam.jpg");
		fileLocation3 = wxFileName(fileLocation).GetPath() + wxT("\\hitamhijau.jpg");
	}
	//////////////////////BATAAASSS///////

	if (parent->setting->colorp2 == 1)
	{
		fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\birubiru.jpg");
		fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\biruhitam.jpg");
		fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\hitambiru.jpg");
	}
	else if (parent->setting->colorp2 == 2)
	{
		fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\merahmerah.jpg");
		fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\merahhitam.jpg");
		fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\hitammerah.jpg");
	}
	else if (parent->setting->colorp2 == 3)
	{
		fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\kuningkuning.jpg");
		fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\kuninghitam.jpg");
		fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\hitamkuning.jpg");
	}
	else if (parent->setting->colorp2 == 4)
	{
		fileLocation4 = wxFileName(fileLocation).GetPath() + wxT("\\hijauhijau.jpg");
		fileLocation5 = wxFileName(fileLocation).GetPath() + wxT("\\hijauhitam.jpg");
		fileLocation6 = wxFileName(fileLocation).GetPath() + wxT("\\hitamhijau.jpg");
	}


	wxImage image1(fileLocation1, wxBITMAP_TYPE_JPEG);
	wxImage image2(fileLocation2, wxBITMAP_TYPE_JPEG);
	wxImage image3(fileLocation3, wxBITMAP_TYPE_JPEG);
	wxImage image4(fileLocation4, wxBITMAP_TYPE_JPEG);
	wxImage image5(fileLocation5, wxBITMAP_TYPE_JPEG);
	wxImage image6(fileLocation6, wxBITMAP_TYPE_JPEG);

	cell11 = new wxBitmap(image1);
	cell10 = new wxBitmap(image2);
	cell01 = new wxBitmap(image3);

	cell22 = new wxBitmap(image4);
	cell20 = new wxBitmap(image5);
	cell02 = new wxBitmap(image6);


	this->reloflag = false;
	this->sacriflag = false;

	this->buttonkill->Show(false);
	this->buttonsacrifice->Show(false);
	this->buttonconvert->Show(false);
	this->buttonrelocate->Show(false);
	this->buttongoplay->Show(false);
	this->buttonskip->Show(false);


	Current_Player = 1;
	Count = 0;
	Total_Count = 0;
	this->First_Phase = true;
	this->Bisa_Kill = false;
	this->Bisa_Relocate = false;
	this->Bisa_Convert = false;
	this->Bisa_Sacrifice = false;

	Cell *yuhu;
	for (int i = 0; i < 20; i++) {
		vector<Cell*>temp2;
		myboard.push_back(temp2);
		for (int j = 0; j < 20; j++) {
			yuhu = new Cell(this, (251 + 25 * i), (121 + 25 * j), i, j);
			yuhu->Bind(wxEVT_BUTTON, &BoardWindow::Response, this);
			myboard[i].push_back(yuhu);
		}
	}

}

void BoardWindow::StartSecondPhase()
{
	Refresh();
	Update_Board();
	Change_Player_Turn();

	First_Phase = false;
	if (parent->setting->kill == false)this->buttonkill->Show(false);
	else this->buttonkill->Show(true);
	if (parent->setting->sacrifice == false)this->buttonsacrifice->Show(false);
	else this->buttonsacrifice->Show(true);
	if (parent->setting->convert == false)this->buttonconvert->Show(false);
	else this->buttonconvert->Show(true);
	if (parent->setting->relocate == false)this->buttonrelocate->Show(false);
	else this->buttonrelocate->Show(true);
	this->buttonskip->Show(true);
}

void BoardWindow::OnPaint(wxPaintEvent & event){
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*board, wxPoint(250, 120), true);
	pdc.DrawBitmap(*logo, wxPoint(10, 10), true);
	pdc.DrawBitmap(*score, wxPoint(15, 300), true);
	
	wxClientDC dc1(this), dc2(this);

	wstringstream str1, str2;
	str1 << JumlahCellp1 << ends;
	str2 << JumlahCellp2 << ends;

	wxFont font(15, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	dc1.SetFont(font);
	dc2.SetFont(font);
	dc1.SetTextForeground(wxColour(255, 102, 0));
	dc2.SetTextForeground(wxColour(255, 102, 0));
	dc1.DrawText(str1.str().c_str(), 200, 320);
	dc1.DrawText(str2.str().c_str(), 200, 370);
}

void BoardWindow::BackToMainMenu(wxCommandEvent & event) {

	wxString tempo;
	tempo.Printf(wxT("Are you sure mate? Progress won't be saved."));
	int ans = wxMessageBox(tempo, "Main Menu", wxYES_NO);
	if (ans == wxYES)
	{
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				delete myboard[i][j];
			}
		}
		this->myboard.clear();
		parent->ShowMainWindow();
	}
}

void BoardWindow::Response(wxCommandEvent & event)
{
	Cell *temp = wxDynamicCast(event.GetEventObject(), Cell);
	if(this->First_Phase == true)FirstPhase(temp);
	if(this->Bisa_Kill == true)Kill(temp);
	if(this->Bisa_Convert == true)Convert(temp);
	if(this->Bisa_Sacrifice == true)Sacrifice(temp);
	if(this->Bisa_Relocate ==true)Relocate(temp);

	//UpdateCells();
}

void BoardWindow::GoPlay(wxCommandEvent & event)
{
	Refresh();
	Change_Player_Turn();
	Update_Turn();
	this->buttongoplay->Show(false);
}

void BoardWindow::Change_Player_Turn()
{
	Refresh();
	if (First_Phase == false)
	{
		//ubah disini titut
		if (JumlahCellp1 == 0);

		if (JumlahCellp2 == 0);
			

		if (parent->setting->kill == false)this->buttonkill->Show(false);
		else this->buttonkill->Show(true);
		if (parent->setting->sacrifice == false)this->buttonsacrifice->Show(false);
		else this->buttonsacrifice->Show(true);
		if (parent->setting->convert == false)this->buttonconvert->Show(false);
		else this->buttonconvert->Show(true);
		if (parent->setting->relocate == false)this->buttonrelocate->Show(false);
		else this->buttonrelocate->Show(true);
		this->buttonskip->Show(true);
	}

	if (this->Current_Player == 1) this->Current_Player = 2;
	else this->Current_Player = 1;
	if (this->Current_Player == 2) playerturn->SetBitmap(*player2turn);
	else if (this->Current_Player == 1)playerturn->SetBitmap(*player1turn);
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
	Refresh();
	this->JumlahCellp1=0;
	this->JumlahCellp2=0;
	Coordinates temp;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			temp.x = i;
			temp.y = j;
			if(Get_Cell_Ownership(temp) ==1)JumlahCellp1 ++;
			if (Get_Cell_Ownership(temp) == 2)JumlahCellp2++;

			Update_Cell_Future_Ownership(temp);
		}
	}
	wxMessageOutputDebug().Printf("p1 %d p2 %d", JumlahCellp1, JumlahCellp2);

	UpdateCells();
}

void BoardWindow::Update_Turn()
{
	Refresh();
	sacriflag = false;
	reloflag = false;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			myboard[i][j]->Update_Current_Ownership();
		}
	}
	Update_Board();
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
	Coordinates temp;
	for (int i = 0; i < 8; i++)
	{
		if (search.x + tempx[i] < 20 && search.x + tempx[i] >= 0 && search.y + tempy[i] < 20 && search.y + tempy[i] >= 0)
		{
			temp.x = search.x + tempx[i];
			temp.y=	search.y + tempy[i];
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
	Refresh();
	if (cari->Get_Ownership() != 0)return;
	
	Count++;
	Total_Count++;

	cari->Set_Current_Ownership(this->Current_Player);
	cari->Set_Future_Ownership(this->Current_Player);
	cari->setColor();
	
	if (Current_Player == 1)JumlahCellp1++;
	if (Current_Player == 2)JumlahCellp2++;

	if (Count == 5)
	{
		if (Total_Count == 10)StartSecondPhase();
		else
		{
			Change_Player_Turn();
			Count = 0;
		}
	}	
}

void BoardWindow::Kill(Cell * cari)
{
	if (cari->Get_Ownership() == 0)return;
	else
	{
		cari->Set_Current_Ownership(0);		
		Update_Board();
		this->buttonkill->Show(false);
		this->buttonsacrifice->Show(false);
		this->buttonconvert->Show(false);
		this->buttonrelocate->Show(false);
		this->buttongoplay->Show(true);
		this->buttonskip->Show(false);

		this->Bisa_Kill = false;
		this->Bisa_Relocate = false;
		this->Bisa_Convert = false;
		this->Bisa_Sacrifice = false;
		this->First_Phase = false;
	}
}

void BoardWindow::Convert(Cell * cari)
{
	if (cari->Get_Ownership() == 0 || cari->Get_Ownership() == Current_Player)return;
	else
	{
		if(cari->Get_Ownership()==1)
		cari->Set_Current_Ownership(2);
		else cari->Set_Current_Ownership(1);
		Update_Board();
		this->buttonkill->Show(false);
		this->buttonsacrifice->Show(false);
		this->buttonconvert->Show(false);
		this->buttonrelocate->Show(false);
		this->buttongoplay->Show(true);
		this->buttonskip->Show(false);

		this->Bisa_Kill = false;
		this->Bisa_Relocate = false;
		this->Bisa_Convert = false;
		this->Bisa_Sacrifice = false;
		this->First_Phase = false;

	}
}

void BoardWindow::Sacrifice(Cell * cari)
{
	if (Sacrifice_Count != 2)
	{
		if (cari->Get_Ownership() == 0 || cari->Get_Ownership() != Current_Player)return;
		cari->Set_Current_Ownership(0);
		Update_Board();
		Sacrifice_Count++;
	}
	else
	{
		if (cari->Get_Ownership() != 0)return;

		cari->Set_Current_Ownership(Current_Player);
		Update_Board();
		this->buttonkill->Show(false);
		this->buttonsacrifice->Show(false);
		this->buttonconvert->Show(false);
		this->buttonrelocate->Show(false);
		this->buttongoplay->Show(true);
		this->buttonskip->Show(false);

		this->Bisa_Kill = false;
		this->Bisa_Relocate = false;
		this->Bisa_Convert = false;
		this->Bisa_Sacrifice = false;
		this->First_Phase = false;
	}
}

void BoardWindow::Relocate(Cell * cari)
{
	if (Relocate_Count != 1)
	{
		if (cari->Get_Ownership() == 0 || cari->Get_Ownership() == Current_Player)return;
		cari->Set_Current_Ownership(0);
		Update_Board();
		Relocate_Count++;
	}
	else
	{
		if (cari->Get_Ownership() != 0)return;

		if (Current_Player == 1)
			cari->Set_Current_Ownership(2);
		else cari->Set_Current_Ownership(1);

		Update_Board();
		this->Bisa_Kill = false;
		this->Bisa_Relocate = false;
		this->Bisa_Convert = false;
		this->Bisa_Sacrifice = false;

		this->buttonskip->Show(false);
		this->buttonkill->Show(false);
		this->buttonsacrifice->Show(false);
		this->buttonconvert->Show(false);
		this->buttonrelocate->Show(false);
		this->buttongoplay->Show(true);
		this->First_Phase = false;
	}
}

void BoardWindow::SacrificeAbility(wxCommandEvent & event) {
	
	if (sacriflag == true)return;
	wxMessageOutputDebug().Printf("diklik sacrifice");
	this->Bisa_Kill = false;
	this->Bisa_Relocate = false;
	this->Bisa_Convert = false;
	this->Bisa_Sacrifice = true;
	this->buttonkill->Show(false);
	this->buttonsacrifice->Show(true);
	this->buttonconvert->Show(false);
	this->buttonrelocate->Show(false);
	this->buttonskip->Show(false);
	this->Sacrifice_Count = 0;
	sacriflag = true;
}

void BoardWindow::RelocateAbility(wxCommandEvent & event) {

	if (reloflag == true)return;
	wxMessageOutputDebug().Printf("diklik sacrifice");
	this->Bisa_Kill = false;
	this->Bisa_Relocate = true;
	this->Bisa_Convert = false;
	this->Bisa_Sacrifice = false;
	this->buttonkill->Show(false);
	this->buttonsacrifice->Show(false);
	this->buttonconvert->Show(false);
	this->buttonskip->Show(false);
	this->buttonrelocate->Show(true);
	this->Relocate_Count = 0;
	reloflag = true;
}

void BoardWindow::KillAbility(wxCommandEvent & event) {
	this->Bisa_Kill = true;
	this->Bisa_Relocate = false;
	this->Bisa_Convert = false;
	this->Bisa_Sacrifice = false;
	this->buttonkill->Show(true);
	this->buttonskip->Show(false);
	this->buttonsacrifice->Show(false);
	this->buttonconvert->Show(false);
	this->buttonrelocate->Show(false);
}

void BoardWindow::ConvertAbility(wxCommandEvent & event) {

	this->Bisa_Kill = false;
	this->Bisa_Relocate = false;
	this->Bisa_Convert = true;
	this->Bisa_Sacrifice = false;
	this->buttonkill->Show(false);
	this->buttonskip->Show(false);
	this->buttonsacrifice->Show(false);
	this->buttonconvert->Show(true);
	this->buttonrelocate->Show(false);
}

void BoardWindow::SkipAbility(wxCommandEvent & event)
{
	this->Bisa_Kill = false;
	this->Bisa_Relocate = false;
	this->Bisa_Convert = false;
	this->Bisa_Sacrifice = false;
	this->buttonkill->Show(false);
	this->buttonskip->Show(false);
	this->buttonsacrifice->Show(false);
	this->buttonconvert->Show(false);
	this->buttonrelocate->Show(false);
	this->buttongoplay->Show(true);
	this->First_Phase = false;
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

	wxString fileLocation12 = wxFileName(fileLocation).GetPath() + wxT("\\sacrificeability.jpg");
	wxString fileLocation13 = wxFileName(fileLocation).GetPath() + wxT("\\sacrificeabilityglow.jpg");
	wxString fileLocation14 = wxFileName(fileLocation).GetPath() + wxT("\\relocateability.jpg");
	wxString fileLocation15 = wxFileName(fileLocation).GetPath() + wxT("\\relocateabilityglow.jpg");
	wxString fileLocation16 = wxFileName(fileLocation).GetPath() + wxT("\\killability.jpg");
	wxString fileLocation17 = wxFileName(fileLocation).GetPath() + wxT("\\killabilityglow.jpg");
	wxString fileLocation18 = wxFileName(fileLocation).GetPath() + wxT("\\convertability.jpg");
	wxString fileLocation19 = wxFileName(fileLocation).GetPath() + wxT("\\convertabilityglow.jpg");

	wxString fileLocation20 = wxFileName(fileLocation).GetPath() + wxT("\\player1.gif");
	wxString fileLocation21 = wxFileName(fileLocation).GetPath() + wxT("\\player2.gif");
	wxString fileLocation22 = wxFileName(fileLocation).GetPath() + wxT("\\score.jpg");
	wxString fileLocation23 = wxFileName(fileLocation).GetPath() + wxT("\\gobutton.jpg");
	wxString fileLocation24 = wxFileName(fileLocation).GetPath() + wxT("\\gobuttonglow.jpg");

	wxString fileLocation25 = wxFileName(fileLocation).GetPath() + wxT("\\skipbutton.jpg");
	wxString fileLocation26 = wxFileName(fileLocation).GetPath() + wxT("\\skipbuttonglow.jpg");


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
	wxImage image12(fileLocation12, wxBITMAP_TYPE_JPEG);
	wxImage image13(fileLocation13, wxBITMAP_TYPE_JPEG);
	wxImage image14(fileLocation14, wxBITMAP_TYPE_JPEG);
	wxImage image15(fileLocation15, wxBITMAP_TYPE_JPEG);
	wxImage image16(fileLocation16, wxBITMAP_TYPE_JPEG);
	wxImage image17(fileLocation17, wxBITMAP_TYPE_JPEG);
	wxImage image18(fileLocation18, wxBITMAP_TYPE_JPEG);
	wxImage image19(fileLocation19, wxBITMAP_TYPE_JPEG);
	wxImage image20(fileLocation20, wxBITMAP_TYPE_GIF);
	wxImage image21(fileLocation21, wxBITMAP_TYPE_GIF);
	wxImage image22(fileLocation22, wxBITMAP_TYPE_JPEG);
	wxImage image23(fileLocation23, wxBITMAP_TYPE_JPEG);
	wxImage image24(fileLocation24, wxBITMAP_TYPE_JPEG);

	wxImage image25(fileLocation25, wxBITMAP_TYPE_JPEG);
	wxImage image26(fileLocation26, wxBITMAP_TYPE_JPEG);

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

	sacrifice = new wxBitmap(image12);
	sacrificeglow = new wxBitmap(image13);
	relocate = new wxBitmap(image14);
	relocateglow = new wxBitmap(image15);
	kill = new wxBitmap(image16);
	killglow = new wxBitmap(image17);
	convert = new wxBitmap(image18);
	convertglow = new wxBitmap(image19);

	player1turn = new wxBitmap(image20);
	player2turn = new wxBitmap(image21);
	score = new wxBitmap(image22);
	goplay = new wxBitmap(image23);
	goplayglow = new wxBitmap(image24);
	skip = new wxBitmap(image25);
	skipglow = new wxBitmap(image26);
}


