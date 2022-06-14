#include <cassert>

using namespace std;

#include "Forme.h"
#include "Rectangle.h"


int main()
{

    cout << endl;
    cout << "******** Test de la classe Point\n";
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
    cout << "******** Test de la classe Rectangle\n";
    Rectangle r1( 0, 0, 100, 200, "r1" );
    r1.display();
    cout << endl;
    cout << "******** Test des méthodes virtuelles\n";
    assert(r1.surface() == 20000);
    cout << "Surface r1 -> " << r1.surface() << endl;
    assert(r1.perimeter() == 600);
    cout << "Périmètre r1 -> " << r1.perimeter() << endl;

    r1.move(10,5);
    assert(r1.getCorner().x == 10);
    assert(r1.getCorner().y == 5);
    cout << "Move r1 de (10,5) -> ";
    r1.display();
    cout << endl;
    cout << endl;



    



    return EXIT_SUCCESS;
}