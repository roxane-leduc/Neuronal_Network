#ifndef __LAYER_HPP__
#define __LAYER_HPP__

#include "Matrix.hpp"
#include "Neurone.hpp"

#include <list>
using std::list;

class Layer
{
private:
    list<Neurone> neurones;
    int nbNeurone;
    //! Matrice contenant les poids des aretes reliant cette couche a la suivante
    Matrix arete;
    //! Matrice contenant les delta de chaque poids 
    Matrix delta;
    //! Savoir quelle fonction d activation est utilisee par la couche
    double fonctionActivation;

public:
    //! Constructeur
    Layer();
    void activation(Layer L);
    void calculerDelta(Layer L);
    //! Affiche la matrice des poids
    void displayWeight(Matrix weight);
    void affichage();
    //! Destructeur
    ~Layer();
};

#endif