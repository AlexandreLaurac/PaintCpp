#ifndef __MYCONTROLPANEL_H__
#define __MYCONTROLPANEL_H__

#include <wx/clrpicker.h>
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

class MyFrame ;

class MyControlPanel : public wxPanel
{
	public :
		MyControlPanel (wxWindow * parent) ;

	private :

		void onButtonRectangle (wxCommandEvent &event) ;
		void onButtonOval (wxCommandEvent &event) ;
		void onButtonLine (wxCommandEvent &event) ;

		void onButtonSelection (wxCommandEvent &event) ;

		void onColorPickerOutline (wxColourPickerEvent &event) ;
		void onColorPickerFill (wxColourPickerEvent &event) ;

		MyFrame * m_parentFrame ;


		wxButton * m_buttonRectangle ;		
		wxButton * m_buttonOval ;
		wxButton * m_buttonLine ;
		wxButton * m_buttonSelection ;

		wxColourPickerCtrl * m_colourPickerOutline;
		wxColourPickerCtrl * m_colourPickerFill;
} ;


#endif
