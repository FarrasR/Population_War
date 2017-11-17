#include "wx\wx.h" 
#include "PWFrame.h" 

class MyApp : public wxApp {
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)

bool MyApp::OnInit() {
	PWFrame *frame = new PWFrame("Population War");
	frame->Show(true);
	return true;
}