#include "controler.h"
#include "view.h"

Controler::Controler(MyFrame * frame)
{
    m_idForme = 0 ; // aucune forme sélectionnée par défaut
    m_appFrame = frame ;
    frame->SetControler (this) ;
}


void Controler::SetIdForme(int idForme)
{
    m_idForme = idForme ;
}