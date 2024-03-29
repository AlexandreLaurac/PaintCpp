#include <cmath>
#include <vector>
#include <algorithm>

#include "controler.h"
#include "constants.h"
#include "MyFrame.h"
#include "MyControlPanel.h"

#include "Rectangle.h"
#include "Oval.h"
#include "Ligne.h"


using namespace std;


Controler::Controler(MyFrame * frame)
{
    m_modeId = ID_MODE_NONE ; // aucun mode de fonctionnement par défaut
    m_formId = ID_FORM_NONE ; // aucune forme sélectionnée par défaut
    m_appFrame = frame ;
    frame->setControler (this) ;
}

void Controler::setInformations(Forme* forme) {
    string buffer = forme->toString();
    m_appFrame->SetStatusText(buffer);
}

int Controler::getModeId () const
{
    return m_modeId ;
}

int Controler::getFormId () const
{
    return m_formId ;
}

int Controler::getMouseId () const
{
    return m_mouseId ;
}

void Controler::setModeId(int modeId)
{
    m_modeId = modeId ;
}

void Controler::setFormId(int formId)
{
    m_formId = formId ;
}


void Controler::setMouseId(int mouseId)
{
    m_mouseId = mouseId ;
}

void Controler::setOutlineColor(int r, int g, int b, int a){
    m_couleurCouranteOutline.r = r;
    m_couleurCouranteOutline.g = g;
    m_couleurCouranteOutline.b = b;
    m_couleurCouranteOutline.a = a/(255); // Pour être cohérent avec le modele
}

void Controler::setFillColor(int r, int g, int b, int a){
    m_couleurCouranteFill.r = r;
    m_couleurCouranteFill.g = g;
    m_couleurCouranteFill.b = b;
    m_couleurCouranteFill.a = a/(255); // Pour être cohérent avec le modele
}



void Controler::formCreation(int x, int y)
{
    switch (m_formId)
    {
        case ID_RECT :
        {
            Rectangle * rectangle = new Rectangle (x, y, 0, 0, "rectangle", m_couleurCouranteOutline, m_couleurCouranteFill) ;
            rectangle->setPivotCorner(x,y);
            setInformations(rectangle);
            m_dessin.addForme(rectangle) ;
            break ;
        }
        case ID_OVAL :
        {
            Oval * oval = new Oval (x, y, 0, 0, "oval", m_couleurCouranteOutline, m_couleurCouranteFill) ;
            oval->setPivotCorner(x,y);
            setInformations(oval);
            m_dessin.addForme(oval) ;
            break ;
        }
        case ID_LINE :
        {
            Ligne * line = new Ligne (x, y, x, y, "ligne",  m_couleurCouranteOutline, m_couleurCouranteFill) ;
            setInformations(line);
            m_dessin.addForme(line) ;
            break ;
        }
    }
}

void Controler::formModification (int x, int y)
{
    switch (m_formId)
    {
        case ID_RECT :
            if (m_mouseId == ID_MOUSELEFTDOWN)
            {
                Rectangle * rectangle = (Rectangle *) m_dessin.getList().back() ;

                // Conditions to move dynamically the topLeftCorner

                if ((x - rectangle->getPivotCorner().x) < 0 && (y - rectangle->getPivotCorner().y) > 0){

                    rectangle->setTopLeftCorner(rectangle->getPivotCorner().x - rectangle->getWidth(), rectangle->getPivotCorner().y);

                } else if ((x - rectangle->getPivotCorner().x) < 0 && (y - rectangle->getPivotCorner().y) < 0){

                    rectangle->setTopLeftCorner(rectangle->getPivotCorner().x - rectangle->getWidth(), rectangle->getPivotCorner().y - rectangle->getHeight());

                } else if ((x - rectangle->getPivotCorner().x) > 0 && (y - rectangle->getPivotCorner().y) < 0){

                    rectangle->setTopLeftCorner(rectangle->getPivotCorner().x, rectangle->getPivotCorner().y - rectangle->getHeight());

                }

                rectangle->setWidth(abs(x-rectangle->getPivotCorner().x)) ;
                rectangle->setHeight(abs(y-rectangle->getPivotCorner().y)) ;

                setInformations(rectangle);
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
                setInformations(oval);
            }
            break ;
        case ID_LINE :
            if (m_mouseId == ID_MOUSELEFTDOWN)
            {
                Ligne * line = (Ligne *) m_dessin.getList().back() ;
                line->setPointEnd(x,y) ;
                setInformations(line);
            }
    }
}

void Controler::formSelection (int x, int y)
{
    Forme * form ;
    Forme * currentForm = m_dessin.getCurrentForm() ;

    auto listeTemp = m_dessin.getList() ;
    reverse(listeTemp.begin(), listeTemp.end());

    for (Forme * form : listeTemp)
    //for (auto it = m_dessin.getList().rbegin() ; it != m_dessin.getList().rend() ; ++it, i++)
    {
        //form = (*it) ;
        if (form->Contains(x,y))
        {
            if (currentForm != nullptr)
            {
                currentForm->setColorOutline(m_dessin.getSavedColor()) ;
            }
            m_dessin.setCurrentForm(form) ;
            m_dessin.setSavedColor(form->getColorOutline()) ;
            form->setColorOutline(Couleur(255,0,0,1)) ;
            return ;
        }
    }
    if (currentForm != nullptr)
    {
        currentForm->setColorOutline(m_dessin.getSavedColor()) ;

    }
}
