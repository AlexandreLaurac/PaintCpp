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
        MyFrame * m_appFrame ;
        Dessin m_dessin ;
    public :
        Controler (MyFrame * frame) ;
        int GetModeId () const ;
        int GetFormId () const ;
        int GetMouseId () const ;
        void SetModeId (int modeId) ;
        void SetFormId (int formId) ;
        void SetMouseId (int mouseId) ;
        Dessin GetDessin () { return m_dessin ;} ;
        void FormCreation (int x, int y) ;
        void FormModification (int x, int y) ;
} ;


#endif
