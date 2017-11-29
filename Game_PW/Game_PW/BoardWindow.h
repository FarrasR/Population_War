#pragma once 
#include "wx\wx.h" 
#include "PWFrame.h"

class BoardWindow : public wxWindow{
public:
	BoardWindow(PWFrame *parent);
	~BoardWindow();

	void OnPaint(wxPaintEvent &event);
	void BackToMainMenu(wxCommandEvent &event);

private:
	PWFrame *parent;

	wxBitmap *board = nullptr;

	void LoadBitmap();
	DECLARE_EVENT_TABLE()
};

