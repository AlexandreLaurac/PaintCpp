#include "constants.h"
#include "MyControlPanel.h"
#include "MyFrame.h"
#include "controler.h"


//------------------------------------------------------------------------
MyControlPanel::MyControlPanel(wxWindow *parent) : wxPanel(parent)
// In this constructor, create the controls and associate each of them (bind) a method
{
	int w, h, y ;
	GetParent()->GetSize(&w,&h) ;
	SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;
	SetBackgroundColour(*wxLIGHT_GREY) ;

	m_parentFrame = (MyFrame *) parent ;


	y = WIDGET_Y0;
	m_buttonRectangle = new wxButton(this, ID_BUTTON_RECT, wxT("Rectangle"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::onButtonRectangle, this, ID_BUTTON_RECT) ;

	y+= WIDGET_Y_STEP ;
	m_buttonOval = new wxButton(this, ID_BUTTON_OVAL, wxT("Ovale"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::onButtonOval, this, ID_BUTTON_OVAL) ;

	y+= WIDGET_Y_STEP ;
	m_buttonLine = new wxButton(this, ID_BUTTON_LINE, wxT("Ligne"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::onButtonLine, this, ID_BUTTON_LINE) ;

	y+= WIDGET_Y_STEP + 25;
	wxStaticText* labelColorPickerOutline = new wxStaticText(this, wxID_ANY, wxT("Bordure"), wxPoint(10, y)) ;
	y+= 20;
	m_colourPickerOutline = new wxColourPickerCtrl(this, ID_COLOURPICKER_OUTLINE, wxColour(0,0,0,255), wxPoint(10, y), wxSize(40,40), 0, wxDefaultValidator, wxT("Couleur des contours")) ;
	Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::onColorPickerOutline, this, ID_COLOURPICKER_OUTLINE) ;
 
	y+= WIDGET_Y_STEP;
	wxStaticText* labelColorPickerFill= new wxStaticText(this, wxID_ANY, wxT("Remplissage"), wxPoint(10, y)) ;
	y+= 20;
	m_colourPickerFill = new wxColourPickerCtrl(this, ID_COLOURPICKER_FILL, wxColour(0,0,0,255), wxPoint(10, y), wxSize(40,40), 0, wxDefaultValidator, wxT("Couleur de remplissage")) ;
	Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::onColorPickerFill, this, ID_COLOURPICKER_FILL) ;

	y+= WIDGET_Y_STEP + 50 ;
	m_buttonLine = new wxButton(this, ID_BUTTON_SELECT, wxT("Sélection"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::onButtonSelection, this, ID_BUTTON_SELECT) ;
}


//------------------------------------------------------------------------
void MyControlPanel::onButtonRectangle(wxCommandEvent &event)
{
	m_parentFrame->getControler()->setModeId(ID_MODE_FORM) ;
	m_parentFrame->getControler()->setFormId(ID_RECT) ;
}

//------------------------------------------------------------------------
void MyControlPanel::onButtonOval(wxCommandEvent &event)
{
	m_parentFrame->getControler()->setModeId(ID_MODE_FORM) ;
	m_parentFrame->getControler()->setFormId(ID_OVAL) ;
}

//------------------------------------------------------------------------
void MyControlPanel::onButtonLine(wxCommandEvent &event)
{
	m_parentFrame->getControler()->setModeId(ID_MODE_FORM) ;
	m_parentFrame->getControler()->setFormId(ID_LINE) ;
}

void MyControlPanel::onButtonSelection(wxCommandEvent &event)
{
	m_parentFrame->getControler()->setModeId(ID_MODE_SELECTION) ;
	m_parentFrame->getControler()->setFormId(ID_FORM_NONE) ;

}

void MyControlPanel::onColorPickerOutline(wxColourPickerEvent &event)
{
	wxColour color = event.GetColour();
	m_parentFrame->getControler()->setOutlineColor((int)color.Red(), (int)color.Green(), (int)color.Blue(), (int)color.Alpha());
}

void MyControlPanel::onColorPickerFill(wxColourPickerEvent &event)
{
	wxColour color = event.GetColour();
	m_parentFrame->getControler()->setFillColor((int)color.Red(), (int)color.Green(), (int)color.Blue(), (int)color.Alpha());
}