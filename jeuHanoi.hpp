/*
 ************************************************************************************
 * Authors: salma.aghrizen@etu.univ-cotedazur.fr, bastien.briat@etu.univ-cotedazur.fr
 ************************************************************************************
 *
 * Ce script contient la déclaration de la classe ToursHanoi pour décrir le déroulement du jeu.
 */

#ifndef JEUHANOI_CLASS
#define JEUHANOI_CLASS
#include <iostream>
#include <string>
#include "Tours.hpp"
using namespace std;


const int T_MAX = 3; // le nombre MAX des tours
class ToursHanoi
{
public:
	explicit ToursHanoi(int n);
	void afficherTours() const;
	void jouer();
	void resoudre();
private:
	bool deplacer(int o, int d);
	bool checkWin();
	void hanoi(int n, int orig, int dest, int inter);
	void initialiser();


	Tour* m_tours[T_MAX]; // les tours
	int m_hauteur; // nombre de disques

	int m_deplacement; // nombre de deplacements
};

#endif
