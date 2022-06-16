#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Forme.h"
#include "Point.h"

//-------------------------------------------
class Rectangle : public Forme
//-------------------------------------------
{
    
public:          
    Rectangle(){};                           
    Rectangle(const int x, const int y, const int w, const int h, const std::string& label, Couleur colorOutline, Couleur colorFill); // constructeur avec couleurs perso
    Rectangle(const int x, const int y, const int w, const int h, const std::string& label); // constructeur avec couleurs par défauts
    Rectangle(const Rectangle& rectangle);

    Rectangle& operator=(const Rectangle& rectangleToCopy);

    virtual ~Rectangle(){};

    // Setters
    void setTopLeftCorner(const int x, const int y);
    void setPivotCorner(const int x, const int y);
    void setWidth(int w);
    void setHeight(int h);

    // Getters
    const Point& getTopLeftCorner() const;
    const Point& getPivotCorner() const;
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
    //virtual double getDistancePoint(int x, int y) const ;
    virtual bool Contains (int x, int y) const ;

private: 
    Point topLeftCorner;
    Point pivotCorner;         
    int width;               
    int height;               

};

#endif
