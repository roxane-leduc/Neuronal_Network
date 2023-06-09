#ifndef __LAYER_HPP__
#define __LAYER_HPP__

#include "Matrix.hpp"
#include "Neurone.hpp"
#include "TrainingFunction.hpp"

#include <list>
using namespace std;
typedef double (*activation_function)(double);
class Layer
{ 

    



    protected:

    //! Vecteur des sorties avant calcul avec la fonction d'activation
        Matrix I;
    //! Nombre de neurones que l'on a en entrée(inutile)
        int Nbe;
    //! Nombre de neurones que l'on a en sortie(inutile)
        int Nbs;   
    
    //! Vecteur des biais de la couche
        Matrix biais;
    
    //! Matrice contenant les poids des aretes reliant cette couche a la suivante
        Matrix arete;
    
    //! Vecteur des delta_j
        Matrix delta;

    //! Vecteur des etiquettes(inutile)
        Matrix etiq;
    
    //! Vecteur des entrees
        Matrix entree;

    //! Classe des fonctions d'activation
        activation_function Fonction;
        activation_function deriveFonction;

    //! Setter
    
    public:
    
    /**
    @brief Permet de donner des valeurs aux élèments de la matrice des poids des neurones de la couche 
    @param eParam : matrice
    */

    void setArete(Matrix & arete);
    Matrix& getArete();
    /**
    
    @brief Permet de donner des valeurs aux élèments la matrice des poids des neurones de la couche
    
    */
    //inutile
    void PoidsAleatoires();
    
    
    
    
    /**
        @brief Permet de donner une valeur au vecteur des etiquettes des neurones de la couche
        @param eParam : vecteur 
    */
   //inutile
    
    void setEtiquette(Matrix et);
    
    /**
        @brief Fonction qui permet de remplir le vecteur des sorties
    
    */
    void Sortie();   
    

    

    
    //! Matrice contenant les delta de chaque poids 
   
    
    
    
    //! Vecteur des sorties (inutile)

    Matrix sortie;

    

    
    
    //! Constructeurs
    
    /**
    @brief Constructeur de la classe, la couche n'a aucun neurone
       
    */
    
    Layer();//inutile   
    Layer(int sizein , int sizeout, activation_function f = TrainingFunction::reLu , activation_function d = TrainingFunction::relu_derivative);
    void activation(Layer & layerprecedant );
    void setDeltas(const Matrix & delta);
    Matrix getI() const;
    
    
   

    /**
        @brief Constructeur de la classe, la couche a Nbe neurones
        @param NbeParam : le nombre de neurones de la couche
        @param NbsParam : le nombre de neurones de la couche suivante
        @param nareteParam : on initialise avec une matrice de poids arete
        @param nbiaisParam : on initialise avec une matrice de  biais nbiais (on sait que w_0=-biais pour un neurone)
        @param netiqParam : on initialise avec une matrice d'etiquette netiq
        @param ndeltaParam : on initialise avec une matrice de biais nbiais

    */
    Layer(int ne, int ns, Matrix entree, Matrix narete, Matrix nbiais, Matrix netiq, Matrix ndelta);
    
    




   
    /**
        @brief Fonction qui Permet de calculer la matrice des deltas pour la mise a jour des poids
        @param LParam : Couche qui suit la couche actuelle
    
    */
    void calculerDelta(Layer& L);
    
    //! Affiche les poids de la matrice de poids
    /**
        @brief Permets d'afficher la matrice des poids
    
    */

    void displayWeight();


     /**
        @brief Permet de donner une valeur au vecteur des entrees de la couche
        @param eParam : vecteur 
   
    */
    void setEntree(Matrix& e);


    /**
    @brief Fonction qui permet d'appliquer la fonction d'activation aux éléments d'un vecteur
    @param colParam : le vecteur auquel on veut appliquer la fonction d'activation
    
    */
    void activation(Matrix col);
    


    /**
        @brief Getters
    
    */

    /**
         @brief Retourne le vecteur des entrees
    
    */  
    Matrix getEntree();
    
    /**
        @brief Retourne la matrice des poids
    
    */

    
    Matrix  getSortie();
    
    /**
        @brief Retourne la matrice des delta
    
    */

    Matrix getDelta() ;
    

    /**
         @brief Retourne le vecteur des etiquettes
    
    */

    Matrix  getBiais();
    
    
    /**
        @brief Retourne le vecteur des delta_j
    
    */

    Matrix getD();    
    
   
    //! Destructeur
    ~Layer();
};

#endif
