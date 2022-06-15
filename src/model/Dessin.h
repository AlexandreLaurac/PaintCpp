#ifndef __DESSIN_H__
#define __DESSIN_H__

#include <vector>

#include "Forme.h"

//-------------------------------------------
class Dessin
//-------------------------------------------
{

public:          
    Dessin(){};                           

    // Setters
    void addForme(Forme* formeToAdd);
    void deleteForme(Forme* formeToDelete);

    // Getters
    std::vector<Forme*> getList() const;

    // Additional methods
    void displayList() const;
    void saveSVG(std::string path); // Encode a vector<Forme> to an SVG file
    std::vector<Forme*> openSVG(std::string path); // Decode an SVG file to a vector<Forme> 


private: 
    std::vector<Forme*> listFormes;

};

#endif
