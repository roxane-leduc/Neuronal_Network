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
    
    //! Vecteur des biais de la couche
    Matrix biais;
    
    void activation(Layer L);

    //! Matrice contenant les poids des aretes reliant cette couche a la suivante
    Matrix arete;
    
    //! Matrice contenant les delta de chaque poids 
    Matrix delta;
    
    //! Vecteur des entrees
    Matrix entree;
    
    //! Vecteur des sorties
    Matrix sortie;
    
    //! Vecteur des etiquettes
    Matrix etiq;
    
     //! Vecteur des delta_j
    Matrix d;
    
    
    
    
    
    //! Fonction d activation utilisee par la couche
    double fonctionActivation(double x);
    
    //! Getter 
    
    
    Matrix<double> getEntree();
    Matrix<double> getPoids();
    Matrix<double> getSortie();
    Matrix<double> getDelta() ;
    Matrix<double> getEtiq();
    Matrix<double> getD();    
    
    //! Setter
    
    void setPoids(Matrix<double> s);
    void setEntree(Matrix<double> e);
    void setEtiquette(Matrix<double> et);
    
    
    

public:
    //! Constructeur
    Layer();
    Layer(int Nbe, int Nbs, Matrix arete, Matrix delta, double fonctionActivation);
    Layer(int Nbe, int Nbs);
    
    //! Calcul de la matrice des deltas
   
    void calculerDelta(Layer L, Matrix d_pred, Matrix biais)
    
    //! Affiche la matrice des poids
    void displayWeight();
    
    //! Calcul et remplissage du vecteur de sortie
    Matrix<double> sortie()

    //! Destructeur
    ~Layer();
};

#endif
