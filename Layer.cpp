#include "Layer.hpp"
#include <random>
#include <iostream>


// 	Fonction qui calcule la matrice de sortie
Matrix<double>Layer::Sortie() {
    // X = W * I
    this.sortie = this.arete * this.entree;
	
    // Applique la fonction sigmoide a toutes les sorties
	
    activation(this.sortie);
    
    return this.sortie;
}


// Applique la fonction sigmoide a toutes les neurones en sorties

void Layer::activation(Matrix<double> col) {
	for (size_t i = 0; i < col.size(); i++) {
        this->sortie[i][0] = fonctionActivation(col[i][0]);
	}
}


// Getters
Matrix<double> Layer::getEntree() {
	return this.entree;
}
Matrix<double> Layer::getPoids() {
	return this.arete;
}
Matrix<double> Layer::getSortie() {
	return this.sortie;
}



    
}

/
// Constructeur de layer 
// Nbe nombre de neurones en entree
// Nbs nombre de neurones en sortie

Layer::Layer()
{
      this.Nbe=0;
      this.Nbs=0;
      this.arete=arete(0,0);    
}

// remplir la matrice de poids

 void Layer::setEntree(Matrix<double> e) {
	this.entree = e;
    }

void Layer::setPoids(Matrix<double> w) {
	this.arete = w;
    }


Layer::Layer(int Nbe, int Nbs)
{
      this.Nbe=Nbe;
      this.Nbs=Nbs;
}

void Layer::calculerDelta(Layer L)
{
}

void Layer::displayWeight(Matrix weight)
{
}


//Definition de la fonction d'activation

double Layer::fonctionActivation(double x) {
  
  //Fonction sigmoide standard 
    return 1 / (1 + std::exp(-x));
}

Layer::~Layer()
{
}
