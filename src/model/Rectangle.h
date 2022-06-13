#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <string>

#include "Forme.h"
#include "Point.h"

//-------------------------------------------
class Rectangle : public Forme
//-------------------------------------------
{
public:          
    Rectangle();                           
    Rectangle(int x, int y, int w, int h, const std::string label); // constructeur

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


private: 
    Point topLeftCorner;         
    int width;               
    int height;               

};

#endif // __RECTANGLE_H__
