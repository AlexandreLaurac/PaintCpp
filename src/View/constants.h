#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__


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
	ID_MOUSELEFTDOWN,
	ID_COLOURPICKER
} ;


#endif
