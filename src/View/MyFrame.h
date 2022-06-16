#ifndef __MYFRAME_H__
#define __MYFRAME_H__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

class MyControlPanel ;
class MyDrawingPanel ;
class Controler ;

class MyFrame : public wxFrame
{
    public :
        MyFrame (const wxString& title, const wxPoint& pos, const wxSize& size) ;
        MyControlPanel* GetControlPanel() {return m_controlPanel ;} ;
        MyDrawingPanel* GetDrawingPanel() {return m_drawingPanel ;} ;
		Controler * GetControler() {return m_controler ;} ;
        void RefreshDrawing() ;
		void SetControler(Controler * controler) ;

    protected:
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnOpenFile(wxCommandEvent& WXUNUSED(event) ) ;
        void OnSaveFile(wxCommandEvent & WXUNUSED(event)) ;
        void OnClose(wxCloseEvent& event) ;
        void OnSize(wxSizeEvent &event) ;
        MyControlPanel * m_controlPanel; // the panel with controls
        MyDrawingPanel * m_drawingPanel; // the panel in which we draw
		Controler * m_controler ;
} ;


#endif
