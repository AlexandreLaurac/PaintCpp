#ifndef __POINT_H__
#define __POINT_H__

//-------------------------------------------
class Point
//-------------------------------------------
{
	
public :

	Point();
	Point(const int x, const int y);

	void move(int X, int Y);  // attention, c'est un déplacement direct au point écrit

	void display() const;

	double distancePoint (int x, int y) const ;

	int x;
	int y;
};

#endif