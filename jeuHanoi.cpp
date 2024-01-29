/*
 ************************************************************************************
 * Authors: salma.aghrizen@etu.univ-cotedazur.fr, bastien.briat@etu.univ-cotedazur.fr
 ************************************************************************************
 * Ce script contient la déclaration des fonctions définit dans le jeuHanoi.hpp
 */

 /*
  * Rôle: déplacer le disque de la positio origine vers la position destination
  * paramètres:
  * --> po: position d'origine
  * --> pd:position de destination
  */
#include "jeuHanoi.hpp"
#include "Disque.hpp"
#include "Tours.hpp"
#include <iostream>
using namespace std;

bool ToursHanoi::deplacer(int po, int pd) {
	bool IsMovePossible;
	Tour* orig = m_tours[po];
	Tour* dest = m_tours[pd];
	
	IsMovePossible = orig->MoveDisk(dest);

	return IsMovePossible;
}

/*
 * La méthode principale récursive pour le jeu du Hanoi
 * Les variables:
 * --> n: le nombre des disques
 * --> orig: la tour origine
 * --> dest: la tour de la destination
 * --> inter: la tour intérmediaire
 */
void ToursHanoi::hanoi(int n, int orig, int dest, int inter) {
	if (n > 0) {
		hanoi(n - 1, orig, inter, dest);
		deplacer(orig, dest);
		afficherTours();
		hanoi(n - 1, inter, dest, orig);
	}
}

/*
 * Cette fonction permet de initialiser certaines variable de la classe définit dans jeuHanoi.hpp
 */
void ToursHanoi::initialiser() {
	// initialiser le premier élément de m_tours avec m_hauteur éléments avec la valeur false
	m_tours[0] = new Tour(1, m_hauteur);
	// initialiser le deuxième élément de m_tours avec m_hauteur éléments avec la valeur true
	m_tours[1] = new Tour(2);
	// initialiser le troisième élément de m_tours avec m_hauteur éléments avec la valeur true
	m_tours[2] = new Tour(3);
	m_deplacement = 0;
}


/*
 * Cette fonction est un constructeur de la classe ToursHanoi définit dans jeuHanoi.hpp
 * Input: un entier n
 * Rôle: initialise l'objet ToursHanoi en utilisant une hauteur spécifiée
 */
ToursHanoi::ToursHanoi(int n)
// D_MAX: nombre maximum des disques 
	: m_hauteur(n < MAX_DISQUE ? n : MAX_DISQUE) {
	if (n >= MAX_DISQUE) {
		m_hauteur = MAX_DISQUE;
	}
}

/*
 * Cette fonction a pour but d'afficher l'état actuel du jeu
*/
void ToursHanoi::afficherTours() const {
	// variable 's' pour construire la représentation du jeu
	string s;
	for (int i = m_hauteur - 1; i >= 0; --i) {
		if (m_tours[0]->getDisque(i) != NULL)
			s += m_tours[0]->getDisque(i)->toString();
		if (m_tours[1]->getDisque(i) != NULL)
			s += m_tours[1]->getDisque(i)->toString();
		if (m_tours[2]->getDisque(i) != NULL)
			s += m_tours[2]->getDisque(i)->toString();
		s += "\n";
	}
	// construction d'une chaîne de caractères '*' qui représente le socle du jeu
	s += string(47, '-'); // 6*8 - 1 = 47 pour garder toujours même taille 
	                      // de socle quelque soit le nombre des disques 
	s +="\n";
	// affichage de la chaîne du jeu
	cout << s << endl;
}

/*
 * Rôle: cette fonction permet de vérifier si le joueur a gagné
 * Output: elle retourne 'vrai' si tous les disques sont placés vers la tour de destination
 * Sinon, elle retourne 'false'
 */
bool ToursHanoi::checkWin() {
	// Si la derniere tour a atteint la hauteur max --> Tout les disques sont sur la derniee tour
	if (m_tours[2]->TourSize >= m_hauteur) 
	{
		return true;
	}
	// si aucun disque maquant n'est trouvé, le joueur a gagné
	return false;
}


/*
 * Cette fonction permet d'éxecuter le jeu
*/
void ToursHanoi::resoudre() {
	initialiser();
	afficherTours();
	hanoi(m_hauteur, 0, 2, 1);
	cout << "Nombre de deplacements = " << m_deplacement << endl;

	if (checkWin()) {
		cout << "Félicitations ^^ vous avez gangé :) !" << endl;
	}
	else {
		cout << "Vous n'avez pas gagné :( ." << endl;
	}
}

void ToursHanoi::jouer() {
	initialiser();
	string reponse;
	int origine_index;
	int destination_index;
	bool IsMoveLegal;

	while (checkWin() == false)
	{
		afficherTours();

		cout << "Choisir la colonne origine, puis la colonne destination, de 1 à 3, sans espace" << endl;
		cin >> reponse;

		origine_index = reponse[0] - '0';
		destination_index = reponse[1] - '0';

		if (origine_index >= 1 && origine_index <= 3 && destination_index >= 1 && destination_index <= 3)
		{

			IsMoveLegal = m_tours[origine_index -1]->MoveDisk(m_tours[destination_index -1]);

			if (IsMoveLegal == true)
			{
				continue;
			}
			else
			{
				//Aficher rouge
				cout << "Numéro de tour invalide, veuillez recommencer" << endl;
			}
		}
		else
		{
			//Aficher rouge
			cout << "Numéro de tour invalide, veuillez recommencer" << endl;
		}
		
	}
	



	cout << "Nombre de deplacements = " << m_deplacement << endl;

	if (checkWin()) {
		cout << "Félicitations ^^ vous avez gangé :) !" << endl;
	}
	else {
		cout << "Vous n'avez pas gagné :( ." << endl;
	}
}
