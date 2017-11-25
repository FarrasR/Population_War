#pragma once
#include "wx\wx.h" 
#include "PWFrame.h"

class CreditWindow : public wxWindow
{
public:
	CreditWindow(PWFrame *parent);
	~CreditWindow();
private:
	PWFrame *parent;
	DECLARE_EVENT_TABLE()
};

