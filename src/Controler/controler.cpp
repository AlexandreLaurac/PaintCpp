#include "controler.h"
#include "view.h"

#include "Rectangle.h"


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
    switch (m_formId) {
        case ID_RECT :
            Rectangle * rectangle = new Rectangle (x, y, 0, 0, "rectangle") ;
            m_dessin.addForme(rectangle) ;
            break ;
    }
}

void Controler::FormModification (int xRightBottomCorner, int yRightBottomCorner)
{
    switch (m_formId) {
        case ID_RECT :
            Rectangle * rectangle = m_dessin.getList().back() ;
            rectangle->setWidth(xRightBottomCorner-rectangle->getCorner().x, yRightBottomCorner-rectangle->getCorner().y)
            break ;
    }
}