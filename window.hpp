// window.hpp

#ifndef JEU_HANOI_WINDOW_HPP
#define JEU_HANOI_WINDOW_HPP

#include <gtk/gtk.h>
#include "jeuHanoi.hpp"  // Assurez-vous d'inclure la classe ToursHanoi
#include "ToursWidget.hpp"
#include <glib-object.h>


class JeuHanoiWindow {
public:
    JeuHanoiWindow();
    ~JeuHanoiWindow();

private:
    GtkWidget* m_window;
    TourWidget m_tourWidgets[3];
    ToursHanoi m_jeu;  // Utilisez une instance de ToursHanoi plutôt qu'une référence
    GtkWidget* m_disquesContainer; // Ajoutez la déclaration du conteneur de disques
    Tour m_tours[3];  // Ajoutez la déclaration du tableau m_tours
    // Autres membres et fonctions...
    // Déclaration des fonctions de rappel pour les boutons, etc.
    void afficherTours();
    void afficherDisque();
    static void onDemoButtonClicked(GtkWidget* widget, gpointer data);
    static void onDefaultButtonClicked(GtkWidget* widget, gpointer data);
    static void disconnectSignals(gpointer data);
    void doDemo();
    void doDefault();
};

#endif // JEU_HANOI_WINDOW_HPP
