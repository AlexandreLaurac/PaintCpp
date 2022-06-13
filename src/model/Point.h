#ifndef __POINT_H__
#define __POINT_H__

class Point{

public :

	Point();
	Point()
	Point(const int x, const int y);

	~Point();

	// Operator d'affectation
    Point& operator=(const Point& other);

	int getX() const;
	int getY() const;

	void setX(const int x);
	void setY(const int y);
	void set(const Point point);

	void move(int offsetX, int offsetY);

private:
	int x;
	int y;


};

#endif