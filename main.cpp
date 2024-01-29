#include <iostream>
#include "jeuHanoi.hpp"
#include "window.hpp"

using namespace std;

int main() {
    int nd; // nombre des disques pour le jeu
    int choixMode; // choix du mode de jeu: défailt ou démo

    cout << "Veuillez choisir un numéro des diques pour commencer le jeu: ";
    cin >> nd;

    cout << "Choisissez le mode de jeu :\n";
    cout << "1. Mode Default\n";
    cout << "2. Mode Démo\n";
    cout << "Votre choix: ";
    cin >> choixMode;
    ToursHanoi jeu(nd);

    switch (choixMode) {
        case 1:
            jeu.jouer(); // Deafult Mode: à utilisateur de jouer
            break;
        case 2:
            jeu.resoudre(); // Démo Mode: à l'ordi de jouer
            break;
        default:
            cout << "Choix invalide.\n";
            return 1;
    }
    JeuHanoiWindow jeuWindow;
    return 0;
}
