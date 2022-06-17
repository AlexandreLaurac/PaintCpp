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
		void openFile (wxString fileName) ;
		void saveFile (wxString fileName) ;

	private :
		void onMouseMove (wxMouseEvent &event) ;
		void onMouseLeftDown (wxMouseEvent &event) ;
		void onMouseLeftUp (wxMouseEvent &event) ;
		void onPaint (wxPaintEvent &event) ;
    	void onLeftDoubleClick (wxMouseEvent & event) ;
		MyFrame * m_parentFrame ;
} ;


#endif
