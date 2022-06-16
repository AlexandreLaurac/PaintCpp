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
        int GetModeId () const ;
        int GetFormId () const ;
        int GetMouseId () const ;

        Couleur GetOutlineColor() const {return m_couleurCouranteOutline;};
        Couleur GetFillColor() const {return m_couleurCouranteFill;};
        void SetOutlineColor(int r, int g, int b, int a);
        void SetFillColor(int r, int g, int b, int a);
        
        void SetModeId (int modeId) ;
        void SetFormId (int formId) ;
        void SetMouseId (int mouseId) ;
        Dessin GetDessin () { return m_dessin ;} ;
        void FormCreation (int x, int y) ;
        void FormModification (int x, int y) ;
        void FormSelection (int x, int y) ;
} ;


#endif
