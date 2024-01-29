#include "Tours.hpp"
#include "Disque.hpp"
#include "TourWidget.hpp"
TourWidget::TourWidget() : m_tour(nullptr), m_widget(nullptr), m_disquesContainer(nullptr) {
    // Initialisez vos membres ici si nécessaire
}

TourWidget::TourWidget(Tour* tour) : m_tour(tour) {
    // Créer le widget GTK pour représenter visuellement la tour
    m_widget = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    
    // Ajouter un conteneur GTK pour les DisqueWidgets
    m_disquesContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(m_widget), m_disquesContainer);

    // Ajouter des DisqueWidgets pour chaque disque dans la tour
    for (int i = 0; i < tour->TourSize; ++i) {
        Disque* disque = tour->getDisque(i);
        DisqueWidget disqueWidget(disque);
        gtk_container_add(GTK_CONTAINER(m_disquesContainer), disqueWidget.getWidget());
    }
}

GtkWidget* TourWidget::getWidget() {
    return m_widget;
}
