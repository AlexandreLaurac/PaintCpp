#include <stdio.h>
#include "Point.h"


Point::Point(){
	x = 0;
	y = 0;
}

Point::Point(const Point::Point& point){
	set(point);
}

Point::Point(const int x, const int y){
	setX(x);
	setY(y);
}

Point& Point::operator(const Point& point){
	set(point);
	return *(this);
}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

void Point::setX(const int x){
	this.x = x;
}

void Point::setY(const int y){
	this.y = y;
}

void Point::set(const Point::Point& point){
	this.x = point.getX();
	this.y = point.getY();
}

void Point::move(int offsetX, int offsetY){
	// Bouge le point d'un certains offset
	this.x = setX(this.x + offsetX);
	this.y = setY(this.y + offsetY);
}

