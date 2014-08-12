#include "Application.h"
#include "wxFormsManager.h"

#include <wx/splash.h>

using namespace std;

bool mxApplication::OnInit() {
	wxImage::AddHandler(new wxPNGHandler());
	wxBitmap bitmap;
	wxSplashScreen* splash;
	if (bitmap.LoadFile("usplash.PNG", wxBITMAP_TYPE_PNG))
	{
		splash = new wxSplashScreen(bitmap, wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,5000, NULL, -1, wxDefaultPosition, wxDefaultSize,
			wxBORDER_SIMPLE|wxSTAY_ON_TOP);
		splash->SetIcon(wxIcon("icons/ico.png", wxBITMAP_TYPE_PNG, 32, 32));
	}
	wxYield();
	windowMain* w =	new windowMain();
	wxTimer* t = new wxTimer(w->GetEventHandler());
	t->Start(5000,false);	
	return true;
}
