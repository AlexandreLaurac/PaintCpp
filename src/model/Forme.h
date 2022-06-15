#ifndef __FORME_H__
#define __FORME_H__

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class Forme {
public:
    Forme();
    Forme(const std::string& label);    // Avec une string
    Forme(const Forme& forme);          // Construction par recopie
    virtual ~Forme();

    // Operator d'affectation
    Forme& operator=(const Forme& forme);

    // Accesseur
    void setLabel(const std::string& str);
    std::string getLabel() const;

    virtual float surface() const { return 0.0f; }
    virtual float perimeter() const { return 0.0f; }

	// Fonctions utilitaires
	virtual void move(int , int) = 0;
    virtual void draw(wxPaintDC& dc) = 0;
    virtual std::string toSVG() = 0;

/*
	virtual void zoom(int ) {};
	virtual void rotation(int ) {};
*/


protected: 
    std::string label;
};

#endif // __FORME_H__
