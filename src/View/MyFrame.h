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
        MyControlPanel* getControlPanel() {return m_controlPanel ;} ;
        MyDrawingPanel* getDrawingPanel() {return m_drawingPanel ;} ;
		Controler * getControler() {return m_controler ;} ;
        void refreshDrawing() ;

        // Setter
		void setControler(Controler * controler) ;


    protected:
        void onQuit(wxCommandEvent& event);
        void onAbout(wxCommandEvent& event);
        void onOpenFile(wxCommandEvent& WXUNUSED(event) ) ;
        void onSaveFile(wxCommandEvent & WXUNUSED(event)) ;
        void onClose(wxCloseEvent& event) ;
        void onSize(wxSizeEvent &event) ;
        MyControlPanel * m_controlPanel; // the panel with controls
        MyDrawingPanel * m_drawingPanel; // the panel in which we draw
		Controler * m_controler ;

        // wxString * m_statut;
        std::string m_statut;
} ;


#endif
