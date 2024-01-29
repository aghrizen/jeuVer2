// window.cpp

#include "window.hpp"
#include "ToursWidget.hpp"
#include "DisqueWidget.hpp"
#include <iostream>
#include <glib-object.h>
#include "jeuHanoi.hpp"
#include "Disque.hpp"

JeuHanoiWindow::JeuHanoiWindow() : m_jeu(), m_disquesContainer(nullptr) {
    gtk_init(NULL, NULL);

    // Créer la fenêtre principale
    m_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(m_window), "Les Tours de Hanoi");
    gtk_window_set_default_size(GTK_WINDOW(m_window), 400, 300);
    g_signal_connect(G_OBJECT(m_window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Initialiser les objets Tour
    for (int i = 0; i < 3; ++i) {
        m_tours[i] = Tour(i);  // Utilisez le constructeur approprié
    }

    // Créer et ajouter les widgets de tour à la fenêtre
    for (int i = 0; i < 3; ++i) {
        m_tourWidgets[i] = TourWidget(&m_tours[i]);
        gtk_container_add(GTK_CONTAINER(m_window), m_tourWidgets[i].getWidget());
    }

    // Ajouter d'autres composants GTK et connecter les signaux...
    // Ajouter un bouton pour le mode Démo
    GtkWidget* buttonDemo = gtk_button_new_with_label("Mode Démo");
    g_signal_connect(buttonDemo, "clicked", G_CALLBACK(onDemoButtonClicked), this);
    gtk_container_add(GTK_CONTAINER(m_window), buttonDemo);

    // Ajouter un bouton pour le mode Défaut
    GtkWidget* buttonDefault = gtk_button_new_with_label("Mode Défaut");
    g_signal_connect(buttonDefault, "clicked", G_CALLBACK(onDefaultButtonClicked), this);
    gtk_container_add(GTK_CONTAINER(m_window), buttonDefault);

    // Afficher la fenêtre et démarrer la boucle GTK
    gtk_widget_show_all(m_window);
    gtk_main();
}

void JeuHanoiWindow::doDemo() {
    std::cout << "Mode Démo activé" << std::endl;
    m_jeu.jouer();
}

void JeuHanoiWindow::doDefault() {
    std::cout << "Mode Default activé" << std::endl;
    m_jeu.resoudre();
}

void JeuHanoiWindow::onDemoButtonClicked(GtkWidget* widget, gpointer data) {
    JeuHanoiWindow* jeuWindow = static_cast<JeuHanoiWindow*>(data);
    jeuWindow->doDemo();
    jeuWindow->afficherTours();
}

void JeuHanoiWindow::onDefaultButtonClicked(GtkWidget* widget, gpointer data) {
    JeuHanoiWindow* jeuWindow = static_cast<JeuHanoiWindow*>(data);
    jeuWindow->doDefault();
    jeuWindow->afficherTours();
}

void JeuHanoiWindow::afficherTours() {
    for (int i = 0; i < 3; ++i) {
        gtk_container_remove(GTK_CONTAINER(m_window), m_tourWidgets[i].getWidget());
    }

    for (int i = 0; i < 3; ++i) {
        m_tourWidgets[i] = TourWidget(&m_tours[i]);
        gtk_container_add(GTK_CONTAINER(m_window), m_tourWidgets[i].getWidget());
    }

    gtk_widget_show_all(m_window);
}

void JeuHanoiWindow::afficherDisque() {
    gtk_container_remove(GTK_CONTAINER(m_window), m_disquesContainer);

    m_disquesContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(m_window), m_disquesContainer);

    for (int i = 0; i < m_jeu.getNombreDisques(); ++i) {
        Disque* disque = m_jeu.getTour(0)->getDisque(i);
        DisqueWidget disqueWidget(disque);
        gtk_container_add(GTK_CONTAINER(m_disquesContainer), disqueWidget.getWidget());
    }

    gtk_widget_show_all(m_window);
}

// window.cpp

// ...


void JeuHanoiWindow::disconnectSignals(gpointer data) {
    // Déconnecter les signaux GTK
    for (int i = 0; i < 3; ++i) {
        g_signal_handlers_disconnect_matched(m_tourWidgets[i].getWidget(), G_SIGNAL_MATCH_FUNC, 0, 0, NULL, NULL, G_CALLBACK(g_cclosure_marshal_VOID__VOID));
    }
}

// window.cpp

// ...

JeuHanoiWindow::~JeuHanoiWindow() {
    // Utilisez la fonction disconnectSignals pour déconnecter les signaux GTK
    disconnectSignals(nullptr);

    // Détruire les widgets de tour
    for (int i = 0; i < 3; ++i) {
        gtk_widget_destroy(m_tourWidgets[i].getWidget());
    }

    // Détruire le conteneur des disques
    gtk_widget_destroy(m_disquesContainer);

    // Fermer la boucle principale de GTK
    gtk_main_quit();
}
