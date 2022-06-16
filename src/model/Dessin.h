#ifndef __DESSIN_H__
#define __DESSIN_H__

#include <vector>

#include "Forme.h"

//-------------------------------------------
class Dessin
//-------------------------------------------
{

public:          
    Dessin(){ currentForm = nullptr ; };                           

    // Setters
    void addForme(Forme* formeToAdd);
    void deleteForme(Forme* formeToDelete);

    // Getters
    std::vector<Forme*> getList() const;

    // Setters
    void SetCurrentForm(Forme * form) ;

    // Additional methods
    void deleteList();
    void displayList() const;
    void drawAllFormes(wxPaintDC& dc) const;
    void saveSVG(const char* path); // Encode a vector<Forme*> to an SVG file
    std::vector<Forme*> openSVG(const char* path); // Decode an SVG file to a vector<Forme*> 


private: 
    std::vector<Forme*> listFormes;
    Forme * currentForm ;
};

#endif
