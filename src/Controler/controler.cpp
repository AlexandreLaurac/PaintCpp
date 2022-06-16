#include "controler.h"
#include "constants.h"
#include "MyFrame.h"
#include "MyControlPanel.h"


#include <cmath>

#include "Rectangle.h"
#include "Oval.h"
#include "Ligne.h"

using namespace std;

Controler::Controler(MyFrame * frame)
{
    m_modeId = ID_MODE_NONE ; // aucun mode de fonctionnement par défaut
    m_formId = ID_FORM_NONE ; // aucune forme sélectionnée par défaut
    m_appFrame = frame ;
    frame->SetControler (this) ;
}

int Controler::GetModeId () const
{
    return m_modeId ;
}

int Controler::GetFormId () const
{
    return m_formId ;
}

int Controler::GetMouseId () const
{
    return m_mouseId ;
}

void Controler::SetModeId(int modeId)
{
    m_modeId = modeId ;
}

void Controler::SetFormId(int formId)
{
    m_formId = formId ;
}


void Controler::SetMouseId(int mouseId)
{
    m_mouseId = mouseId ;
}


void Controler::FormCreation(int x, int y)
{
    switch (m_formId)
    {
        case ID_RECT :
        {
            Rectangle * rectangle = new Rectangle (x, y, 0, 0, "rectangle") ;
            m_dessin.addForme(rectangle) ;
            break ;
        }
        case ID_OVAL :
        {
            Oval * oval = new Oval (x, y, 0, 0, "oval") ;
            oval->setPivotCorner(x,y);
            m_dessin.addForme(oval) ;
            break ;
        }
        case ID_LINE :
        {
            Ligne * line = new Ligne (x, y, x, y, "ligne") ;
            m_dessin.addForme(line) ;
            break ;
        }
    }
}

void Controler::FormModification (int x, int y)
{
    switch (m_formId)
    {
        case ID_RECT :
            if (m_mouseId == ID_MOUSELEFTDOWN)
            {
                Rectangle * rectangle = (Rectangle *) m_dessin.getList().back() ;
                rectangle->setWidth(x-rectangle->getCorner().x) ;
                rectangle->setHeight(y-rectangle->getCorner().y) ;
            }
            break ;
        case ID_OVAL :
            if (m_mouseId == ID_MOUSELEFTDOWN)
            {
                Oval * oval = (Oval *) m_dessin.getList().back() ;

                // Conditions to move dynamically the topLeftCorner

                if ((x - oval->getPivotCorner().x) < 0 && (y - oval->getPivotCorner().y) > 0){

                    oval->setCornerTopLeft(oval->getPivotCorner().x - oval->getWidth(), oval->getPivotCorner().y);

                } else if ((x - oval->getPivotCorner().x) < 0 && (y - oval->getPivotCorner().y) < 0){

                    oval->setCornerTopLeft(oval->getPivotCorner().x - oval->getWidth(), oval->getPivotCorner().y - oval->getHeight());

                } else if ((x - oval->getPivotCorner().x) > 0 && (y - oval->getPivotCorner().y) < 0){

                    oval->setCornerTopLeft(oval->getPivotCorner().x, oval->getPivotCorner().y - oval->getHeight());

                }

                oval->setWidth(abs(x-oval->getPivotCorner().x)) ;
                oval->setHeight(abs(y-oval->getPivotCorner().y)) ;
            }
            break ;
        case ID_LINE :
            if (m_mouseId == ID_MOUSELEFTDOWN)
            {
                Ligne * line = (Ligne *) m_dessin.getList().back() ;
                line->setPointEnd(x,y) ;
            }
    }
}

void Controler::FormSelection (int x, int y)
{
    for (Forme * form : m_dessin.getList())
    {
        if (form->Contains(x,y))
        {
            m_dessin.SetCurrentForm(form) ;
            form->setColorOutline(Couleur(255,0,0,1)) ;
            return ;
        }
    }    
}