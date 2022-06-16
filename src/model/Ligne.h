#ifndef __LIGNE_H__
#define __LIGNE_H__

#include "Forme.h"
#include "Point.h"

//-------------------------------------------
class Ligne : public Forme
//-------------------------------------------
{
    
public:          
    Ligne(){};                           
    Ligne(const int x1, const int y1, const int x2, const int y2, const std::string& label, const Couleur colorOutline, const Couleur colorFill); // constructeur avec couleurs perso
    Ligne(const int x1, const int y1, const int x2, const int y2, const std::string& label); // constructeur avec couleurs par défauts
    Ligne(const Ligne& Ligne);

    Ligne& operator=(const Ligne& LigneToCopy);

    virtual ~Ligne(){};

    // Setters
    void setPointStart(const int x, const int y);
    void setPointEnd(const int x, const int y);

    // Getters
    const Point& getPointStart() const;    
    const Point& getPointEnd() const;  
	int getLength() const;  

	// Méthodes virtuelles
	virtual void display() const;
    //virtual float perimeter() const override;
	virtual void move(int offsetX, int offsetY);
    virtual void draw(wxPaintDC& dc);
    virtual std::string toSVG();
    
    virtual Point getCentre() const ;
    //virtual double getDistancePoint(int x, int y) const ;
    virtual bool Contains(int x, int y) const {return false ;} ; // TEMPORAIRE


private: 
    Point pointStart;         
    Point pointEnd;         
            

};

#endif
