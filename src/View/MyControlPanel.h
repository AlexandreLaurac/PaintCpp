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

		void OnColorPickerOutline (wxColourPickerEvent &event) ;
		void OnColorPickerFill (wxColourPickerEvent &event) ;

		MyFrame * m_parentFrame ;
		wxButton * m_button ;
		wxSlider * m_slider ;
		wxCheckBox * m_checkBox ;
		wxButton * m_buttonRectangle ;		
		wxButton * m_buttonOval ;
		wxButton * m_buttonLine ;
		wxButton * m_buttonSelection ;

		wxColourPickerCtrl * m_colourPickerOutline;
		wxColourPickerCtrl * m_colourPickerFill;
} ;


#endif
