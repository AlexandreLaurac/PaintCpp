#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include "Rectangle.h"

using namespace std;


Rectangle::Rectangle(const int x, const int y, const int w, const int h, const string& label, const string& colorOutline, const string& colorFill) : Forme(label, colorOutline, colorFill) {
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
    topLeftCorner.x = rectangle.getCorner().x;
	topLeftCorner.y = rectangle.getCorner().y;
	width = rectangle.getWidth();
	height = rectangle.getHeight();
}



void Rectangle::setWidth(int w) {
    width = w;
}

void Rectangle::setHeight(int h) {
    height = h;
}

const Point& Rectangle::getCorner() const {
    return topLeftCorner;
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
	cout << " *** Outline : " << colorOutline << " & Fill : " << colorFill;
}

// Méthodes virtuelles

void Rectangle::move(int offsetX, int offsetY) {
    topLeftCorner.move(offsetX, offsetY);
}

float Rectangle::surface() const {
    return (float)(width * height);
}

float Rectangle::perimeter() const {
    return (float)(2*width + 2*height);
}


void Rectangle::draw(wxPaintDC& dc){
	dc.DrawRectangle(wxPoint(topLeftCorner.x, topLeftCorner.y), wxSize(width,height)) ;
}

string Rectangle::toSVG(){
	string xStr = to_string(topLeftCorner.x);
	string yStr = to_string(topLeftCorner.y);
	string wStr = to_string(width);
	string hStr = to_string(height);
	string outline = colorOutline;
	string fill = colorFill;

	return "<rect x='"+xStr+"' y='"+yStr+"' width='"+wStr+"' height='"+hStr+"' stroke='"+outline+"' fill='"+colorFill+"'/>";	
}



