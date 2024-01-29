/*
 ************************************************************************************
 * Authors: salma.aghrizen@etu.univ-cotedazur.fr, bastien.briat@etu.univ-cotedazur.fr
 ************************************************************************************
 * Ce script contient la déclaration des fonctions de la classe Disque
 */

#include "Disque.hpp"

 // Un constructeur par défaut.
Disque::Disque() : m_taille(0), m_jeusize(1) {}

/*
 * Un constructeur normal avec les paramètres du disque:
 *   t = la taille du jeu
 *   s = la taille du disque
 */
Disque::Disque(int s, int t) : m_taille(s), m_jeusize(t) {}

/*
 * Fonction getTaille(): fonction qui retourne la taille de disque.
 * Résultat: entier représentant la taille du disque.
 */

int Disque::getTaille()
{
	return m_taille;
}


/*
 * toString(): Fonction qui  utilise la taille du disque pour déterminer le nombre d'espaces avant
 * et après la représentation du disque, de sorte que le disque semble centré dans le jeu
 * Résultat: elle retourne le disque en caractères.
 */

string Disque::toString()
{
	// Si la taille du disque est 0, la variable nespaces est égale (la taille du jeu)-1, sinon, 
	// est égale (la taille du jeu)- taille du disque.
	int nespaces = (getTaille() == 0 ? m_jeusize - 1U : m_jeusize - getTaille());
	return string(nespaces, ' ')
		+ (getTaille() == 0 ? "|" : string(2 * getTaille() - 1, '*'))
		+ string(nespaces, ' ')
		+ " ";
}
