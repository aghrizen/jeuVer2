#ifndef DISQUE_WIDGET_HPP
#define DISQUE_WIDGET_HPP

#include <gtk/gtk.h>
#include "Disque.hpp"  // Assurez-vous d'inclure la classe Disque

class DisqueWidget {
public:
    DisqueWidget(Disque* disque);  // Constructeur prenant un pointeur vers un objet Disque
    GtkWidget* getWidget();  // Fonction pour obtenir le widget associé au DisqueWidget

private:
    GtkWidget* m_widget;
    Disque* m_disque;  // Un pointeur vers l'objet Disque associé à ce widget

    // Autres membres et fonctions nécessaires...
};

#endif // DISQUE_WIDGET_HPP
