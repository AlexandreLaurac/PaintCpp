#ifndef __VIEW_H__
#define __VIEW_H__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <vector>


class Controler ;

//------------------------------------------------------------------------
// Some constants
#define APPLICATION_WIDTH	1000
#define APPLICATION_HEIGHT	800
#define WIDGET_PANEL_WIDTH	150
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50
#define APP_NAME "M1102 Skeleton 1.0"


//------------------------------------------------------------------------
// Some enums for widgets
enum
{
	ID_QUIT = 1,
	ID_ABOUT,
	ID_LOAD,
	ID_SAVE,
	ID_BUTTON1,
	ID_SLIDER1,
	ID_CHECKBOX1,
	ID_BUTTON_RECT,    // Bouton rectangle du panneau de contrôle
	ID_BUTTON_OVAL,    // Bouton ovale du panneau de contrôle
	ID_BUTTON_LINE,    // Bouton ligne du panneau de contrôle
	ID_BUTTON_SELECT,  // Bouton pour la sélection d'une forme
	// ID de mode
	ID_MODE_NONE,
	ID_MODE_FORM,
	ID_MODE_SELECTION,
	// ID de Formes
	ID_FORM_NONE,
	ID_RECT,
	ID_OVAL,
	ID_LINE,
	// ID de souris
	ID_MOUSELEFTUP,
	ID_MOUSELEFTDOWN
} ;


class MyFrame ;

//************************************************************************
//************************* class MyControlPanel *************************
//************************************************************************

class MyControlPanel : public wxPanel
{
	public :
		MyControlPanel (wxWindow * parent) ;
		int GetSliderValue() { return m_slider->GetValue() ; } ;
		bool GetCheckBoxValue() { return m_checkBox->GetValue() ; } ;

	private :
		void OnButton (wxCommandEvent &event) ;
		void OnSlider (wxScrollEvent &event) ;
		void OnCheckBox (wxCommandEvent &event) ;
		void OnButtonRectangle (wxCommandEvent &event) ;
		void OnButtonOval (wxCommandEvent &event) ;
		void OnButtonLine (wxCommandEvent &event) ;
		void OnButtonSelection (wxCommandEvent &event) ;

		MyFrame * m_parentFrame ;
		wxButton * m_button ;
		wxSlider * m_slider ;
		wxCheckBox * m_checkBox ;
		wxButton * m_buttonRectangle ;		
		wxButton * m_buttonOval ;
		wxButton * m_buttonLine ;
		wxButton * m_buttonSelection ;
} ;



//************************************************************************
//************************* class MyDrawingPanel *************************
//************************************************************************

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
		void OnPaint(wxPaintEvent &event) ;
		MyFrame * m_parentFrame ;
} ;


//************************************************************************
//**************************** class MyFrame *****************************
//************************************************************************

class MyFrame : public wxFrame
{
    public :
        MyFrame (const wxString& title, const wxPoint& pos, const wxSize& size) ;
        MyControlPanel* GetControlPanel() {return m_controlPanel ;} ;
        MyDrawingPanel* GetDrawingPanel() {return m_drawingPanel ;} ;
		Controler * GetControler() {return m_controler ;} ;
        void RefreshDrawing(){m_drawingPanel->Refresh() ;} ;
		void SetControler(Controler * controler) ;

    protected :
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