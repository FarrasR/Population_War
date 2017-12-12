#pragma once 
#include "wx\wx.h" 
#include "PWFrame.h"
#include <wx/app.h>
#include <wx/arrimpl.cpp>
#include <wx/dynarray.h>
#include <wx/dcbuffer.h>
#include <vector>
#include "CellTools.h"
using namespace std;


class Cell;

class BoardWindow : public wxWindow{
public:
	BoardWindow(PWFrame *parent);
	~BoardWindow();
	void StartGame();
	void StartSecondPhase();
	void OnPaint(wxPaintEvent &event);
	void BackToMainMenu(wxCommandEvent &event);
	
	void Response(wxCommandEvent &event);	//RESPONSE CUMA BUAT INPUT, DIPROSES SAMA FUNGSI LAIN!!!
	void GoPlay(wxCommandEvent &event);
	void Change_Player_Turn();

	void SacrificeAbility(wxCommandEvent &event);
	void RelocateAbility(wxCommandEvent &event);
	void KillAbility(wxCommandEvent &event);
	void ConvertAbility(wxCommandEvent &event);


	//Func
	void FirstPhase(Cell* cari);
	void Kill(Cell* cari);
	void Convert(Cell* cari);
	void Sacrifice(Cell* cari);
	void Relocate(Cell* cari);

	void UpdateCells();

	vector<vector <Cell*> >myboard;

	//Updater
	void Update_Cell_Future_Ownership(Coordinates search);
	void Update_Board();
	void Update_Turn();

	//Getter
	int Get_Cell_Ownership(Coordinates search);
	int Get_Future_Ownership(Coordinates search);
	Nearby Get_Nearby_Cell(Coordinates search);

	//set Ownership
	void Set_Current_Cell(Coordinates target, int player);
	void Set_Future_Cell(Coordinates target, int player);


	wxBitmap *cell00 = nullptr;
	wxBitmap *cell11 = nullptr;
	wxBitmap *cell22 = nullptr;
	wxBitmap *cell01 = nullptr;
	wxBitmap *cell02 = nullptr;
	wxBitmap *cell10 = nullptr;
	wxBitmap *cell20 = nullptr;
	
private:
	PWFrame *parent;
	
	wxBitmap *mainmenu = nullptr;
	wxBitmap *mainmenuglow = nullptr;
	wxBitmap *board = nullptr;
	wxBitmap *logo = nullptr;
	wxBitmap *sacrifice = nullptr;
	wxBitmap *sacrificeglow = nullptr;
	wxBitmap *relocate = nullptr;
	wxBitmap *relocateglow = nullptr;
	wxBitmap *kill = nullptr;
	wxBitmap *killglow = nullptr;
	wxBitmap *convert = nullptr;
	wxBitmap *convertglow = nullptr;
	wxBitmap *player1turn = nullptr;
	wxBitmap *player2turn = nullptr;
	wxBitmap *score = nullptr;
	wxBitmap *goplay = nullptr;
	wxBitmap *goplayglow = nullptr;

	wxStaticBitmap *playerturn;
	wxBitmapButton *buttonmainmenu;
	wxBitmapButton *buttonsacrifice;
	wxBitmapButton *buttonrelocate;
	wxBitmapButton *buttonkill;
	wxBitmapButton *buttonconvert;
	wxBitmapButton *buttoncellcoba;
	wxBitmapButton *buttongoplay;

	bool First_Phase;
	bool Bisa_Kill;
	bool Bisa_Relocate;
	bool Bisa_Convert;
	bool Bisa_Sacrifice;

	bool sacriflag;
	bool reloflag;

	int Current_Player;
	int Count;
	int Total_Count;

	int Sacrifice_Count;
	int Relocate_Count;

	int JumlahCellp1 = 0;
	int JumlahCellp2 = 0;

	void LoadBitmap();
	DECLARE_EVENT_TABLE()
};

