///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __wxForms__
#define __wxForms__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/toolbar.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/grid.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/choice.h>
#include <wx/radiobox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define btn1 1000
#define btn2 1001
#define btn3 1002
#define btn4 1003
#define btn5 1004
#define btn6 1005
#define btn7 1006
#define btn8 1007
#define btn9 1008
#define btn10 1009

///////////////////////////////////////////////////////////////////////////////
/// Class wxMain
///////////////////////////////////////////////////////////////////////////////
class wxMain : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel1;
		wxToolBar* m_toolBar1;
		wxStaticText* m_staticText6;
		wxTextCtrl* m_TextBoxSearch;
		wxBitmapButton* btn_Search;
		wxBitmapButton* stop_Search;
		wxGrid* wxGridMain;
		wxStatusBar* m_statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void wxMainOnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void btnTool_NewDB( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnTool_OpenDB( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnTool_SaveDB( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnTool_InfoBook( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnTool_AddBook( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnTool_EditBook( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnTool_DeleteBook( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnTool_Log( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnTool_Help( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnTool_Sell( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnEvent_Search( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_SearchOnRightDClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void stop_SearchOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void wxGridMainOnGridLabelLeftClick( wxGridEvent& event ) { event.Skip(); }
		virtual void wxGridMainOnGridSelectCell( wxGridEvent& event ) { event.Skip(); }
		
	
	public:
		
		wxMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxRamLex BookManager :: Menu Principal"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 983,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~wxMain();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxLogger
///////////////////////////////////////////////////////////////////////////////
class wxLogger : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel2;
		wxTextCtrl* m_TextPool;
	
	public:
		
		wxLogger( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Log ..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 650,400 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~wxLogger();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxAuthor
///////////////////////////////////////////////////////////////////////////////
class wxAuthor : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel3;
		wxStaticText* m_staticText2;
		wxTextCtrl* Tb_editorial;
		wxStaticText* m_staticText3;
		wxTextCtrl* Tb_author;
		wxStaticText* m_staticText31;
		wxTextCtrl* Tb_title;
		wxStaticText* m_staticText32;
		wxTextCtrl* Tb_isbn;
		wxStaticText* m_staticText33;
		wxTextCtrl* Tb_precio;
		wxStaticText* m_staticText34;
		wxTextCtrl* Tb_paginas;
		wxStaticText* m_staticText35;
		wxTextCtrl* Tb_peso;
		wxStaticText* m_staticText36;
		wxStaticText* label_Stock;
		wxButton* Btn_more;
		wxButton* Btn_less;
		wxStaticText* m_staticText361;
		wxChoice* comboBox_Category;
		wxButton* btn_OK;
		wxButton* btnCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void wxAuthorOnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void Btn_moreOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void Btn_moreThanOneButtonClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void Btn_lessOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void Btn_lessThanOneButtonClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void btnOKnSave_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnCancel_OnClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		wxAuthor( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("setTitle"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 368,363 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~wxAuthor();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxSearchOps
///////////////////////////////////////////////////////////////////////////////
class wxSearchOps : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel4;
		wxRadioBox* m_radioBox1;
		wxButton* btn_SetSearchOps;
		
		// Virtual event handlers, overide them in your derived class
		virtual void btn_SetSearchOpsOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		wxSearchOps( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Opciones"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 133,177 ), long style = wxDEFAULT_DIALOG_STYLE );
		~wxSearchOps();
	
};

#endif //__wxForms__
