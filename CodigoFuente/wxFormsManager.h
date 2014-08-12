#ifndef H_wxManager
#define H_wxManager

#include <wx/filedlg.h>
#include "cBook.h"
#include "wxForms.h"

#include <wx/timer.h>
using namespace std;

class windowMain : public wxMain {
private: 
	void Initialize();
	void CleanUp();
	void CheckClosingFile();
	void SetRow(int row, string E, string A, string T, string I, string S);
	void LoadBooksInGrid();
	
protected:
	void wxMainOnClose( wxCloseEvent& event ) ;

public:
	windowMain(wxWindow *parent = NULL);
	void ReloadGrid();
	//Events
	void btnTool_NewDB( wxCommandEvent& event );
	void btnTool_OpenDB ( wxCommandEvent& event );
	void btnTool_SaveDB ( wxCommandEvent& event );
	void btnTool_InfoBook ( wxCommandEvent& event );
	void btnTool_AddBook ( wxCommandEvent& event );
	void btnTool_EditBook ( wxCommandEvent& event );
	void btnTool_DeleteBook ( wxCommandEvent& event );
	void btnTool_Log ( wxCommandEvent& event );
	void btnTool_Help ( wxCommandEvent& event );
	void btnTool_Sell ( wxCommandEvent& event );
	void btnEvent_Search (wxCommandEvent& event );
	void btn_SearchOnRightDClick (wxMouseEvent& event );
	void wxGridMainOnGridLabelLeftClick ( wxGridEvent& event );
	void wxGridMainOnGridSelectCell ( wxGridEvent& event );	
	void OnTimer(wxTimerEvent& event);
	void stop_SearchOnButtonClick( wxCommandEvent& event ) ;
	
	DECLARE_EVENT_TABLE();
};

class windowLog : public wxLogger {
public:
	windowLog(wxWindow* parent = NULL);
};

class windowAuthor : public wxAuthor {
private:
	int _Mode;	
	
public:
	windowAuthor(wxWindow* parent = NULL, int = 0);
	void btnCancel_OnClick ( wxCommandEvent& event );
	void wxAuthorOnClose ( wxCloseEvent& event );
	void Btn_moreThanOneButtonClick( wxMouseEvent& event ) ;
	void Btn_lessThanOneButtonClick( wxMouseEvent& event ) ;
	void Btn_moreOnButtonClick( wxCommandEvent& event );
	void Btn_lessOnButtonClick( wxCommandEvent& event);
	void btnOKnSave_OnClick( wxCommandEvent& event );
		
};

class windowSearch : public wxSearchOps {
private:
		
public:
	windowSearch(wxWindow* parent = NULL);
	void btn_SetSearchOpsOnButtonClick( wxCommandEvent& event ) ;
};

extern wxFileDialog* _sourceFile;
extern wxFileDialog* _openFile;
extern bool* _eea;
extern int _idSelected;
extern wxWindow* myParent;
#endif
