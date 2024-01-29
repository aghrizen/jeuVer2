/*
 ************************************************************************************
 * Authors: salma.aghrizen@etu.univ-cotedazur.fr, bastien.briat@etu.univ-cotedazur.fr
 ************************************************************************************
 *
 * Ce script contient la déclaration de la classe disque
 * Chaque disque contient sa propre taille, en fonction de nombre des disques choisis par l'utilisateur.
*/

// Pour garantir qu'il n'ya pas des doubles inclusions de ce fichier:
#ifndef TOURSHANOI_DISQUE_CLASS
#define TOURSHANOI_DISQUE_CLASS
#include <string>
using namespace std;

// La déclaration de la classe:
class Disque {
	// La déclarations des éléments publiques:
public:
	// La déclaration du constructeur:
	Disque();
	/* La déclaration du constructeur avec ces paramètres
	 * s: la taille
	 * t: la taille du jeu
	 */
	Disque(int s, int t);
	int getTaille();
	// pour retourner une présentation sous forme de chaîne du disque
	string toString();
	// La déclaration des éléments privés:
private:
	// la taille de notre disque
	int m_taille;
	// la taille de notre jeu
	int m_jeusize;
};


#endif
