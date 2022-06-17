#include "constants.h"
#include "MyDrawingPanel.h"
#include "MyFrame.h"
#include "controler.h"

#include "Forme.h"
#include "Dessin.h"

#include <vector>
#include <algorithm>

using namespace std ;

//------------------------------------------------------------------------
MyDrawingPanel::MyDrawingPanel(wxWindow *parent) : wxPanel(parent)
// In this constructor, bind some mouse events and the paint event with the appropriate methods
{
	int w, h ;
	GetParent()->GetClientSize(&w,&h) ;
	SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH,0), wxPoint(w, h))) ;
	SetBackgroundColour(wxColour(0xFF,0xFF,0xFF)) ;
	Bind(wxEVT_MOTION, &MyDrawingPanel::onMouseMove, this);
	Bind(wxEVT_LEFT_DOWN, &MyDrawingPanel::onMouseLeftDown, this);
	Bind(wxEVT_PAINT, &MyDrawingPanel::onPaint, this) ;
	Bind(wxEVT_LEFT_UP, &MyDrawingPanel::onMouseLeftUp, this);
	Bind(wxEVT_LEFT_DCLICK, &MyDrawingPanel::onLeftDoubleClick, this) ;
	m_parentFrame = (MyFrame *) parent ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::onMouseLeftDown(wxMouseEvent &event)
{
	// Récupération de l'état de l'interface
	m_parentFrame->getControler()->setMouseId(ID_MOUSELEFTDOWN) ;
	int mode = m_parentFrame->getControler()->getModeId() ;

	// Actions en fonction de cet état
	switch (mode)
	{
		case ID_MODE_SELECTION : // le bouton "Sélection" a été préalablement cliqué
		{
			m_parentFrame->getControler()->formSelection(event.m_x, event.m_y) ;  // la méthode onMouseLeftDown consiste alors à sélectionner une forme
			Refresh() ;
			break ;
		}
		case ID_MODE_FORM :      // un bouton de forme géométrique ("Rectangle", etc.) a été préalablement cliqué
		{
			m_parentFrame->getControler()->formCreation(event.m_x, event.m_y) ; // la méthode onMouseLeftDown consiste alors à créer une forme
			break ;
		}
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::onMouseMove(wxMouseEvent &event)
{
	// Récupération de l'état de l'interface
	int mode = m_parentFrame->getControler()->getModeId() ;
	int souris = m_parentFrame->getControler()->getMouseId() ;

	// Actions en fonction de cet état
	switch (mode)
	{
		case ID_MODE_SELECTION : // le bouton "Sélection" a été préalablement cliqué
		{ // la méthode onMouseMove consiste alors à déplacer une forme
			Forme * currentForm = m_parentFrame->getControler()->getDessin().getCurrentForm() ;
			if (currentForm != nullptr && souris == ID_MOUSELEFTDOWN) 
			{
				currentForm->move(event.m_x, event.m_y) ;
				Refresh() ;
			}
			break ;
		}
		case ID_MODE_FORM :      // un bouton de forme géométrique ("Rectangle", etc.) a été préalablement cliqué
		{ // la méthode onMouseMove consiste alors à modifier une forme
			m_parentFrame->getControler()->formModification(event.m_x, event.m_y) ;
			Refresh() ;
		}
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::onMouseLeftUp(wxMouseEvent &event)
{
	m_parentFrame->getControler()->setMouseId(ID_MOUSELEFTUP) ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::onLeftDoubleClick (wxMouseEvent & event)
{
	// if (m_parentFrame->GetControler()->GetModeId() == ID_MODE_SELECTION)
	// {
	// 	Forme * currentForm = m_parentFrame->GetControler()->GetDessin().getCurrentForm() ;
	// 	if (currentForm != nullptr && currentForm->Contains(event.m_x, event.m_y))
	// 	{
	// 		m_parentFrame->GetControler()->GetDessin().deleteForme(currentForm) ;
	// 		m_parentFrame->GetControler()->GetDessin().SetCurrentForm(nullptr) ;
	// 		Refresh() ;
	// 	}
	// }
	cout << "Suppression pas encore fonctionnelle" << endl ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::onPaint(wxPaintEvent &event)
{
	// La méthode consiste à redessiner toutes les formes
	wxPaintDC dc(this);
	m_parentFrame->getControler()->getDessin().drawAllFormes(dc) ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::openFile(wxString fileName)
{
	// just to open (and close) any file
	m_parentFrame->getControler()->getDessin().openSVG(fileName);
	Refresh();
}

//------------------------------------------------------------------------
void MyDrawingPanel::saveFile(wxString fileName)
{
	m_parentFrame->getControler()->getDessin().saveSVG(fileName.mb_str());
	wxMessageBox(wxT("The file was saved")) ;
}
