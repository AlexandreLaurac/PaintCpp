#ifndef __COULEUR_H__
#define __COULEUR_H__

#include <array>

//-------------------------------------------
class Couleur
//-------------------------------------------
{
	
public :

	Couleur();
	Couleur(const unsigned int& r, const unsigned int& g, const unsigned int& b, const unsigned int& a);
	Couleur(const Couleur& toCopy);
	Couleur(std::string line); // Constructeur avec une chaine rgba(...)

	~Couleur(){}

	Couleur& operator=(const Couleur& couleur);
	bool operator==(const Couleur& c) const;


	// Getter
	const std::array<unsigned int, 4> toArray() const;
	const std::string toString() const;


	unsigned int r,g,b,a;
};

#endif