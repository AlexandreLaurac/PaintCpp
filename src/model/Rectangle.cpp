#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Rectangle.h"

using namespace std;


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


