#pragma once 
#include "wx\wx.h" 

class PWWindow;

class PWFrame : public wxFrame {
public:
	PWFrame(const wxString &title);




private:
	PWWindow *window;
};