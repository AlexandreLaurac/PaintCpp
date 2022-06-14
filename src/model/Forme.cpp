#include <iostream>
#include "Forme.h"

using namespace std;

Forme::Forme(){}

Forme::Forme(const string label) {
    this->label = label;
}

Forme::Forme(const Forme& forme) {
    this->label = forme.label;
}

// virtual
Forme::~Forme(){}

Forme& Forme::operator=(const Forme& forme) {
    // La Forme ne contient qu'un attribut, le label, on peut utiliser SetLabel
    setLabel(forme.label);

    return *(this);
}

void Forme::setLabel(const std::string label) {
	this->label = label;
}

std::string Forme::getLabel() const {
    return label;
}