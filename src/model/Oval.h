#ifndef __OVAL_H__
#define __OVAL_H__

#include "Forme.h"
#include "Point.h"

#include <cmath>

//-------------------------------------------
class Oval : public Forme
//-------------------------------------------
{
    
public:          
    Oval(){};                           
    Oval(const int x, const int y, const int w, const int h, const std::string& label, const std::string& colorOutline, const std::string& colorFill); // constructeur avec couleurs perso
    Oval(const int x, const int y, const int w, const int h, const std::string& label); // constructeur avec couleurs par défauts
    Oval(const Oval& oval);

    Oval& operator=(const Oval& ovalToCopy);

    virtual ~Oval(){};

    // Setters
    void setWidth(int w);
    void setHeight(int h);

    // Getters
    const Point& getCorner() const;    
    int getWidth() const;
    int getHeight() const;

	// Méthodes virtuelles
	virtual void display() const;
    virtual float surface() const override;
    virtual float perimeter() const override;
	virtual void move(int offsetX, int offsetY);
    virtual void draw(wxPaintDC& dc);
    virtual std::string toSVG();

    virtual Point getCentre() const ;
    //virtual double getDistancePoint(const Point & point) const ;

private: 
    Point topLeftCorner;         
    int width;               
    int height;               

};

#endif
