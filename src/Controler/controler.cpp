#include "controler.h"
#include "view.h"

#include "Rectangle.h"
#include "Oval.h"
#include "Ligne.h"

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
                oval->setWidth(x-oval->getCorner().x) ;
                oval->setHeight(y-oval->getCorner().y) ;
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