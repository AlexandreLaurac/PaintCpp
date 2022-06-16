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

	y = WIDGET_Y0 ;
	m_button = new wxButton(this, ID_BUTTON1, wxT("Click me"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButton, this, ID_BUTTON1) ;

	y+= WIDGET_Y_STEP ;
	wxStaticText* text1 = new wxStaticText(this, wxID_ANY, wxT("Radius"), wxPoint(10, y)) ;

	y+= 15 ;
	m_slider = new wxSlider(this, ID_SLIDER1, 10, 2, 100, wxPoint(10, y), wxSize(100,20), wxSL_LABELS) ;
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_SLIDER1) ;

	y+= WIDGET_Y_STEP ;
	m_checkBox = new wxCheckBox(this, ID_CHECKBOX1, "Show (x,y)", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ;

	y+= WIDGET_Y_STEP ;
	m_buttonRectangle = new wxButton(this, ID_BUTTON_RECT, wxT("Rectangle"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonRectangle, this, ID_BUTTON_RECT) ;

	y+= WIDGET_Y_STEP ;
	m_buttonOval = new wxButton(this, ID_BUTTON_OVAL, wxT("Ovale"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonOval, this, ID_BUTTON_OVAL) ;

	y+= WIDGET_Y_STEP ;
	m_buttonLine = new wxButton(this, ID_BUTTON_LINE, wxT("Ligne"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonLine, this, ID_BUTTON_LINE) ;

	y+= WIDGET_Y_STEP + 10 ;
	m_buttonLine = new wxButton(this, ID_BUTTON_SELECT, wxT("Sélection"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonSelection, this, ID_BUTTON_SELECT) ;


	y+= WIDGET_Y_STEP + 10 ;
	m_colourPickerOutline = new wxColourPickerCtrl(this, ID_COLOURPICKER_OUTLINE, wxColour(0,0,0,255), wxPoint(10, y), wxDefaultSize, 0, wxDefaultValidator, wxT("Couleur des contours")) ;
	Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::OnColorPickerOutline, this, ID_COLOURPICKER_OUTLINE) ;


	y+= WIDGET_Y_STEP + 10 ;
	m_colourPickerFill = new wxColourPickerCtrl(this, ID_COLOURPICKER_FILL, wxColour(0,0,0,255), wxPoint(10, y), wxDefaultSize, 0, wxDefaultValidator, wxT("Couleur de remplissage")) ;
	Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::OnColorPickerFill, this, ID_COLOURPICKER_FILL) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnButton(wxCommandEvent &event)
{
	wxMessageBox(wxT("You just pressed the button!")) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnSlider(wxScrollEvent &event)
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnCheckBox(wxCommandEvent &event)
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonRectangle(wxCommandEvent &event)
{
	m_parentFrame->GetControler()->SetModeId(ID_MODE_FORM) ;
	m_parentFrame->GetControler()->SetFormId(ID_RECT) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonOval(wxCommandEvent &event)
{
	m_parentFrame->GetControler()->SetModeId(ID_MODE_FORM) ;
	m_parentFrame->GetControler()->SetFormId(ID_OVAL) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonLine(wxCommandEvent &event)
{
	m_parentFrame->GetControler()->SetModeId(ID_MODE_FORM) ;
	m_parentFrame->GetControler()->SetFormId(ID_LINE) ;
}

void MyControlPanel::OnButtonSelection(wxCommandEvent &event)
{
	m_parentFrame->GetControler()->SetModeId(ID_MODE_SELECTION) ;
	m_parentFrame->GetControler()->SetFormId(ID_FORM_NONE) ;

}

void MyControlPanel::OnColorPickerOutline(wxColourPickerEvent &event)
{
	wxColour color = event.GetColour();
	m_parentFrame->GetControler()->SetOutlineColor((int)color.Red(), (int)color.Green(), (int)color.Blue(), (int)color.Alpha());
}

void MyControlPanel::OnColorPickerFill(wxColourPickerEvent &event)
{
	wxColour color = event.GetColour();
	m_parentFrame->GetControler()->SetFillColor((int)color.Red(), (int)color.Green(), (int)color.Blue(), (int)color.Alpha());
}