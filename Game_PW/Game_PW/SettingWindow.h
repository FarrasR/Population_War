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


private:
	PWFrame *parent;

	wxBitmap *abilitybox = nullptr;
	wxBitmap *checkboxfalse = nullptr;
	wxBitmap *checkboxtrue = nullptr;
	wxBitmap *logo = nullptr;


	wxBitmapButton *buttonkill;
	wxBitmapButton *buttonconvert;
	wxBitmapButton *buttonsacrifice;
	wxBitmapButton *buttonrelocate;

	void LoadBitmap();
	void CheckSetting();

	DECLARE_EVENT_TABLE()
};

