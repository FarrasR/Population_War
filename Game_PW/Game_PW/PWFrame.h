#pragma once 
#include "wx\wx.h" 

class PWWindow;
class PWFrame : public wxFrame {
private:
	PWWindow *window;
public:
	PWFrame(const wxString &title);
};