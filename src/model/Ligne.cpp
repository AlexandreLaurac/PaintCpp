#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include "Ligne.h"

using namespace std;


Ligne::Ligne(const int x1, const int y1, const int x2, const int y2, const string& label, const string& colorOutline, const string& colorFill) : Forme(label, colorOutline, colorFill) {
	pointStart.x = x1;
	pointStart.y = y1;

	pointEnd.x = x2;
	pointEnd.y = y2;
}

Ligne::Ligne(const int x1, const int y1, const int x2, const int y2, const string& label) : Forme(label) {
	pointStart.x = x1;
	pointStart.y = y1;

	pointEnd.x = x2;
	pointEnd.y = y2;
}


Ligne::Ligne(const Ligne& ligne) : Forme(ligne.label){
	pointStart.x = ligne.pointStart.x;
	pointStart.y = ligne.pointStart.y;

	pointEnd.x = ligne.pointEnd.x;
	pointEnd.y = ligne.pointEnd.y;
}


void Ligne::setPointStart(const int x, const int y){
	pointStart.x = x;
	pointStart.y = y;
}

void Ligne::setPointEnd(const int x, const int y){
	pointEnd.x = x;
	pointEnd.y = y;
}

const Point& Ligne::getPointStart() const {
	return pointStart;
}

const Point& Ligne::getPointEnd() const {
	return pointEnd;
}

int Ligne::getLength() const {
	return sqrt((pointEnd.x - pointStart.x)*(pointEnd.x - pointStart.x) + (pointEnd.y - pointStart.y)*(pointEnd.y - pointStart.y));
}


void Ligne::display() const {
	cout << label << " de départ ";
	pointStart.display();
	cout << " et de fin ";
	pointEnd.display();
	cout << " ****Couleur outline:" << colorOutline;
}

// Méthodes virtuelles

void Ligne::move(int offsetX, int offsetY) {
    pointStart.move(offsetX, offsetY);
    pointEnd.move(offsetX, offsetY);
}


void Ligne::draw(wxPaintDC& dc){
	dc.DrawLine(pointStart.x, pointStart.y, pointEnd.x, pointEnd.y) ;
}

string Ligne::toSVG(){
	string x1 = to_string(pointStart.x);
	string y1 = to_string(pointStart.y);
	string x2 = to_string(pointEnd.x);
	string y2 = to_string(pointEnd.y);
	string outline = colorOutline;


	return "<line x1=\""+x1+"\" y1=\""+y1+"\" x2=\""+x2+"\" y2=\""+y2+"\" stroke=\""+outline+"\" />";	
}



