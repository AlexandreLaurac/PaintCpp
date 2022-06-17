#include "constants.h"
#include "MyControlPanel.h"
#include "MyDrawingPanel.h"
#include "MyFrame.h"
#include "controler.h"

using namespace std;

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

	Bind(wxEVT_MENU, &MyFrame::onOpenFile, this, ID_LOAD);
	Bind(wxEVT_MENU, &MyFrame::onSaveFile, this, ID_SAVE);
	Bind(wxEVT_MENU, &MyFrame::onQuit, this, ID_QUIT);
	Bind(wxEVT_MENU, &MyFrame::onAbout, this, ID_ABOUT);
	Bind(wxEVT_CLOSE_WINDOW, &MyFrame::onClose, this);
	Bind(wxEVT_SIZE, &MyFrame::onSize, this);

	SetMenuBar( menuBar );

// create the panel that will contain the controls
	m_controlPanel = new MyControlPanel(this);
// create the panel that will display the graphics
	m_drawingPanel = new MyDrawingPanel(this);

	CreateStatusBar() ;
	SetStatusText(wxT("Appuyer sur une des boutons de l'interface à droite pour commencer à utiliser l'application")) ;
	Centre() ; // Guess what it does ;-)
}

void MyFrame::setControler (Controler * controler)
{
	m_controler = controler ;
}

//------------------------------------------------------------------------
void MyFrame::onQuit(wxCommandEvent& WXUNUSED(event))
{
	getControler()->getDessin().saveSVG("fichier.svg") ;
	Close(true) ;
}

//------------------------------------------------------------------------
void MyFrame::onClose(wxCloseEvent& event)
{
	delete m_controlPanel ;
	delete m_drawingPanel ;
	event.Skip() ;
}

//------------------------------------------------------------------------
void MyFrame::onAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox(wxT("How to .. \n\n- use 2 panels (one for controls, one for drawings)\n- manage basic events (so that controls impact drawings)\n\n... with wxWidgets (3.0.2)\n\nPascal Bertolino UGA - GIPSA-lab, Grenoble - France\npascal.bertolino@gipsa-lab.fr"),
                  wxT(APP_NAME), wxOK | wxICON_INFORMATION ) ;

}

//------------------------------------------------------------------------
void MyFrame::onOpenFile(wxCommandEvent& WXUNUSED(event) )
{
	wxString filename = wxFileSelector(wxT("Select file"));
	if ( !filename.empty() )
		m_drawingPanel->openFile(filename) ;
}

//------------------------------------------------------------------------
void MyFrame::onSaveFile(wxCommandEvent & WXUNUSED(event))
{
	wxString filename = wxSaveFileSelector(wxT("Save file as"), wxT("*.svg"), wxT("data"));
	if ( !filename.empty() )
		m_drawingPanel->saveFile(filename) ;
}

//------------------------------------------------------------------------
void MyFrame::onSize(wxSizeEvent &event)
// Called when you resize the frame
{
	int w, h ;
	GetSize(&w,&h) ;
	m_controlPanel->SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;
	m_drawingPanel->SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH,0), wxPoint(w, h))) ;
}

void MyFrame::refreshDrawing()
{
    m_drawingPanel->Refresh() ;
}