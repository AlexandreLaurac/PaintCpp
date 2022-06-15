#include <iostream>
#include "Forme.h"

using namespace std;

Forme::Forme(){}

Forme::Forme(const string& label, const string& colorOutline, const string& colorFill) {
    this->label = label;
    this->colorOutline = colorOutline;
    this->colorFill = colorFill;
}

Forme::Forme(const string& label) {
    this->label = label;
    this->colorOutline = "BLACK";
    this->colorFill = "TransparentColour";
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

void Forme::setcolorOutline(const string& colorOutline) {
	this->colorOutline = colorOutline;
}

string Forme::getcolorOutline() const {
    return colorOutline;
}

void Forme::setcolorFill(const string& colorFill) {
	this->colorFill = colorFill;
}

string Forme::getcolorFill() const {
    return colorFill;
}
