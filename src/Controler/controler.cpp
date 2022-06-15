#include "controler.h"
#include "view.h"

#include "Rectangle.h"
#include "Oval.h"

Controler::Controler(MyFrame * frame)
{
    m_formId = 0 ; // aucune forme sélectionnée par défaut
    m_appFrame = frame ;
    frame->SetControler (this) ;
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
    }
}

void Controler::FormModification (int xRightBottomCorner, int yRightBottomCorner)
{
    switch (m_formId)
    {
        case ID_RECT :
            if (m_mouseId == ID_MOUSELEFTDOWN)
            {
                Rectangle * rectangle = (Rectangle *) m_dessin.getList().back() ;
                rectangle->setWidth(xRightBottomCorner-rectangle->getCorner().x) ;
                rectangle->setHeight(yRightBottomCorner-rectangle->getCorner().y) ;
            }
            break ;
        case ID_OVAL :
            if (m_mouseId == ID_MOUSELEFTDOWN)
            {
                Oval * oval = (Oval *) m_dessin.getList().back() ;
                oval->setWidth(xRightBottomCorner-oval->getCorner().x) ;
                oval->setHeight(yRightBottomCorner-oval->getCorner().y) ;
            }

    }
}