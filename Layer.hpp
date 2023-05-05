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
    //! Nombre de neurones que l'on a en entrée
    int Nbe;
    //! Nombre de neurones que l'on a en sortie
    int Nbs;   
    void activation(Layer L);

    //! Matrice contenant les poids des aretes reliant cette couche a la suivante
    Matrix arete;
    
    //! Matrice contenant les delta de chaque poids 
    Matrix delta;
    
    //! Matrice des entrees
    Matrix entree;
    
    //! Matrice des sorties
    Matrix sortie;
    
    //! Matrice des etiquettes
    Matrix etiq;
    
    
    
    
    //! Fonction d activation utilisee par la couche
    double fonctionActivation(double x);
    
    //! Getter et Setter
    
    //! Setter
    
    void setWeights(Matrix<double> s);
    void setEntree(Matrix<double> e);
   
    
    
    

public:
    //! Constructeur
    Layer();
    Layer(int Nbe, int Nbs, Matrix arete, Matrix delta, double fonctionActivation);
    Layer(int Nbe, int Nbs);
    
    //! Calcul de la matrice des deltas
    void calculerDelta(Layer L);
    //! Affiche la matrice des poids
    void displayWeight(Matrix weight);

    //! Destructeur
    ~Layer();
};

#endif
