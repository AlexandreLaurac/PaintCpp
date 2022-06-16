#include <iostream>
#include <string>
#include "Couleur.h"

using namespace std;

Couleur::Couleur() {
	r = 0;
	g = 0;
	b = 0;
	a = 1;
}

Couleur::Couleur(const unsigned int& r, const unsigned int& g, const unsigned int& b, const unsigned int& a) {
	this -> r = r;
	this -> b = b;
	this -> g = g;
	this -> a = a;
}

Couleur::Couleur(const Couleur& toCopy){
	r = toCopy.r;
	g = toCopy.g;
	b = toCopy.b;
	a = toCopy.a;
}

Couleur& Couleur::operator=(const Couleur& couleur){
	r = couleur.r;
	g = couleur.g;
	b = couleur.b;
	a = couleur.a;
	
	return *(this);
}

bool Couleur::operator==(const Couleur& c) const{
	return ((r == c.r) && (g == c.g) && (b == c.b) && (a == c.a));
}


const array<unsigned int, 4> Couleur::toArray() const{
	array<unsigned int, 4> buffer = {r,g,b,a};
	return buffer;
}

const string Couleur::toString() const {
	string buffer = "rgba("+to_string(r)+","+to_string(g)+","+to_string(b)+","+to_string(a)+")";
	return buffer;
}


