#include <iostream>
#include <cstdlib>
#include <cmath> // pour sqrt

using namespace std;

#include "Forme.h"
#include "Rectangle.h"


int main()
{
    // test Display
    Rectangle r4( 0, 0, 100, 200, "r1" );
    cout << "******** Test du Display de differents objets\n";
    r4.display();
    cout << endl;

    // test Surface
    cout << "******** Test de la surface\n";
    cout << "Surface r4= " << r4.surface() << endl;
    cout << endl;

    return EXIT_SUCCESS;
}