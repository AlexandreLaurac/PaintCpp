#ifndef __MYDRAWINGPANEL_H__
#define __MYDRAWINGPANEL_H__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

class MyFrame ;

class MyDrawingPanel : public wxPanel
{
	public :
		MyDrawingPanel (wxWindow * parent) ;
		void OpenFile (wxString fileName) ;
		void SaveFile (wxString fileName) ;

	private :
		void OnMouseMove (wxMouseEvent &event) ;
		void OnMouseLeftDown (wxMouseEvent &event) ;
		void OnMouseLeftUp (wxMouseEvent &event) ;
		void OnPaint (wxPaintEvent &event) ;
    	void OnLeftDoubleClick (wxMouseEvent & event) ;
		MyFrame * m_parentFrame ;
} ;


#endif
