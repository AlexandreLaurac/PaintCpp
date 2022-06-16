#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include "Oval.h"


using namespace std;


Oval::Oval(const int x, const int y, const int w, const int h, const string& label, const Couleur colorOutline, const Couleur colorFill) : Forme(label, colorOutline, colorFill) {
	topLeftCorner.x = x;
	topLeftCorner.y = y;
	width = w;
	height = h;
}

Oval::Oval(const int x, const int y, const int w, const int h, const string& label) : Forme(label) {
	topLeftCorner.x = x;
	topLeftCorner.y = y;
	width = w;
	height = h;
}


Oval::Oval(const Oval& Oval) : Forme(Oval.label){
    topLeftCorner.x = Oval.getCornerTopLeft().x;
	topLeftCorner.y = Oval.getCornerTopLeft().y;

	pivotCorner.x = Oval.getPivotCorner().x;
	pivotCorner.y = Oval.getPivotCorner().y;

	width = Oval.getWidth();
	height = Oval.getHeight();
}



void Oval::setWidth(int w) {
    width = w;
}

void Oval::setHeight(int h) {
    height = h;
}

void Oval::setCornerTopLeft(const int x, const int y){
	topLeftCorner.x = x;
	topLeftCorner.y = y;
}
const Point& Oval::getCornerTopLeft() const {
    return topLeftCorner;
}

void Oval::setPivotCorner(const int x, const int y){
	pivotCorner.x = x;
	pivotCorner.y = y;
}
const Point& Oval::getPivotCorner() const {
    return pivotCorner;
}

int Oval::getWidth() const {
    return width;
}

int Oval::getHeight() const {
    return height;
}

void Oval::display() const {
	cout << label << " de coin ";
	topLeftCorner.display();
	cout << " de largeur=" << width << " et de hauteur=" << height;
	cout << " *** Outline : " << colorOutline.toString();
	cout << " & Fill : " << colorFill.toString();
}

// Méthodes virtuelles

void Oval::move(int offsetX, int offsetY) {
    topLeftCorner.move(offsetX, offsetY);
}

float Oval::surface() const {
    return (float)(M_PI * (width/2) * (height/2));
}

float Oval::perimeter() const {
    return (float)(M_PI * (3 * ( (width+height) / 2) - sqrt( (3 * (width/2) + height/2) * ((width/2)+3*(height/2))) ) ); // Formule de Ramanujan avaec précision de 0.01%
}


void Oval::draw(wxPaintDC& dc){
	dc.DrawEllipse(topLeftCorner.x, topLeftCorner.y, width,height) ;
}

string Oval::toSVG(){
	string cx = to_string(topLeftCorner.x + width/2);
	string cy = to_string(topLeftCorner.y + height/2);
	string rx = to_string(width/2);
	string ry = to_string(height/2);

	string outline = colorOutline.toString();
	string fill = colorFill.toString();

	return "<ellipse cx=\""+cx+"\" cy=\""+cy+"\" rx=\""+rx+"\" ry=\""+ry+"\" stroke=\""+outline+"\" fill=\""+fill+"\"/>";	
}


Point Oval::getCentre() const
{
	int x = (int) (getCornerTopLeft().x + getWidth()/2) ;
	int y = (int) (getCornerTopLeft().y + getHeight()/2) ;
	return Point(x,y) ;
}

bool Oval::Contains(int x, int y) const
{
	return ( (getCornerTopLeft().x <= x && x <= getCornerTopLeft().x+getWidth()) && (getCornerTopLeft().y <= y && y <= getCornerTopLeft().y+getHeight())) ;
}
