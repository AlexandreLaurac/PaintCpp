#include <string>
#include <iostream>

#include "Dessin.h"

using namespace std;

// Verifier qu'il y a dupplication de mémoire de formetoadd dans le vector
// SI oui, supprimer la forme toAdd apres l'avoir init dans la liste

void Dessin::addForme(Forme* formeToAdd){
	try {
		listFormes.push_back(formeToAdd);
	} catch (bad_alloc& ex) {
		cerr << "Impossible d'allouer au vector" << endl;
		throw;
	}
}

void Dessin::deleteForme(Forme* formeToDelete){
	unsigned i = 0;
	size_t size = listFormes.size();
	bool findForme = false;

	while (i < size && !findForme){
		if (formeToDelete == listFormes.at(i)){
			listFormes.erase(listFormes.begin()+i);
			findForme = true;

			delete formeToDelete;
		}
		i++;
	}	

	if (!findForme){
		cerr << "La Forme n'a pas été trouvée ! Suppression impossible" << endl;
	}
}

vector<Forme*> Dessin::getList() const{
	return listFormes;
}


void Dessin::SetCurrentForm(Forme * form)
{
	currentForm = form ;
}


void Dessin::displayList() const {
	cout << "listFormes={";
	for (size_t i = 0; i < listFormes.size(); i++){
		if (i == (listFormes.size() - 1)){
			cout << listFormes.at(i)->getLabel();

		} else {
			cout << listFormes.at(i)->getLabel() << ";" ;
		}
	}
	cout << "}";
}

void Dessin::deleteList() {
	for (Forme* forme : listFormes){
		deleteForme(forme);
	}
}

void Dessin::drawAllFormes(wxPaintDC& dc) const {
	for (Forme* forme : listFormes){

		array<unsigned int,4> colorOutline = forme->getColorOutline().toArray(); 
		array<unsigned int,4> colorFill = forme->getColorFill().toArray(); 

		wxColour c1 = wxColour(colorOutline[0], colorOutline[1], colorOutline[2], (int) colorOutline[3]*255);
		wxColour c2 = wxColour(colorFill[0], colorFill[1], colorFill[2], (int) colorFill[3]*255);

		dc.SetPen(c1);
		dc.SetBrush(c2);
		forme -> draw(dc);
	}
}

void Dessin::saveSVG(const char* path){
	try{
		FILE* f = fopen(path, "w") ;

		fprintf(f,"<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
		for (Forme* forme : listFormes){
			fprintf(f,"\t");
			fprintf(f,forme->toSVG().c_str());
			fprintf(f,"\n");
		}
		fprintf(f,"</svg>");

		fclose(f);
	} catch(const exception& e){
		cout << "Erreur dans l'ouverture du fichier" << endl;
		cout << e.what() << endl;
		throw;
	}

}
