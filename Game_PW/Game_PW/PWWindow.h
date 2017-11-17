#pragma once 
#include "wx\wx.h" 

class PWWindow : public wxWindow {
public:
	PWWindow(wxFrame *parent);
	~PWWindow();
	void OnPaint(wxPaintEvent &event);
private:
	wxBitmap *logoBitmap = nullptr;
	wxBitmap *textpwBitmap = nullptr;
	DECLARE_EVENT_TABLE()
	void LoadMainBitmap();
};