#pragma once 
#include "wx\wx.h" 
#include "PWFrame.h"

class SettingWindow : public wxWindow
{
public:
	SettingWindow(PWFrame *parent);
	~SettingWindow();

	void OnPaint(wxPaintEvent &event);

	void EnableKill(wxCommandEvent& event);
	void EnableConvert(wxCommandEvent& event);
	void EnableSacrifice(wxCommandEvent& event);
	void EnableRelocate(wxCommandEvent& event);
	void BackToMainMenu(wxCommandEvent &event);
	void AbilityMenu(wxCommandEvent &event);
	void CellMenu(wxCommandEvent &event);
	void NextColor1(wxCommandEvent &event);
	void NextColor2(wxCommandEvent &event);

private:
	PWFrame *parent;

	wxBitmap *settingbox = nullptr;
	wxBitmap *checkboxfalse = nullptr;
	wxBitmap *checkboxtrue = nullptr;
	wxBitmap *logo = nullptr;
	wxBitmap *mainmenu = nullptr;
	wxBitmap *mainmenuglow = nullptr;
	wxBitmap *abilitymenu = nullptr;
	wxBitmap *abilitymenuglow = nullptr;
	wxBitmap *cellmenu = nullptr;
	wxBitmap *cellmenuglow = nullptr;
	wxBitmap *abilitytext = nullptr;
	wxBitmap *celltext = nullptr;
	wxBitmap *cellbluecolor = nullptr;
	wxBitmap *cellredcolor = nullptr;
	wxBitmap *cellyellowcolor = nullptr;
	wxBitmap *cellgreencolor = nullptr;
	wxBitmap *nextcolor = nullptr;

	wxStaticBitmap *menutextstatic;
	wxStaticBitmap *player1color;
	wxStaticBitmap *player2color;
	wxBitmapButton *buttonkill;
	wxBitmapButton *buttonconvert;
	wxBitmapButton *buttonsacrifice;
	wxBitmapButton *buttonrelocate;
	wxBitmapButton *buttonmainmenu;
	wxBitmapButton *buttonabilitymenu;
	wxBitmapButton *buttoncellmenu;
	wxBitmapButton *buttonnextcolor1;
	wxBitmapButton *buttonnextcolor2;

	void LoadBitmap();
	void CheckSetting();

	DECLARE_EVENT_TABLE()
};

