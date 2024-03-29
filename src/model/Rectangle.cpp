#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include "Rectangle.h"

using namespace std;


Rectangle::Rectangle(const int x, const int y, const int w, const int h, const string& label, Couleur colorOutline, Couleur colorFill) : Forme(label, colorOutline, colorFill) {
	topLeftCorner.x = x;
	topLeftCorner.y = y;
	width = w;
	height = h;
}


Rectangle::Rectangle(const int x, const int y, const int w, const int h, const string& label) : Forme(label) {
	topLeftCorner.x = x;
	topLeftCorner.y = y;
	width = w;
	height = h;
}


Rectangle::Rectangle(const Rectangle& rectangle) : Forme(rectangle.label){
    topLeftCorner.x = rectangle.getTopLeftCorner().x;
	topLeftCorner.y = rectangle.getTopLeftCorner().y;

	pivotCorner.x = rectangle.getPivotCorner().x;
	pivotCorner.y = rectangle.getPivotCorner().y;

	width = rectangle.getWidth();
	height = rectangle.getHeight();
}

Rectangle::Rectangle(string line) : Forme("rectangle"){
	line.erase(0, line.find("=\"") + 2);
	string x = line.substr(0, line.find("\""));
	topLeftCorner.x = stoi(x);

	line.erase(0, line.find("=\"") + 2);
	string y = line.substr(0, line.find("\""));
	topLeftCorner.y = stoi(y);

	line.erase(0, line.find("=\"") + 2);
	string w = line.substr(0, line.find("\""));
	width = stoi(w);

	line.erase(0, line.find("=\"") + 2);
	string h = line.substr(0, line.find("\""));
	h = stoi(h);

	line.erase(0, line.find("=\"") + 2);
	string stroke = line.substr(0, line.find("\""));
	colorOutline = Couleur(stroke);

	line.erase(0, line.find("=\"") + 2);
	string fill = line.substr(0, line.find("\""));
	colorFill = Couleur(fill);
}


void Rectangle::setWidth(int w) {
    width = w;
}

void Rectangle::setHeight(int h) {
    height = h;
}

void Rectangle::setTopLeftCorner(const int x, const int y){
	topLeftCorner.x = x;
	topLeftCorner.y = y;
}
const Point& Rectangle::getTopLeftCorner() const {
    return topLeftCorner;
}

void Rectangle::setPivotCorner(const int x, const int y){
	pivotCorner.x = x;
	pivotCorner.y = y;
}
const Point& Rectangle::getPivotCorner() const {
    return pivotCorner;
}

int Rectangle::getWidth() const {
    return width;
}

int Rectangle::getHeight() const {
    return height;
}

void Rectangle::display() const {
	cout << label << " de coin ";
	topLeftCorner.display();
	cout << " de largeur=" << width << " et de hauteur=" << height;
	cout << " *** Outline : " << colorOutline.toString();
	cout << " & Fill : " << colorFill.toString();
}

// Méthodes virtuelles

void Rectangle::move(int offsetX, int offsetY) {
    topLeftCorner.move(offsetX, offsetY);
}

float Rectangle::getSurface() const {
    return (float)(width * height);
}

float Rectangle::getPerimeter() const {
    return (float)(2*width + 2*height);
}


void Rectangle::draw(wxPaintDC& dc){
	dc.DrawRectangle(topLeftCorner.x, topLeftCorner.y, width, height) ;
}

string Rectangle::toSVG(){
	string xStr = to_string(topLeftCorner.x);
	string yStr = to_string(topLeftCorner.y);
	string wStr = to_string(width);
	string hStr = to_string(height);

	string outline = colorOutline.toString();
	string fill = colorFill.toString();

	return "<rect x=\""+xStr+"\" y=\""+yStr+"\" width=\""+wStr+"\" height=\""+hStr+"\" stroke=\""+outline+"\" fill=\""+fill+"\"/>";	
}

string Rectangle::toString(){
	string w = to_string(width);
	string h = to_string(height);

	string perimetre = to_string(getPerimeter());
	string surface = to_string(getSurface());

	string outline = colorOutline.toString();
	string fill = colorFill.toString();

	return "Dessin d'un rectangle | Couleur contour "+outline+" & remplissage "+fill+"  |  Perimetre = "+perimetre+"  Surface = "+surface;	
}




Point Rectangle::getCentre() const
{
	int x = (int) (getTopLeftCorner().x + getWidth()/2) ;
	int y = (int) (getTopLeftCorner().y + getHeight()/2) ;
	return Point(x,y) ;
}

bool Rectangle::Contains(int x, int y) const
{
	return ( (getTopLeftCorner().x <= x && x <= getTopLeftCorner().x+getWidth()) && (getTopLeftCorner().y <= y && y <= getTopLeftCorner().y+getHeight())) ;
}
