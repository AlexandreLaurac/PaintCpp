### Application de tracé de figures

Application de tracé de figures "à la Paint" écrite en C++ avec la bibliothèque wxWidgets.  
Projet réalisé en binôme pendant une semaine à temps plein en juin 2022 (module projet tuteuré en C++ du DUT d'informatique en année spéciale).  

Les attendus comprenaient : le tracé de différents types de figures, le choix de leurs couleurs (bordure et intérieur), la sélection, le déplacement et la suppression d'une figure, la sauvegarde et la lecture d'un fichier au format SVG.  
Presque toutes ces fonctionnalités ont totalement ou partiellement été implémentées.

Le code est structuré selon le paradigme MVC.  

Voir le fichier grille_rendu_projet.pdf pour la description des fonctionnalités implémentées, les informations techniques sur le projet et l'état de développement des différentes fonctionnalités.  

Pour obtenir l'exécutable, il convient d'avoir installé cmake et wxWidgets. 
Lancer ensuite les commandes :
```
cmake -S . -B build
cmake --build build
```
L'exécutable **skeleton** obtenu est situé dans le dossier build.
