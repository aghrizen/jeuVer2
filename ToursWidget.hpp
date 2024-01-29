// TourWidget.hpp
#ifndef TOUR_WIDGET_HPP
#define TOUR_WIDGET_HPP

#include <gtk/gtk.h>
#include "Tours.hpp"  // Assurez-vous d'inclure la classe Tour

class TourWidget {
public:
    TourWidget();
    TourWidget(Tour* tour);  // Constructeur prenant un pointeur vers un objet Tour
    GtkWidget* getWidget();  // Fonction pour obtenir le widget associé au TourWidget
    //void afficherTours();
private:
    GtkWidget* m_widget;
    Tour* m_tour;  // Un pointeur vers l'objet Tour associé à ce widget
    GtkWidget* m_disquesContainer;
    // Autres membres et fonctions nécessaires...
};

#endif // TOUR_WIDGET_HPP
