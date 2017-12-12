#pragma once 
#include "wx\wx.h" 
#include "PWFrame.h"

class PWWindow : public wxWindow {
public:
	PWWindow(PWFrame *parent);
	~PWWindow();
	void OnPaint(wxPaintEvent &event);

	void ClickPlay(wxCommandEvent &event);
	void ClickSetting(wxCommandEvent &event);
	void ClickHTP(wxCommandEvent &event);
	void ClickCredit(wxCommandEvent &event);

private:
	wxBitmap *playbutton = nullptr;
	wxBitmap *settingbutton = nullptr;
	wxBitmap *htpbutton = nullptr;
	wxBitmap *creditbutton = nullptr;
	wxBitmap *playbuttonglow = nullptr;
	wxBitmap *settingbuttonglow = nullptr;
	wxBitmap *htpbuttonglow = nullptr;
	wxBitmap *creditbuttonglow = nullptr;
	wxBitmap *newbackground = nullptr;

	wxBitmapButton *button1;
	wxBitmapButton *button2;
	wxBitmapButton *button3;
	wxBitmapButton *button4;

	PWFrame *parent;

	void LoadMainBitmap();
	DECLARE_EVENT_TABLE()
};