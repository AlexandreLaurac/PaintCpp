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
    Rectangle(const int x, const int y, const int w, const int h, const std::string& label, const std::string& colorOutline, const std::string& colorFill); // constructeur avec couleurs perso
    Rectangle(const int x, const int y, const int w, const int h, const std::string& label); // constructeur avec couleurs par défauts
    Rectangle(const Rectangle& rectangle);

    Rectangle& operator=(const Rectangle& rectangleToCopy);

    virtual ~Rectangle(){};

    // Setters
    void setWidth(int w);
    void setHeight(int h);

    // Getters
    const Point& getCorner() const;    
    int getWidth() const;
    int getHeight() const;

    // Méthode additionnel
	void display() const;

	// Méthodes virtuelles
    virtual float surface() const override;
    virtual float perimeter() const override;
	virtual void move(int offsetX, int offsetY);
    virtual void draw(wxPaintDC& dc);
    virtual std::string toSVG();


private: 
    Point topLeftCorner;         
    int width;               
    int height;               

};

#endif
