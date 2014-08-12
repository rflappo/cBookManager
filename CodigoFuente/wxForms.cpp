///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxForms.h"

///////////////////////////////////////////////////////////////////////////

wxMain::wxMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );
	
	m_toolBar1 = new wxToolBar( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	m_toolBar1->AddTool( btn1, wxT("tool"), wxBitmap( wxT("icons/addDB.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Nueva DB ..."), wxEmptyString ); 
	m_toolBar1->AddTool( btn2, wxT("tool"), wxBitmap( wxT("icons/openDB.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Abrir DB ..."), wxEmptyString ); 
	m_toolBar1->AddTool( btn3, wxT("tool"), wxBitmap( wxT("icons/saveDB.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Guardar DB ..."), wxEmptyString ); 
	m_toolBar1->AddSeparator(); 
	m_toolBar1->AddSeparator(); 
	m_toolBar1->AddTool( btn4, wxT("tool"), wxBitmap( wxT("icons/infoBook.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Detalles del libro ..."), wxEmptyString ); 
	m_toolBar1->AddTool( btn5, wxT("tool"), wxBitmap( wxT("icons/addBook.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Agregar libro ..."), wxEmptyString ); 
	m_toolBar1->AddTool( btn6, wxT("tool"), wxBitmap( wxT("icons/editBook.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Editar libro ..."), wxEmptyString ); 
	m_toolBar1->AddTool( btn7, wxT("tool"), wxBitmap( wxT("icons/deleteBook.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Eliminar libro ..."), wxEmptyString ); 
	m_toolBar1->AddSeparator(); 
	m_toolBar1->AddSeparator(); 
	m_toolBar1->AddTool( btn8, wxT("tool"), wxBitmap( wxT("icons/log.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Log ..."), wxEmptyString ); 
	m_toolBar1->AddSeparator(); 
	m_toolBar1->AddSeparator(); 
	m_toolBar1->AddTool( btn9, wxT("tool"), wxBitmap( wxT("icons/help.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Ayuda ..."), wxEmptyString ); 
	m_toolBar1->AddSeparator(); 
	m_toolBar1->AddSeparator(); 
	m_toolBar1->AddTool( btn10, wxT("tool"), wxBitmap( wxT("icons/sellBook.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Vender libro ..."), wxEmptyString ); 
	m_toolBar1->Realize();
	
	bSizer171->Add( m_toolBar1, 1, wxEXPAND, 5 );
	
	bSizer17->Add( bSizer171, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( m_panel1, wxID_ANY, wxT("Buscar:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer21->Add( m_staticText6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 10 );
	
	m_TextBoxSearch = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_TextBoxSearch, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	btn_Search = new wxBitmapButton( m_panel1, wxID_ANY, wxBitmap( wxT("icons/searchHover.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	
	btn_Search->SetBitmapSelected( wxBitmap( wxT("icons/search.png"), wxBITMAP_TYPE_ANY ) );
	bSizer21->Add( btn_Search, 0, wxALL, 5 );
	
	stop_Search = new wxBitmapButton( m_panel1, wxID_ANY, wxBitmap( wxT("icons/stop.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer21->Add( stop_Search, 0, wxALL, 5 );
	
	bSizer17->Add( bSizer21, 0, wxEXPAND, 5 );
	
	wxGridMain = new wxGrid( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	wxGridMain->CreateGrid( 0, 5 );
	wxGridMain->EnableEditing( false );
	wxGridMain->EnableGridLines( true );
	wxGridMain->EnableDragGridSize( false );
	wxGridMain->SetMargins( 0, 0 );
	
	// Columns
	wxGridMain->SetColSize( 0, 170 );
	wxGridMain->SetColSize( 1, 213 );
	wxGridMain->SetColSize( 2, 350 );
	wxGridMain->SetColSize( 3, 132 );
	wxGridMain->SetColSize( 4, 78 );
	wxGridMain->EnableDragColMove( false );
	wxGridMain->EnableDragColSize( true );
	wxGridMain->SetColLabelSize( 30 );
	wxGridMain->SetColLabelValue( 0, wxT("Editorial") );
	wxGridMain->SetColLabelValue( 1, wxT("Autor") );
	wxGridMain->SetColLabelValue( 2, wxT("Titulo") );
	wxGridMain->SetColLabelValue( 3, wxT("ISBN") );
	wxGridMain->SetColLabelValue( 4, wxT("Stock") );
	wxGridMain->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	wxGridMain->EnableDragRowSize( false );
	wxGridMain->SetRowLabelSize( 0 );
	wxGridMain->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	wxGridMain->SetDefaultCellFont( wxFont( 10, 74, 90, 90, false, wxT("Courier New") ) );
	wxGridMain->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	bSizer17->Add( wxGridMain, 1, wxEXPAND|wxALL, 0 );
	
	m_panel1->SetSizer( bSizer17 );
	m_panel1->Layout();
	bSizer17->Fit( m_panel1 );
	bSizer14->Add( m_panel1, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( bSizer14 );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wxMain::wxMainOnClose ) );
	this->Connect( btn1, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_NewDB ) );
	this->Connect( btn2, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_OpenDB ) );
	this->Connect( btn3, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_SaveDB ) );
	this->Connect( btn4, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_InfoBook ) );
	this->Connect( btn5, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_AddBook ) );
	this->Connect( btn6, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_EditBook ) );
	this->Connect( btn7, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_DeleteBook ) );
	this->Connect( btn8, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_Log ) );
	this->Connect( btn9, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_Help ) );
	this->Connect( btn10, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_Sell ) );
	btn_Search->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::btnEvent_Search ), NULL, this );
	btn_Search->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( wxMain::btn_SearchOnRightDClick ), NULL, this );
	stop_Search->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::stop_SearchOnButtonClick ), NULL, this );
	wxGridMain->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( wxMain::wxGridMainOnGridLabelLeftClick ), NULL, this );
	wxGridMain->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( wxMain::wxGridMainOnGridSelectCell ), NULL, this );
}

wxMain::~wxMain()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wxMain::wxMainOnClose ) );
	this->Disconnect( btn1, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_NewDB ) );
	this->Disconnect( btn2, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_OpenDB ) );
	this->Disconnect( btn3, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_SaveDB ) );
	this->Disconnect( btn4, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_InfoBook ) );
	this->Disconnect( btn5, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_AddBook ) );
	this->Disconnect( btn6, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_EditBook ) );
	this->Disconnect( btn7, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_DeleteBook ) );
	this->Disconnect( btn8, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_Log ) );
	this->Disconnect( btn9, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_Help ) );
	this->Disconnect( btn10, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxMain::btnTool_Sell ) );
	btn_Search->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::btnEvent_Search ), NULL, this );
	btn_Search->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( wxMain::btn_SearchOnRightDClick ), NULL, this );
	stop_Search->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::stop_SearchOnButtonClick ), NULL, this );
	wxGridMain->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( wxMain::wxGridMainOnGridLabelLeftClick ), NULL, this );
	wxGridMain->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( wxMain::wxGridMainOnGridSelectCell ), NULL, this );
	
}

wxLogger::wxLogger( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_TextPool = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH|wxTE_RICH2|wxTE_WORDWRAP );
	bSizer6->Add( m_TextPool, 1, wxALL|wxEXPAND, 5 );
	
	m_panel2->SetSizer( bSizer6 );
	m_panel2->Layout();
	bSizer6->Fit( m_panel2 );
	bSizer5->Add( m_panel2, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

wxLogger::~wxLogger()
{
}

wxAuthor::wxAuthor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_panel3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( m_panel3, wxID_ANY, wxT("Editorial:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer9->Add( m_staticText2, 0, wxALL, 8 );
	
	Tb_editorial = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( Tb_editorial, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer9, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( m_panel3, wxID_ANY, wxT("Autor:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer10->Add( m_staticText3, 0, wxALL, 8 );
	
	Tb_author = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( Tb_author, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( m_panel3, wxID_ANY, wxT("Titulo:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText31->Wrap( -1 );
	m_staticText31->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer101->Add( m_staticText31, 0, wxALL, 8 );
	
	Tb_title = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer101->Add( Tb_title, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer101, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer102;
	bSizer102 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32 = new wxStaticText( m_panel3, wxID_ANY, wxT("ISBN:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText32->Wrap( -1 );
	m_staticText32->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer102->Add( m_staticText32, 0, wxALL, 8 );
	
	Tb_isbn = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer102->Add( Tb_isbn, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer102, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer103;
	bSizer103 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText33 = new wxStaticText( m_panel3, wxID_ANY, wxT("Precio:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText33->Wrap( -1 );
	m_staticText33->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer103->Add( m_staticText33, 0, wxALL, 8 );
	
	Tb_precio = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer103->Add( Tb_precio, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer103, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer104;
	bSizer104 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText34 = new wxStaticText( m_panel3, wxID_ANY, wxT("Paginas:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText34->Wrap( -1 );
	m_staticText34->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer104->Add( m_staticText34, 0, wxALL, 8 );
	
	Tb_paginas = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer104->Add( Tb_paginas, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer104, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer105;
	bSizer105 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText35 = new wxStaticText( m_panel3, wxID_ANY, wxT("Peso:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText35->Wrap( -1 );
	m_staticText35->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer105->Add( m_staticText35, 0, wxALL, 8 );
	
	Tb_peso = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer105->Add( Tb_peso, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer105, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer106;
	bSizer106 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText36 = new wxStaticText( m_panel3, wxID_ANY, wxT("Stock:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText36->Wrap( -1 );
	m_staticText36->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer106->Add( m_staticText36, 0, wxALL, 8 );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );
	
	label_Stock = new wxStaticText( m_panel3, wxID_ANY, wxT("::value::"), wxDefaultPosition, wxDefaultSize, 0 );
	label_Stock->Wrap( -1 );
	bSizer30->Add( label_Stock, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer106->Add( bSizer30, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	Btn_more = new wxButton( m_panel3, wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer106->Add( Btn_more, 0, wxALL, 5 );
	
	Btn_less = new wxButton( m_panel3, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer106->Add( Btn_less, 0, wxALL, 5 );
	
	bSizer8->Add( bSizer106, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1061;
	bSizer1061 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText361 = new wxStaticText( m_panel3, wxID_ANY, wxT("Categoria:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText361->Wrap( -1 );
	m_staticText361->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer1061->Add( m_staticText361, 0, wxALL, 8 );
	
	wxArrayString comboBox_CategoryChoices;
	comboBox_Category = new wxChoice( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, comboBox_CategoryChoices, 0 );
	comboBox_Category->SetSelection( 0 );
	bSizer1061->Add( comboBox_Category, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer1061, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );
	
	bSizer27->Add( bSizer29, 1, wxEXPAND, 5 );
	
	btn_OK = new wxButton( m_panel3, wxID_ANY, wxT("setValue"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( btn_OK, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	btnCancel = new wxButton( m_panel3, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( btnCancel, 0, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer8->Add( bSizer27, 0, wxALL|wxEXPAND, 5 );
	
	m_panel3->SetSizer( bSizer8 );
	m_panel3->Layout();
	bSizer8->Fit( m_panel3 );
	bSizer7->Add( m_panel3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wxAuthor::wxAuthorOnClose ) );
	Btn_more->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthor::Btn_moreOnButtonClick ), NULL, this );
	Btn_more->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( wxAuthor::Btn_moreThanOneButtonClick ), NULL, this );
	Btn_less->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthor::Btn_lessOnButtonClick ), NULL, this );
	Btn_less->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( wxAuthor::Btn_lessThanOneButtonClick ), NULL, this );
	btn_OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthor::btnOKnSave_OnClick ), NULL, this );
	btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthor::btnCancel_OnClick ), NULL, this );
}

wxAuthor::~wxAuthor()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wxAuthor::wxAuthorOnClose ) );
	Btn_more->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthor::Btn_moreOnButtonClick ), NULL, this );
	Btn_more->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( wxAuthor::Btn_moreThanOneButtonClick ), NULL, this );
	Btn_less->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthor::Btn_lessOnButtonClick ), NULL, this );
	Btn_less->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( wxAuthor::Btn_lessThanOneButtonClick ), NULL, this );
	btn_OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthor::btnOKnSave_OnClick ), NULL, this );
	btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthor::btnCancel_OnClick ), NULL, this );
	
}

wxSearchOps::wxSearchOps( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	m_panel4 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_radioBox1Choices[] = { wxT("Titulo"), wxT("Editorial"), wxT("Autor"), wxT("ISBN") };
	int m_radioBox1NChoices = sizeof( m_radioBox1Choices ) / sizeof( wxString );
	m_radioBox1 = new wxRadioBox( m_panel4, wxID_ANY, wxT("Busqueda"), wxDefaultPosition, wxDefaultSize, m_radioBox1NChoices, m_radioBox1Choices, 1, wxRA_SPECIFY_COLS );
	m_radioBox1->SetSelection( 0 );
	bSizer24->Add( m_radioBox1, 0, wxALIGN_BOTTOM|wxFIXED_MINSIZE|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	bSizer23->Add( bSizer24, 0, wxEXPAND, 5 );
	
	bSizer22->Add( bSizer23, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	btn_SetSearchOps = new wxButton( m_panel4, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( btn_SetSearchOps, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panel4->SetSizer( bSizer22 );
	m_panel4->Layout();
	bSizer22->Fit( m_panel4 );
	bSizer21->Add( m_panel4, 1, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 0 );
	
	this->SetSizer( bSizer21 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btn_SetSearchOps->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxSearchOps::btn_SetSearchOpsOnButtonClick ), NULL, this );
}

wxSearchOps::~wxSearchOps()
{
	// Disconnect Events
	btn_SetSearchOps->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxSearchOps::btn_SetSearchOpsOnButtonClick ), NULL, this );
	
}
