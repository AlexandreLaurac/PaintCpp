#include <cassert>
#include <string>
#include <iostream>

using namespace std;

#include "Forme.h"
#include "Rectangle.h"
#include "Dessin.h"


int main()
{

    cout << endl;
    cout << "******** Test de la classe Point" << endl;
    Point p1;
    assert(p1.x == 0);
    assert(p1.y == 0);
    cout << "Point par défault ";
    p1.display();
    cout << endl;

    Point p2(10,5);
    assert(p2.x == 10);
    assert(p2.y == 5);
    cout << "Point ";
    p2.display();
    cout << endl;

    p2.move(2,3);
    assert(p2.x == 12);
    assert(p2.y == 8);
    cout << "Move de p2 de (2,3) -> ";
    p2.display();
    cout << endl;


    cout << endl;
    cout << "******** Test de la classe Rectangle" << endl;
    
    Rectangle r1( 0, 0, 100, 200, "r1" );
    r1.display();
    cout << endl;

    Rectangle r2( 0, 8, 10, 2, "r2" );
    r1.display();
    cout << endl;

    cout << "******** Test des méthodes virtuelles" << endl;
    assert(r1.surface() == 20000);
    cout << "Surface r1 -> " << r1.surface() << endl;

    assert(r1.perimeter() == 600);
    cout << "Périmètre r1 -> " << r1.perimeter() << endl;

    assert(r1.getId() == 1);
    cout << "id r1 -> " << r1.getId() << endl;

    assert(r2.getId() == 2);
    cout << "id r2 -> " << r2.getId() << endl;

    r1.move(10,5);
    assert(r1.getCorner().x == 10);
    assert(r1.getCorner().y == 5);
    cout << "Move r1 de (10,5) -> ";
    r1.display();
    cout << endl;

    cout << endl;
    cout << "******** Test de la classe Dessin" << endl;
    Dessin d1;
    assert(d1.getList().size() == 0);
    d1.displayList();
    cout << endl;

    cout << "******** Test des méthodes d'ajouts de forme" << endl;
    d1.addForme(&r2);
    assert(d1.getList().size() == 1);
    d1.displayList();
    cout << endl;

    Rectangle r3(0,0,1,8,"r3");
    d1.addForme(&r3);
    assert(d1.getList().size() == 2);
    d1.displayList();
    cout << endl;

    cout << "******** Test des méthodes de suppression de forme" << endl;
    d1.deleteForme(&r2);
    assert(d1.getList().size() == 1);
    d1.displayList();
    cout << endl;


    





    



    return EXIT_SUCCESS;
}