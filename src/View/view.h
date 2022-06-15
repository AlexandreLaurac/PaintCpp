#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <vector>


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
	ID_BUTTON2,    // Bouton rectangle du panneau de contrôle
	ID_BUTTON3,    // Bouton ovale du panneau de contrôle
	ID_RECT,
	ID_OVAL
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
		int GetSelectedForm() { return m_selectedForm ; } ;

	private :
		void OnButton (wxCommandEvent &event) ;
		void OnSlider (wxScrollEvent &event) ;
		void OnCheckBox (wxCommandEvent &event) ;
		void OnButtonRectangle (wxCommandEvent &event) ;
		void OnButtonOval (wxCommandEvent &event) ;
		MyFrame * m_parentFrame ;
		wxButton * m_button ;
		wxSlider * m_slider ;
		wxCheckBox * m_checkBox ;
		wxButton * m_buttonRectangle ;		
		wxButton * m_buttonOval ;
		int m_selectedForm ;
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
		wxRect GetOneRect () ;
		void SetOneRect (const wxRect & rectToCopy) ;

	private :
		void OnMouseMove (wxMouseEvent &event) ;
		void OnMouseLeftDown (wxMouseEvent &event) ;
		void OnMouseLeftUp (wxMouseEvent &event) ;
		void OnPaint(wxPaintEvent &event) ;
		MyFrame * m_parentFrame ;
		wxPoint m_mousePoint ;
		wxPoint m_onePoint ;
		wxRect m_oneRect ;
		std::vector <wxRect> m_Rect ;
		std::vector <int> m_Forme ;
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
        void RefreshDrawing(){m_drawingPanel->Refresh() ;} ;

    protected:
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnOpenFile(wxCommandEvent& WXUNUSED(event) ) ;
        void OnSaveFile(wxCommandEvent & WXUNUSED(event)) ;
        void OnClose(wxCloseEvent& event) ;
        void OnSize(wxSizeEvent &event) ;

        MyControlPanel * m_controlPanel; // the panel with controls
        MyDrawingPanel * m_drawingPanel; // the panel in which we draw
} ;
