CXX = g++            # le compilateur à utiliser
CXXFLAGS = -g -Wall -pedantic -std=c++11 `pkg-config --cflags gtk+-3.0` # les options du compilateur
LDFLAGS = -lsx `pkg-config --libs gtk+-3.0`  # les options pour l'éditeur de liens
SRC = main.cpp Tours.cpp jeuHanoi.cpp Disque.cpp window.cpp ToursWidget.cpp DisqueWidget.cpp # les fichiers sources
PROG = hanoi          # nom de l'exécutable
OBJS = $(SRC:.cpp=.o) # les .o qui en découlent
.SUFFIXES: .cpp .o     # lien entre les suffixes

all: run

# étapes de compilation et d'édition de liens
# $@ la cible  $^ toutes les dépendances
$(PROG): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

Disque.o: Disque.hpp
Tours.o: Tours.hpp Disque.hpp
jeuHanoi.o: jeuHanoi.hpp Disque.hpp Tours.hpp
window.o: window.hpp Tours.hpp Disque.hpp ToursWidget.hpp
ToursWidget.o: ToursWidget.hpp Tours.hpp Disque.hpp
DisqueWidget.o: DisqueWidget.hpp Disque.hpp
main.o: jeuHanoi.hpp Tours.hpp Disque.hpp window.hpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# exécute l'interface
run: $(PROG)
	./$(PROG)

# pour faire propre
.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)
