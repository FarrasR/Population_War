#pragma once 
#include "wx\wx.h" 

class PWWindow : public wxWindow {
public:
	PWWindow(wxFrame *parent);
	~PWWindow();
	void OnPaint(wxPaintEvent &event);

	void ClickPlay(wxCommandEvent &event);
	void ClickSetting(wxCommandEvent &event);
	void ClickHTP(wxCommandEvent &event);
	void ClickCredit(wxCommandEvent &event);

private:
	wxBitmap *logoBitmap = nullptr;
	wxBitmap *textpwBitmap = nullptr;
	wxBitmap *playbutton = nullptr;
	wxBitmap *settingbutton = nullptr;
	wxBitmap *htpbutton = nullptr;
	wxBitmap *creditbutton = nullptr;
	wxBitmapButton *button1;
	wxBitmapButton *button2;
	wxBitmapButton *button3;
	wxBitmapButton *button4;

	void LoadMainBitmap();
	DECLARE_EVENT_TABLE()
};