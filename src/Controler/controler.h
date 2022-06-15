#ifndef __CONTROLER_H__
#define __CONTROLER_H__


class MyFrame ;

class Controler
{
    private :
        int m_idForme ;
        MyFrame * m_appFrame ;
    public :
        Controler (MyFrame * frame) ;
        void SetIdForme (int idForme) ;
} ;


#endif
