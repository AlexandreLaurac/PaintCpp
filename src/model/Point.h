#ifndef __POINT_H__
#define __POINT_H__

//-------------------------------------------
class Point
//-------------------------------------------
{
	
public :

	Point();
	Point(const int x, const int y);

	void move(int offsetX, int offsetY);

	void display() const;

	int x;
	int y;
};

#endif