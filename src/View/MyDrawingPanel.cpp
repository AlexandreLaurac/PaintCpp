#include "constants.h"
#include "MyDrawingPanel.h"
#include "MyFrame.h"
#include "controler.h"


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
//			m_parentFrame->GetControler()->SelectionForm(event.m_x, event.m_y) ;
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