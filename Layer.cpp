#include "Layer.hpp"
#include <random>
#include <iostream>

//TACHES: mis à jour des poids
	// Commentaires
	//Calcul de la matrice des Deltas

//! Constructeurs de layer 

/**
    @brief Constructeur de la classe, la couche n'a aucun neurone
   
  */

Layer::Layer()
{
      this.Nbe=0;
      this.Nbs=0; 
}


/**
    @brief Constructeur de la classe, la couche a Nbe neurones
    @param NbeParam : le nombre de neurones de la couche
    @param NbsParam : le nombre de neurones de la couche suivante
    */
Layer::Layer(int Nbe, int Nbs)
{
      this.Nbe=Nbe;
      this.Nbs=Nbs;
}


//! Fonctions

/**
    @brief Fonction qui permet de remplir le vecteur des sorties
       //! produit matrice vecteur avec W : matrice des poids , I vecteur des entrees, X, vecteur des sortiesX = W * I
      
    
    */

Matrix<double>Layer::sortie() {
 
    this.sortie.weight = this.arete.weight * this.entree.weight;
	
     //! Applique la fonction d'activation a toutes les sorties
	
    activation(this.sortie.weight);
    
    return this.sortie.weight;
}


//! Applique la fonction d'activation a toutes les neurones en sorties
/**
    @brief Fonction qui permet d'appliquer la fonction d'activation aux éléments d'un vecteur
    @param colParam : le vecteur auquel on veut appliquer la fonction d'activation
    
    */

void Layer::activation(Matrix<double> col) {
	for (size_t i = 0; i < col.size(); i++) {
        this.sortie.weight[i][0] = fonctionActivation(col.weight[i][0]);
	}
}



/**
    @brief Getters
    
    */

Matrix<double> Layer::getEntree() {
	return this.entree.weight;
}
Matrix<double> Layer::getPoids() {
	return this.arete.weight;
}
Matrix<double> Layer::getSortie() {
	return this.sortie.weight;
}

Matrix<double> Layer::getDelta() {
	return this.delta.weight;
}

Matrix<double> Layer::getEtiq() {
	return this.etiq.weight;
}

Matrix<double> Layer::getD() {
	return this.d.weight;
}


/**
    @brief Setter
   
    */

 void Layer::setEntree(Matrix<double> e) {
	this.entree = e;
    }

/**
    @brief Constructeur de la classe, tous les poids de la matrice sont nuls
    @param nbRowsParam : le nombre de ligne de la matrice
    @param nbColumnsParam : le nombre de colonne de la matrice
    */
 void Layer::setEtiquette(Matrix<double> et) {
	this.etiq = et;
    }

/**
    @brief Constructeur de la classe, tous les poids de la matrice sont nuls
    @param nbRowsParam : le nombre de ligne de la matrice
    @param nbColumnsParam : le nombre de colonne de la matrice
    */

void Layer::setPoids(Matrix<double> w) {
	this.arete = w;
    }


//! Permet de calculer la matrice des deltas pour la mise a jour des poids
//! Elle prend
/**
    @brief Constructeur de la classe, tous les poids de la matrice sont nuls
    @param nbRowsParam : le nombre de ligne de la matrice
    @param nbColumnsParam : le nombre de colonne de la matrice
    */

void Layer::calculerDelta(Layer L, Matrix d_pred, Matrix biais)
{
	double Ij;
	double dj;
	double s;
	double n=1;
	
	for (int i=0;i<this.arete.nbRows;i++)
	{
		for(int j=1;j<this.arete.nbColumns;j++)
		{
			//Calcul de la somme pondérées des poids pour le neurone de sortis j
			Ij=L.arete.weight[j][0];
			s=0;
			for(int k=0;k<this.arete.nbRows;k++)
			{
				Ij=Ij+this.arete.weight[k][j];
				s=s+d_pred.weight[k][0]*this.arete.weight[k][j];
			}
			dj=dfonctionActivation(Ij)*s;
			this.d[j]=dj;
			if (j-1==0)
				delta.weight[i][j-1]=n*dj*biais.weight[j-1];
			else
				delta.weight[i][j-1]=n*dj*sortie.weight[j-1];
			
		}
	
	
	}
}

//! Affiche les poids de la matrice de poids
/**
    @brief Constructeur de la classe, tous les poids de la matrice sont nuls
    @param nbRowsParam : le nombre de ligne de la matrice
    @param nbColumnsParam : le nombre de colonne de la matrice
    */

void Layer::displayWeight()
{
	std::cout<<"Affichage de la matrice des poids"<<std::endl;
	for (int i=0;i<this.arete.nbRows;i++)
	{
		std::cout<<"Neurone_entree "<<i+1<<std::endl;
		for (int j=0;j<this.arete.nbColumns;i++)
		{	
			if(j==0)
				std::cout<<"w_0= "<<this.arete.weight[i][0]<<std::endl;
			else
				std::cout<<"w_"<<j<<"= "<<this.arete.weight[i][j]<<std::endl;
		}
		
	}
}


//! Definition de la fonction d'activation
/**
    @brief Constructeur de la classe, tous les poids de la matrice sont nuls
    @param nbRowsParam : le nombre de ligne de la matrice
    @param nbColumnsParam : le nombre de colonne de la matrice
    */

double Layer::fonctionActivation(double x) {
  
  //Fonction sigmoide standard 
    return 1 / (1 + std::exp(-x));
}

/**
    @brief Constructeur de la classe, tous les poids de la matrice sont nuls
    @param nbRowsParam : le nombre de ligne de la matrice
    @param nbColumnsParam : le nombre de colonne de la matrice
    */

double Layer::dfonctionActivation(double x) {
  
  //Derivee de la fonction d'activation
	
    return 1 / (1 + std::exp(-x));
}

Layer::~Layer()
{
}
