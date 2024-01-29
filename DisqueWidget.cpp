// disque.cpp

#include "DisqueWidget.hpp"

DisqueWidget::DisqueWidget(Disque* disque) : m_disque(disque) {
    // Créer le widget GTK pour représenter visuellement le disque
    m_widget = gtk_label_new(m_disque->toString().c_str());
}

DisqueWidget::DisqueWidget() : m_disque(nullptr), m_widget(nullptr) {
    // Initialisez vos membres ici si nécessaire
}

GtkWidget* DisqueWidget::getWidget() {
    return m_widget;
}
