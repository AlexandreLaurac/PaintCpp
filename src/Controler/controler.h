#ifndef __CONTROLER_H__
#define __CONTROLER_H__

#include "Dessin.h"

class MyFrame ;

class Controler
{
    private :
        int m_modeId ;
        int m_formId ;
        int m_mouseId ;
        Couleur m_couleurCouranteFill;
        Couleur m_couleurCouranteOutline;
        MyFrame * m_appFrame ;
        Dessin m_dessin ;

    public :
        Controler (MyFrame * frame) ;
        int getModeId () const ;
        int getFormId () const ;
        int getMouseId () const ;

        void setInformations(Forme* forme);

        Couleur getOutlineColor() const {return m_couleurCouranteOutline;};
        Couleur getFillColor() const {return m_couleurCouranteFill;};
        void setOutlineColor(int r, int g, int b, int a);
        void setFillColor(int r, int g, int b, int a);
        
        void setModeId (int modeId) ;
        void setFormId (int formId) ;
        void setMouseId (int mouseId) ;
        Dessin getDessin () { return m_dessin ;} ;
        void formCreation (int x, int y) ; 
        void formModification (int x, int y) ;
        void formSelection (int x, int y) ;
} ;


#endif
