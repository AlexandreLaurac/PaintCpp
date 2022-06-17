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
	Bind(wxEVT_MOTION, &MyDrawingPanel::OnMouseMove, this);
	Bind(wxEVT_LEFT_DOWN, &MyDrawingPanel::OnMouseLeftDown, this);
	Bind(wxEVT_PAINT, &MyDrawingPanel::OnPaint, this) ;
	Bind(wxEVT_LEFT_UP, &MyDrawingPanel::OnMouseLeftUp, this);
	Bind(wxEVT_LEFT_DCLICK, &MyDrawingPanel::OnLeftDoubleClick, this) ;
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
			m_parentFrame->GetControler()->FormSelection(event.m_x, event.m_y) ;
			Refresh() ;
			break ;
		}
		case ID_MODE_FORM :
		{
			m_parentFrame->GetControler()->FormCreation(event.m_x, event.m_y) ;
			//string test = m_parentFrame->GetControler()->GetInformations();
			break ;
		}
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent &event) // called when the mouse is moved
{
	int mode = m_parentFrame->GetControler()->GetModeId() ;
	int souris = m_parentFrame->GetControler()->GetMouseId() ;
	switch (mode)
	{
		case ID_MODE_SELECTION :
		{
			Forme * currentForm = m_parentFrame->GetControler()->GetDessin().getCurrentForm() ;
			if (currentForm != nullptr && souris == ID_MOUSELEFTDOWN) // && currentForm->Contains(event.m_x, event.m_y))
			{
				currentForm->move(event.m_x, event.m_y) ;
				Refresh() ;
			}
			break ;
		}
		case ID_MODE_FORM :
		{
			m_parentFrame->GetControler()->FormModification(event.m_x, event.m_y) ;
			Refresh() ;
		}
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftUp(wxMouseEvent &event)
{
	m_parentFrame->GetControler()->SetMouseId(ID_MOUSELEFTUP) ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnLeftDoubleClick (wxMouseEvent & event)
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
void MyDrawingPanel::OnPaint(wxPaintEvent &event)
{
	wxPaintDC dc(this);
	m_parentFrame->GetControler()->GetDessin().drawAllFormes(dc) ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::OpenFile(wxString fileName)
{
	// just to open (and close) any file
	m_parentFrame->GetControler()->GetDessin().openSVG(fileName);
	Refresh();
}

//------------------------------------------------------------------------
void MyDrawingPanel::SaveFile(wxString fileName)
{
	m_parentFrame->GetControler()->GetDessin().saveSVG(fileName.mb_str());
	wxMessageBox(wxT("The file was saved")) ;
}
