#include <iostream>
#include <cmath>

#include "Point.h"


using namespace std;

Point::Point(){
	x = 0;
	y = 0;
}

Point::Point(const int x, const int y){
	this->x = x;
	this->y = y;
}

void Point::move(int offsetX, int offsetY){
	// Bouge le point d'un certains offset
	x = x + offsetX;
	y = y + offsetY;
}

void Point::display() const{
	cout << "(" << x << "," << y << ")";
}


double Point::distancePoint(int x, int y) const
{
	return sqrt ((this->x-x)*(this->x-x)+(this->y-y)*(this->y-y)) ;
}