#ifndef __FORME_H__
#define __FORME_H__

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <array>
#include <Couleur.h>

#include "Point.h"

class Forme {
public:
    Forme();
    Forme(const std::string& label); // Avec un label
    Forme(const std::string& label, const Couleur colorOutline, const Couleur colorFill); // Avec un label et des couleurs
    Forme(const Forme& forme); // Construction par recopie
    virtual ~Forme();

    // Operator d'affectation
    Forme& operator=(const Forme& forme);

    // Setter
    void setLabel(const std::string& str);
    void setColorOutline(const Couleur colorOutline);
    void setColorFill(const Couleur colorFill);

    // Getter
    std::string getLabel() const;
    const Couleur getColorOutline() const;
    const Couleur getColorFill() const;

    virtual float surface() const { return 0.0f; }
    virtual float perimeter() const { return 0.0f; }

    virtual Point getCentre() const = 0 ;
    double getDistancePoint(int x, int y) const ;
    virtual bool Contains(int x, int y) const = 0 ;


	// Fonctions utilitaires
    virtual void display() const = 0;
	virtual void move(int , int) = 0;
    virtual void draw(wxPaintDC& dc) = 0;
    virtual std::string toSVG() = 0;

/*
	virtual void zoom(int ) {};
	virtual void rotation(int ) {};
*/


protected: 
    std::string label;

    Couleur colorOutline; // [R,G,B,Alpha]
    Couleur colorFill; // [R,G,B,Alpha]

private:

};

#endif // __FORME_H__
