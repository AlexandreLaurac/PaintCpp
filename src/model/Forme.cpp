#include <iostream>
#include "Forme.h"

using namespace std;

Forme::Forme(){}

Forme::Forme(const string& label, const Couleur colorOutline, const Couleur colorFill){
    this->label = label;
    this->colorOutline = colorOutline;
    this->colorFill = colorFill;
}

Forme::Forme(const string& label) {
    this->label = label;
    colorOutline = Couleur(0,0,0,1);
    colorFill = Couleur(255,255,255,1);
}

Forme::Forme(const Forme& forme) {
    this->label = forme.label;
    this->colorOutline = forme.colorOutline;
    this->colorFill = forme.colorFill;
}

// virtual
Forme::~Forme(){}

Forme& Forme::operator=(const Forme& forme) {
    // La Forme ne contient qu'un attribut, le label, on peut utiliser SetLabel
    setLabel(forme.label);

    return *(this);
}

void Forme::setLabel(const string& label) {
	this->label = label;
}

string Forme::getLabel() const {
    return label;
}


void Forme::setColorOutline(const Couleur colorOutline) {
	this->colorOutline = colorOutline;
}
const Couleur Forme::getColorOutline() const {
    return colorOutline;
}

void Forme::setColorFill(const Couleur colorFill) {
	this->colorFill = colorFill;
}
const Couleur Forme::getColorFill() const {
    return colorFill;
}


double Forme::getDistancePoint(int x, int y) const
{
	return getCentre().distancePoint(x,y) ;
}