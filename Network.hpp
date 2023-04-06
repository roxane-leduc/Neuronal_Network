#ifndef __NETWORK_HPP__
#define __NETWORK_HPP__

#include "Layer.hpp"
#include "HiddenLayer.hpp"
#include "Matrix.hpp"

#include <list>
using std::list;

class Network
{
private:
    //! Nombre de couches cachees
    int nbHiddenLayer;
    //! Indicateur permettant de savoir si le reseau est efficace ou non 
    double fiabilite;
    Layer inputLayer;
    Layer outputLayer;
    list<HiddenLayer> hidden;

public:
    //! Constructeur
    Network(int tailleDeHidden, int outputDim);
    //! Entrainement du reseau
    void training(Matrix TrainXSet, Matrix TrainYSet, double LearningRate, int TailleLot);
    //! Mettre a jour une couche
    void set_layer(Layer L);
    //! Test du reseau
    void test(Matrix TestXSet, Matrix TestYSet);
    //! Affiche la valeur de sortie de chaque neurone
    void forward_propagation(Matrix TrainXSet);
    //! Afficher l’erreur au niveau de chaque couche
    void backward_propagation(Matrix TrainXSet);
    //! Mise a jour de la valeur des poids (prend en parametre une vitesse d apprentissage)
    void update_poids(double learningRate);
    //! Observer la sortie du reseau
    void display_result();
    //! Connaitre la fiabilite du reseau
    void calcul_fiabilite();
    //! Destructeur
    ~Network();
}

#endif
