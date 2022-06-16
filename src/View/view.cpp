#include "view.h"
#include "controler.h"

//************************************************************************
//************************* class MyControlPanel *************************
//************************************************************************

//------------------------------------------------------------------------
MyControlPanel::MyControlPanel(wxWindow *parent) : wxPanel(parent)
// In this constructor, create the controls and associate each of them (bind) a method
{
	int w, h, y ;
	GetParent()->GetSize(&w,&h) ;
	SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;
	SetBackgroundColour(*wxLIGHT_GREY) ;

	m_parentFrame = (MyFrame *) parent ;

	y = WIDGET_Y0 ;
	m_button = new wxButton(this, ID_BUTTON1, wxT("Click me"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButton, this, ID_BUTTON1) ;

	y+= WIDGET_Y_STEP ;
	wxStaticText* text1 = new wxStaticText(this, wxID_ANY, wxT("Radius"), wxPoint(10, y)) ;

	y+= 15 ;
	m_slider = new wxSlider(this, ID_SLIDER1, 10, 2, 100, wxPoint(10, y), wxSize(100,20), wxSL_LABELS) ;
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_SLIDER1) ;

	y+= WIDGET_Y_STEP ;
	m_checkBox = new wxCheckBox(this, ID_CHECKBOX1, "Show (x,y)", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ;

	y+= WIDGET_Y_STEP ;
	m_buttonRectangle = new wxButton(this, ID_BUTTON_RECT, wxT("Rectangle"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonRectangle, this, ID_BUTTON_RECT) ;

	y+= WIDGET_Y_STEP ;
	m_buttonOval = new wxButton(this, ID_BUTTON_OVAL, wxT("Ovale"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonOval, this, ID_BUTTON_OVAL) ;

	y+= WIDGET_Y_STEP ;
	m_buttonLine = new wxButton(this, ID_BUTTON_LINE, wxT("Ligne"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonLine, this, ID_BUTTON_LINE) ;

	y+= WIDGET_Y_STEP + 10 ;
	m_buttonLine = new wxButton(this, ID_BUTTON_SELECT, wxT("Sélection"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonSelection, this, ID_BUTTON_SELECT) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnButton(wxCommandEvent &event)
{
	wxMessageBox(wxT("You just pressed the button!")) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnSlider(wxScrollEvent &event)
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnCheckBox(wxCommandEvent &event)
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonRectangle(wxCommandEvent &event)
{
	m_parentFrame->GetControler()->SetModeId(ID_MODE_FORM) ;
	m_parentFrame->GetControler()->SetFormId(ID_RECT) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonOval(wxCommandEvent &event)
{
	m_parentFrame->GetControler()->SetModeId(ID_MODE_FORM) ;
	m_parentFrame->GetControler()->SetFormId(ID_OVAL) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonLine(wxCommandEvent &event)
{
	m_parentFrame->GetControler()->SetModeId(ID_MODE_FORM) ;
	m_parentFrame->GetControler()->SetFormId(ID_LINE) ;
}

void MyControlPanel::OnButtonSelection(wxCommandEvent &event)
{
	m_parentFrame->GetControler()->SetModeId(ID_MODE_SELECTION) ;
	m_parentFrame->GetControler()->SetFormId(ID_FORM_NONE) ;

}


//************************************************************************
//************************* class MyDrawingPanel *************************
//************************************************************************

//------------------------------------------------------------------------
MyDrawingPanel::MyDrawingPanel(wxWindow *parent) : wxPanel(parent)
// In this constructor, bind some mouse events and the paint event with the appropriate methods
{
	int w, h ;
	GetParent()->GetClientSize(&w,&h) ;
	SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH,0), wxPoint(w, h))) ;
	SetBackgroundColour(wxColour(0xFF,0xFF,0xFF)) ;
	Bind(wxEVT_MOTION, &MyDrawingPanel::OnMouseMove, this);
	Bind(wxEVT_LEFT_DOWN, &MyDrawingPanel::OnMouseLeftDown, this);
	Bind(wxEVT_PAINT, &MyDrawingPanel::OnPaint, this) ;
	Bind(wxEVT_LEFT_UP, &MyDrawingPanel::OnMouseLeftUp, this);
	m_parentFrame = (MyFrame *) parent ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent &event)
// called when the mouse left button is pressed
{
	m_parentFrame->GetControler()->SetMouseId(ID_MOUSELEFTDOWN) ;
	int mode = m_parentFrame->GetControler()->GetModeId() ;
	switch (mode)
	{
		case ID_MODE_SELECTION :
		{
			m_parentFrame->GetControler()->SelectionForm(event.m_x, event.m_y) ;
			break ;
		}
		case ID_MODE_FORM :
		{
			m_parentFrame->GetControler()->FormCreation(event.m_x, event.m_y) ;
			break ;
		}
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent &event)
// called when the mouse is moved
{
	m_parentFrame->GetControler()->FormModification(event.m_x, event.m_y) ;
	Refresh() ;	// send an event that calls the OnPaint method
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftUp(wxMouseEvent &event)
{
	m_parentFrame->GetControler()->SetMouseId(ID_MOUSELEFTUP) ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnPaint(wxPaintEvent &event)
// called automatically when the panel is shown for the first time or
// when the panel is resized
// You have to call OnPaint with Refresh() when you need to update the panel content
{
	wxPaintDC dc(this);
	m_parentFrame->GetControler()->GetDessin().drawAllFormes(dc) ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::OpenFile(wxString fileName)
{
	// just to open (and close) any file
	FILE* f = fopen(fileName, "r") ;
	if (f)
	{
		wxMessageBox(wxT("The file was opened then closed")) ;
		fclose(f) ;
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::SaveFile(wxString fileName)
{
	m_parentFrame->GetControler()->GetDessin().saveSVG(fileName.mb_str());
	wxMessageBox(wxT("The file was saved")) ;
}



//************************************************************************
//**************************** class MyFrame *****************************
//************************************************************************

//------------------------------------------------------------------------
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
       : wxFrame((wxFrame *)NULL, -1, title, pos, size)
// The constructor of the main frame that creates the menu stuffs and the 2 panels
{
	wxMenu *fileMenu = new wxMenu();
	fileMenu->Append(ID_LOAD, wxT("&Open file..."));
	fileMenu->Append(ID_SAVE, wxT("&Save file..."));
	fileMenu->Append(ID_ABOUT, wxT("&About..."));
	fileMenu->AppendSeparator();
	fileMenu->Append(ID_QUIT, wxT("&Exit"));

	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, wxT("&File"));

	Bind(wxEVT_MENU, &MyFrame::OnOpenFile, this, ID_LOAD);
	Bind(wxEVT_MENU, &MyFrame::OnSaveFile, this, ID_SAVE);
	Bind(wxEVT_MENU, &MyFrame::OnQuit, this, ID_QUIT);
	Bind(wxEVT_MENU, &MyFrame::OnAbout, this, ID_ABOUT);
	Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);
	Bind(wxEVT_SIZE, &MyFrame::OnSize, this);

	SetMenuBar( menuBar );

// create the panel that will contain the controls
	m_controlPanel = new MyControlPanel(this);
// create the panel that will display the graphics
	m_drawingPanel = new MyDrawingPanel(this);
	CreateStatusBar() ;
	SetStatusText(wxT("click in the right panel and tune the controls of the left panel. Visit the File menu!")) ;
	Centre() ; // Guess what it does ;-)
}

void MyFrame::SetControler (Controler * controler)
{
	m_controler = controler ;
}

//------------------------------------------------------------------------
void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	GetControler()->GetDessin().saveSVG("fichier.svg") ;
	Close(true) ;
}

//------------------------------------------------------------------------
void MyFrame::OnClose(wxCloseEvent& event)
{
	delete m_controlPanel ;
	delete m_drawingPanel ;
	event.Skip() ;
}

//------------------------------------------------------------------------
void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox(wxT("How to .. \n\n- use 2 panels (one for controls, one for drawings)\n- manage basic events (so that controls impact drawings)\n\n... with wxWidgets (3.0.2)\n\nPascal Bertolino UGA - GIPSA-lab, Grenoble - France\npascal.bertolino@gipsa-lab.fr"),
                  wxT(APP_NAME), wxOK | wxICON_INFORMATION ) ;
}

//------------------------------------------------------------------------
void MyFrame::OnOpenFile(wxCommandEvent& WXUNUSED(event) )
{
	wxString filename = wxFileSelector(wxT("Select file"));
	if ( !filename.empty() )
		m_drawingPanel->OpenFile(filename) ;
}

//------------------------------------------------------------------------
void MyFrame::OnSaveFile(wxCommandEvent & WXUNUSED(event))
{
	wxString filename = wxSaveFileSelector(wxT("Save file as"), wxT("*.txt"), wxT("data"));
	if ( !filename.empty() )
		m_drawingPanel->SaveFile(filename) ;
}

//------------------------------------------------------------------------
void MyFrame::OnSize(wxSizeEvent &event)
// Called when you resize the frame
{
	int w, h ;
	GetSize(&w,&h) ;
	m_controlPanel->SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;
	m_drawingPanel->SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH,0), wxPoint(w, h))) ;
}
