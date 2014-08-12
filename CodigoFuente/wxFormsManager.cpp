#include <algorithm>
#include <cstdio>
#include <fstream>
#include <vector>
#include <sstream>
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/textdlg.h>
#include "wxFormsManager.h"
#include "cBook.h"
#include "cBookManager.h"
#include "windows.h"
using namespace std;

BEGIN_EVENT_TABLE(windowMain, wxFrame)
	EVT_TIMER(wxID_ANY,windowMain::OnTimer)
END_EVENT_TABLE()

windowMain :: windowMain(wxWindow *parent) : wxMain (parent){	
	myManager = new cBookManager();
	_sourceFile = new wxFileDialog(this,"Elegir archivo para guardar","","", "RamLexBSM DataBase |*.rldb|",wxSAVE,wxDefaultPosition);
	_openFile = new wxFileDialog(this,"Elegir archivo para abrir","","","RamLexBSM |*.rldb|",wxOPEN,wxDefaultPosition);
	Initialize();
	myParent = this;
}

void windowMain::OnTimer(wxTimerEvent& event) {
	Show();
}

void windowMain::Initialize(){
	wxGridMain->SetSelectionMode(wxGrid::wxGridSelectRows);
	m_statusBar->SetStatusText("Listo");
	SetIcon(wxIcon("icons/ico.png", wxBITMAP_TYPE_PNG, 32, 32));
	m_toolBar1->EnableTool(1006,false);
	m_toolBar1->EnableTool(1009,false);
	_eea = new bool(false);
	searchOpSetted = SEARCH_BY_TITLE;
}

void windowMain::CleanUp(){
	delete myManager;
	myManager = new cBookManager();			
	while(wxGridMain->DeleteRows());
	m_TextBoxSearch->Clear();
	m_toolBar1->EnableTool(1009,false);
	_idSelected = -1;
}

void windowMain::CheckClosingFile(){
	bool finish = false;
	if(myManager->IsAnyChange()){
		int firstAnswer = wxMessageBox("Se han realizado cambios en la base de datos actual.\nDesea guardar los cambios?", "Atención!",wxICON_WARNING | wxYES_NO);
		if(firstAnswer == wxYES) {
			if(myManager->IsFilePathEmpty()){
				do {
					int secondAnswer = _sourceFile->ShowModal();
					if(secondAnswer == wxID_OK){						
						string filePathSelected = (string)_sourceFile->GetPath();
						ifstream fileTest(filePathSelected.c_str(), ios::binary);
						if(fileTest.is_open()){
							int thirdAnswer = wxMessageBox("Archivo existente. Reemplazar?","Atención",wxICON_WARNING | wxYES_NO);
							if(thirdAnswer == wxYES){
								finish = true;
								myManager->SaveDB(filePathSelected);								
							} //If not restart process again. 
						} else {
							finish = true;
							myManager->SaveDB(filePathSelected);
						}						
					} else { //If pressed cancel. Ask again.
						int fourthAnswer = wxMessageBox("Seguro?: Perderá todos los cambios.\n Esta acción no se puede deshacer.","Atención!",wxICON_WARNING | wxYES_NO);
						if(fourthAnswer == wxYES) finish = true;
					}
				} while(!finish);
			} else { //If file path is not empty. Save. Execute.
				myManager->SaveDB();
			}
		} //If not accept proposal. Execute.
	} //If not changed. Execute.
	finish = false;	
}

void windowMain::LoadBooksInGrid(){
	cBook* tmpBook;
	wxString _stock;
	int c = myManager->GetSize();
	for(int i = 0 ; i < c  ; i++){				
		myManager->GetBook(i,&tmpBook);		
		_stock = wxString::Format(wxT("%i"),tmpBook->GetStock());
		SetRow(i,tmpBook->GetEditorial(),tmpBook->GetAuthor(),tmpBook->GetTitle(),tmpBook->GetISBN(),(string)_stock);	
		delete tmpBook;
//		wxGridMain->SelectRow(0);
	}
	
}

void windowMain::SetRow(int row, string E, string A, string T, string I, string S) {
	wxGridMain->AppendRows();
	wxGridMain->SetCellValue(row,0,E);
	wxGridMain->SetCellValue(row,1,A);
	wxGridMain->SetCellValue(row,2,T);
	wxGridMain->SetCellValue(row,3,I);
	wxGridMain->SetCellValue(row,4,S);	
}

void windowMain::btnTool_NewDB (wxCommandEvent& event){
	CheckClosingFile();
	CleanUp();
	m_statusBar->SetStatusText("Creando nueva base de datos ...");
	myManager->LogIt("Creando nueva base de datos.");
	m_statusBar->SetStatusText("Listo. Nueva base de datos creada.");
	m_toolBar1->EnableTool(1006,false);
	m_toolBar1->EnableTool(1009,false);
}
void windowMain::btnTool_OpenDB (wxCommandEvent& event){
	if(*_eea == true) {
		wxMessageBox("UHHHH. Va a tener que llamar al técnico. Su computadora se rompió.\nPor las dudas dele al aceptar.","ERROR!",wxICON_ERROR);
		wxMessageBox("Jejejeje. Happy Easter Egg.","Surprise!",wxICON_INFORMATION);
		*_eea = false;
		return;
	}
	CheckClosingFile();	
	int firstAnswer = _openFile->ShowModal();
	if(firstAnswer == wxID_OK){
		CleanUp();
		myManager->OpenDB((string)_openFile->GetPath());
		string _lu = myManager->GetLastUpdate();
		transform(_lu.begin(),_lu.end(),_lu.begin(),::toupper);
		m_statusBar->SetStatusText("Base de datos abierta. Ultima Actualización: " + _lu);
		myManager->LogIt("Abriendo base de datos. " + myManager->GetFilePath() + " Ultima Actualización: " + _lu);	
		if(myManager->GetSize() > 0)
			wxGridMain->SelectRow(0);
		if(!myManager->GetSearchStatusMode()){ //Assertion.
			LoadBooksInGrid();
		} else {
			wxMessageBox("ERROR inesperado. Llamar al tecnico. osea a Alexis o Ramiro.","ERROR!",wxICON_ERROR);
		}
	}
}

void windowMain::btnTool_SaveDB (wxCommandEvent& event){
	int ModalAnswer;
	if(myManager->IsAnyChange()){
		string Mystring = myManager->GetFilePath();
		if(Mystring.size() > 0){
			int answer = wxMessageBox("Desea sobreescribir la base de datos actual?", "Guardar base de datos", wxICON_QUESTION | wxYES_NO);
			if(answer == wxYES){
				myManager->SaveDB();
				string _lu = myManager->GetLastUpdate();
				transform(_lu.begin(),_lu.end(),_lu.begin(),::toupper);
				m_statusBar->SetStatusText("Base de datos Guardada. " + _lu);
				myManager->LogIt("Guadrando base de datos. " + myManager->GetFilePath() + " :: " + _lu);
			}
			else{
				ModalAnswer = _sourceFile->ShowModal();
				if(ModalAnswer == wxID_OK){
					myManager->SaveDB((string) _sourceFile->GetPath());
					string _lu = myManager->GetLastUpdate();
					transform(_lu.begin(),_lu.end(),_lu.begin(),::toupper);
					m_statusBar->SetStatusText("Base de datos Guardada. " + _lu);
					myManager->LogIt("Guadrando base de datos. " + myManager->GetFilePath() + " :: " + _lu);
				}				
			}
		} else {
			ModalAnswer = _sourceFile->ShowModal();
			if(ModalAnswer == wxID_OK){
				myManager->SaveDB((string) _sourceFile->GetPath());
				string _lu = myManager->GetLastUpdate();
				transform(_lu.begin(),_lu.end(),_lu.begin(),::toupper);
				m_statusBar->SetStatusText("Base de datos Guardada. " + _lu);
				myManager->LogIt("Guadrando base de datos. " + myManager->GetFilePath() + " :: " + _lu);
			}
		}
	} else {
		int answer = wxMessageBox("No se realizo ninguna modificacion de datos.\nDesea Guardar de todos modos?", "Guardar base de datos", wxICON_QUESTION | wxYES_NO);
		if(answer ==wxYES){
			ModalAnswer = _sourceFile->ShowModal();
			if(ModalAnswer == wxID_OK){
				myManager->SaveDB((string) _sourceFile->GetPath());
				string _lu = myManager->GetLastUpdate();
				transform(_lu.begin(),_lu.end(),_lu.begin(),::toupper);
				m_statusBar->SetStatusText("Base de datos Guardada. " + _lu);
				myManager->LogIt("Guadrando base de datos. " + myManager->GetFilePath() + " :: " + _lu);
			}
		}
	}
}
	

void windowMain::btnTool_InfoBook (wxCommandEvent& event){
	if(myManager->GetSize()==0) return;
	stringstream o;
	cBook* tmpBook;
	myManager->GetBook(_idSelected, &tmpBook);
	sCategory cat;
	myManager->GetCategory(tmpBook->GetCategory(),cat);
	o << "Editorial: " << tmpBook->GetEditorial() << "\n" << "Autor: " << tmpBook->GetAuthor() << "\n" << "Título: " << tmpBook->GetTitle() << "\n" << "ISBN: " << tmpBook->GetISBN() << "\n" << "Precio: $" << tmpBook->GetPrice() << "\n"<< "Stock: " << tmpBook->GetStock() << "\n" << "Categoria: " << cat._nameCategory<< "\n" << "Páginas: " << tmpBook->GetPages() << "\n" << "Peso: " << tmpBook->GetWeight();
	wxMessageBox(o.str(),"Información",wxICON_INFORMATION);	
} 

void windowMain::btnTool_AddBook (wxCommandEvent& event){
	new windowAuthor(this);
}

void windowMain::btnTool_EditBook (wxCommandEvent& event){
	if(_idSelected != -1) {
		new windowAuthor(this,1);
	}
}
void windowMain::btnTool_DeleteBook ( wxCommandEvent& event ){
	if(_idSelected != -1) {
		int answer = wxMessageBox("Esta seguro que desea eliminar libro?", "Eliminar", wxICON_INFORMATION | wxYES_NO);
		if(answer == wxYES){
			cBook* tmpCBook;
			myManager->GetBook(_idSelected,&tmpCBook);
			string _lu = myManager->GetLastUpdate();
			myManager->LogIt("Eliminado libro: " + tmpCBook->GetTitle() + " :: " + _lu);
			transform(_lu.begin(),_lu.end(),_lu.begin(),::toupper);
			m_statusBar->SetStatusText("Eliminado libro: " + tmpCBook->GetTitle() + " :: " + _lu);
			delete tmpCBook;
			myManager->RemoveBook(_idSelected);
			ReloadGrid();
		}
		if(myManager->GetSize()==0) {
			m_toolBar1->EnableTool(1006,false);		
		} else {
			m_toolBar1->EnableTool(1006,true);		
		}
	}
	
}

void windowMain::btnTool_Log ( wxCommandEvent& event ){
	new windowLog(this);	
}

void windowMain::btnTool_Help ( wxCommandEvent& event ){
	ShellExecute(NULL, "open", "help\\index.html", NULL, NULL, SW_SHOWNORMAL);
}

void windowMain::btn_SearchOnRightDClick (wxMouseEvent& event ){
	new windowSearch(this); 
}

void windowMain::btnTool_Sell ( wxCommandEvent& event ){
	if(_idSelected != -1){
		bool _auxStatusSearchMode = myManager->GetSearchStatusMode();
		myManager->SetStockOnSellcBook(-1,_idSelected);
		int a = _idSelected;
		cBook* tmpCBook;
		myManager->GetBook(_idSelected,&tmpCBook);
		myManager->SetLastUpdate();
		string _lu = myManager->GetLastUpdate();
		myManager->LogIt("Vendido libro: " + tmpCBook->GetTitle() + " :: " + _lu);
		m_statusBar->SetStatusText("Vendido libro: " + tmpCBook->GetTitle() + " :: " + _lu);
		ReloadGrid();
		wxGridMain->SelectRow(a);
		m_TextBoxSearch->Clear();
		
		//selecciona el ultimo libro seleccionado previamente
		_idSelected = a;
		wxGridMain->SelectRow(a);
	
		if(tmpCBook->GetStock() <= 0)
			m_toolBar1->EnableTool(1009,false);
		else
			m_toolBar1->EnableTool(1009,true);			
		
		delete tmpCBook;
		
		//Guarda si se trabaja sobre una database existente
		
			if(myManager->GetSearchStatusMode())
				myManager->ChangeSearchStatusMode();
			myManager->SaveDB();
			if(_auxStatusSearchMode ==true)
				myManager->ChangeSearchStatusMode();
	}
}

void windowMain::btnEvent_Search (wxCommandEvent& event ) {
	
	string criteria = (string)m_TextBoxSearch->GetValue();
	transform(criteria.begin(),criteria.end(),criteria.begin(),::tolower);
	size_t ee = criteria.find("messupmydear666!");
	if(criteria.size() == 16 && ee == 0) {
		*_eea = true;		
	}
	
	myManager->Search(criteria, searchOpSetted);
	ReloadGrid();
}

void windowMain::stop_SearchOnButtonClick( wxCommandEvent& event )  {
	if(myManager->GetSearchStatusMode()){
		myManager->ChangeSearchStatusMode();
		m_TextBoxSearch->Clear();
	}
	ReloadGrid();
}


void windowMain::wxGridMainOnGridLabelLeftClick (wxGridEvent& event ) {
	int col = event.GetCol();	
	switch(col){
		case 0:
			myManager->Sort(SORT_BY_EDITORIAL);
			break;
		case 1:
			myManager->Sort(SORT_BY_AUTHOR);
			break;
		case 2:
			myManager->Sort(SORT_BY_TITLE);
			break;
		case 3:
			return;
	}
	ReloadGrid();
}

void windowMain::ReloadGrid() {
	while(wxGridMain->DeleteRows());
	LoadBooksInGrid();
}

void windowMain::wxGridMainOnGridSelectCell ( wxGridEvent& event ){
	m_toolBar1->EnableTool(1006,true);
	int row = event.GetRow();
	_idSelected = row;
	wxString stock = wxGridMain->GetCellValue(row,4);
	int _stock = atoi(stock.c_str());
	
	if(_stock > 0){
		m_toolBar1->EnableTool(1009,true);
	} else {
		m_toolBar1->EnableTool(1009,false);
	}
}

windowLog::windowLog(wxWindow* parent) : wxLogger(parent) {
	ifstream logFile("wxRamLexBSM.log.txt");
	if(logFile.is_open()){
		char tmp[500];
		while(logFile.getline(tmp,500)){
			m_TextPool->AppendText(tmp);
			m_TextPool->AppendText("\n");
		}
	} else {
		m_TextPool->AppendText("ERROR. No se encuentra el archivo wxRamLexBSM.log.txt. Asegurese de no haberle cambiado el nombre.");
	}
	SetIcon(wxIcon("icons/ico.png", wxBITMAP_TYPE_PNG, 32, 32));
	Show();
}

windowAuthor::windowAuthor(wxWindow* parent, int mode) : wxAuthor(parent) {
	sCategory tmpSCategory;
	_Mode = mode;
	int c = myManager->LoadCategories();
	if(c==-1){
		wxMessageBox("El archivo wxRamLexCategories.dat no existe o esta dañado.\nBuscar wxRamLexCategories.dat.bak y renombrar.","Error!",wxICON_ERROR);
	} else {
		for(int i=0;i<c;i++){			
			myManager->GetCategory(i, tmpSCategory);
			comboBox_Category->Insert(tmpSCategory._nameCategory, i);
		}
		comboBox_Category->Select(0);
		SetIcon(wxIcon("icons/ico.png", wxBITMAP_TYPE_PNG, 32, 32));
		parent->Disable();		
		if(mode == 0){ //Add mode.
			SetTitle("Agregar Libro");
			btn_OK->SetLabel("Agregar");
			label_Stock->SetLabel("0");
		} else { //Modify mode.
			SetTitle("Modificar Libro");
			btn_OK->SetLabel("Modificar");
			cBook* tmpCBook;
			myManager->GetBook(_idSelected,&tmpCBook);			
			Tb_author->SetValue(tmpCBook->GetAuthor());
			Tb_editorial->SetValue(tmpCBook->GetEditorial());
			Tb_isbn->SetValue(tmpCBook->GetISBN());
			Tb_paginas->SetValue(wxString::Format(wxT("%i"), tmpCBook->GetPages()));
			Tb_peso->SetValue(wxString::Format(wxT("%f"), tmpCBook->GetWeight()));
			Tb_precio->SetValue(wxString::Format(wxT("%f"), tmpCBook->GetPrice()));
			Tb_title->SetValue(tmpCBook->GetTitle());
			sCategory tmpCategoria;
			myManager->GetCategory(tmpCBook->GetCategory(), tmpCategoria);
			comboBox_Category->SetSelection(tmpCategoria._idCategory);
			label_Stock->SetLabel(wxString::Format(wxT("%i"), tmpCBook->GetStock()));	
			delete tmpCBook;
		}
		Show();
	}
}

void windowAuthor::btnCancel_OnClick ( wxCommandEvent& event ){
	myParent->Enable();
	Destroy();
}

void windowAuthor::wxAuthorOnClose( wxCloseEvent& event ){
	myParent->Enable();
	Destroy();
}


void windowAuthor::btnOKnSave_OnClick( wxCommandEvent& event ){
	sBook tmpSBook;
	string tmpStr;
	tmpStr = string(Tb_author->GetValue());
	strcpy(tmpSBook._author, tmpStr.c_str());	
	tmpStr = string(Tb_editorial->GetValue());
	strcpy(tmpSBook._editorial, tmpStr.c_str());
	tmpStr = string(Tb_isbn->GetValue());
	strcpy(tmpSBook._isbn, tmpStr.c_str());
	tmpStr = string(Tb_title->GetValue());
	strcpy(tmpSBook._title, tmpStr.c_str());
	tmpSBook._price = (float) atof((std::string(Tb_precio->GetValue())).c_str());
	tmpSBook._weight = (float) atof((std::string(Tb_peso->GetValue())).c_str());
	tmpSBook._pages = (int) atoi((std::string(Tb_paginas->GetValue())).c_str());
	tmpSBook._stock = (int) atoi((std::string(label_Stock->GetLabel())).c_str());
	tmpSBook._idCategory = comboBox_Category->GetSelection();
	myManager->SetLastUpdate();
	cBook MyTmpBook(tmpSBook);
	ValidationTexts OnValidate = myManager->ValidateBookData(MyTmpBook);
	stringstream ErrorText;
	if( !OnValidate.isanyerror ){
		if(_Mode == 0){
			cBook tmpCBookForAdd(tmpSBook);
			if(myManager->ValidateIsbn(tmpCBookForAdd)){
				myManager->AddBook(tmpCBookForAdd);
				string _lu = myManager->GetLastUpdate();
				transform(_lu.begin(),_lu.end(),_lu.begin(),::toupper);
				/*m_statusBar->SetStatusText("Base de datos Guardada. " + _lu);*/
				myManager->LogIt("Agregando Libro. " + (string)tmpSBook._title + " :: " + _lu);
				windowMain* x = (windowMain*)myParent;
				x->ReloadGrid();
				myParent->Enable();
				Destroy();
			} else {
				wxMessageBox( "<ISBN> Fuera de rango, debe ser de 13 digitos. (o ya existente)", "Error", wxICON_ERROR);
			}
		} else {
				cBook tmpCBookForReplacement(tmpSBook);
				string ISBNerased = myManager->EraseISBN(_idSelected);
				if(myManager->ValidateIsbn(tmpCBookForReplacement)){
					myManager->ReplaceBook(_idSelected,tmpSBook);
					string _lu = myManager->GetLastUpdate();
					transform(_lu.begin(),_lu.end(),_lu.begin(),::toupper);
					myManager->LogIt("Editando Libro. " + (string) tmpSBook._title + " :: " + _lu);
					if(myManager->GetSearchStatusMode())
						myManager->ChangeSearchStatusMode();
					windowMain* x = (windowMain*)myParent;
					x->ReloadGrid();
					myParent->Enable();
					Destroy();
				} else {
					wxMessageBox( "<ISBN> Fuera de rango, debe ser de 13 digitos. (o ya existente)", "Error", wxICON_ERROR);
				}
		}
	} else {
		if(OnValidate._erroroneditorial.size() != 0)
			ErrorText<<OnValidate._erroroneditorial<<'\n';
		if(OnValidate._erroronauthor.size() != 0)
			ErrorText<<OnValidate._erroronauthor<<'\n';
		if(OnValidate._errorontitle.size() != 0)
			ErrorText<<OnValidate._errorontitle<<'\n';
		if(OnValidate._erroronprice.size() != 0)
			ErrorText<<OnValidate._erroronprice<<'\n';
		if(OnValidate._erroronpages.size() != 0)
			ErrorText<<OnValidate._erroronpages<<'\n';
		if(OnValidate._erroronweight.size() != 0)
			ErrorText<<OnValidate._erroronweight<<'\n';
		if(OnValidate._erroronstock.size() != 0)
			ErrorText<<OnValidate._erroronstock<<'\n';		
		wxMessageBox( ErrorText.str(), "Error", wxICON_ERROR);
	}
	OnValidate.isanyerror = false;
}
void windowAuthor::Btn_lessOnButtonClick( wxCommandEvent& event){
	int x = (int) atoi((std::string(label_Stock->GetLabel())).c_str());
	x -= 1;
	if(x>0)
		label_Stock->SetLabel(wxString::Format(wxT("%i"),x));
	else
		label_Stock->SetLabel("0");
}
void windowAuthor::Btn_moreOnButtonClick( wxCommandEvent& event ){
	int x = (int) atoi((std::string(label_Stock->GetLabel())).c_str());
	x += 1;
	label_Stock->SetLabel(wxString::Format(wxT("%i"),x));
}

void windowAuthor::Btn_moreThanOneButtonClick( wxMouseEvent& event )  {
	wxString MyCantStockText = wxGetTextFromUser("Cantidad:", "+ Stock", "0");
	int _SetStockCant = ((int) atoi((std::string(MyCantStockText)).c_str())) + ((int) atoi((std::string(label_Stock->GetLabel())).c_str()));;
	if (_SetStockCant >= 0){
		
		label_Stock->SetLabel(wxString::Format(wxT("%i"),_SetStockCant));
	}
	else{
		wxMessageBox("<Stock> no puede ser un numero negativo","Error",wxICON_ERROR);
	}
}

void windowAuthor::Btn_lessThanOneButtonClick( wxMouseEvent& event )  {
	wxString MyCantStockText = wxGetTextFromUser("Cantidad:", "- Stock","0");
	int _SetStockCant = (((int) atoi((std::string(label_Stock->GetLabel())).c_str())) - ((int) atoi((std::string(MyCantStockText)).c_str())));
	if (_SetStockCant >= 0){
		label_Stock->SetLabel(wxString::Format(wxT("%i"),_SetStockCant));
	}
	else{
		stringstream TextToShow;
		TextToShow<<"<Stock> no puede ser un numero negativo\n OOPS!, te pasaste por: "<< (-1) * _SetStockCant;
		wxMessageBox(TextToShow.str(),"Error",wxICON_ERROR);
	}
}

windowSearch::windowSearch(wxWindow* parent) : wxSearchOps(parent) {
	ShowModal();
}

void windowSearch::btn_SetSearchOpsOnButtonClick( wxCommandEvent& event )  {
	switch(m_radioBox1->GetSelection()){
	case 0:
		searchOpSetted = SEARCH_BY_TITLE;
		break;
	case 1:
		searchOpSetted = SEARCH_BY_EDITORIAL;
		break;
	case 2:
		searchOpSetted = SEARCH_BY_AUTHOR;
		break;
	case 3:
		searchOpSetted = SEARCH_BY_ISBN;
		break;
	}
	Destroy();
}

wxFileDialog* _sourceFile;
wxFileDialog* _openFile;
bool* _eea;
int _idSelected = -1;
wxWindow* myParent;

void windowMain::wxMainOnClose( wxCloseEvent& event )  {
	CheckClosingFile();
	Destroy();
}

