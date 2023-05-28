#ifndef __LAYER_HPP__
#define __LAYER_HPP__

#include "Matrix.hpp"
#include "Neurone.hpp"
#include "TrainingFunction.hpp"

#include <list>
using std::list;

class Layer
{
protected:
    
    //! Nombre de neurones que l'on a en entrée
    int Nbe;
    //! Nombre de neurones que l'on a en sortie
    int Nbs;   
    
    //! Vecteur des biais de la couche
    Matrix biais;
    
    //! Matrice contenant les poids des aretes reliant cette couche a la suivante
    Matrix arete;
    
    
    //! Vecteur des etiquettes
    Matrix etiq;
    
     //! Vecteur des delta_j
    Matrix delta;
    
    
    
    
    

   
    //! Setter
    
    /**
    @brief Permet de donner des valeurs aux élèments de la matrice des poids des neurones de la couche 
    @param eParam : matrice
    */
    void setPoids(Matrix s);
    
    /**
    
    @brief Permet de donner des valeurs aux élèments la matrice des poids des neurones de la couche
    
    */
        
    void PoidsAleatoires();
    
    
    
    
    /**
        @brief Permet de donner une valeur au vecteur des etiquettes des neurones de la couche
        @param eParam : vecteur 
    */
    
    void setEtiquette(Matrix et);
    
    
    

public:

    
    //! Matrice contenant les delta de chaque poids 
    Matrix delta;
    
    //! Vecteur des entrees
    Matrix entree;
    
    //! Vecteur des sorties
    Matrix sortie;

    //! Vecteur des sorties avant calcul avec la fonction d'activation
    Matrix I;

    //! Classe des fonctions d'activation
    TrainingFunction Fonction;
    
    //! Constructeurs
    
    /**
    @brief Constructeur de la classe, la couche n'a aucun neurone
       
    */

    Layer();

    Layer(int ne, int ns);
   

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
        @brief Fonction qui permet de remplir le vecteur des sorties
    
    */
     Matrix Layer::Sortie();

   
    /**
        @brief Fonction qui Permet de calculer la matrice des deltas pour la mise a jour des poids
        @param LParam : Couche qui suit la couche actuelle
    
    */
    void calculerDelta(Layer L);
    
    //! Affiche les poids de la matrice de poids
    /**
        @brief Permets d'afficher la matrice des poids
    
    */

    void displayWeight();


     /**
        @brief Permet de donner une valeur au vecteur des entrees de la couche
        @param eParam : vecteur 
   
    */
    void setEntree(Matrix e);


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

    Matrix getPoids();
    
    
    /**
        @brief Retourne le vecteur des sorties
    
    */
    
    Matrix  getSortie();
    
    /**
        @brief Retourne la matrice des delta
    
    */

    Matrix getDelta() ;
    

    /**
         @brief Retourne le vecteur des etiquettes
    
    */

    Matrix  getEtiq();
    
    
    /**
        @brief Retourne le vecteur des delta_j
    
    */

    Matrix getD();    
    
   
    //! Destructeur
    ~Layer();
};

#endif
