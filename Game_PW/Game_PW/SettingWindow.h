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
	void EnableSacrifice(wxCommandEvent& event);
	void BackToMainMenu(wxCommandEvent &event);

private:
	PWFrame *parent;

	wxBitmap *abilitybox = nullptr;
	wxBitmap *checkboxfalse = nullptr;
	wxBitmap *checkboxtrue = nullptr;

	void LoadBitmap();
	DECLARE_EVENT_TABLE()
};

