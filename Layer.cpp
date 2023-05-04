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



//Definir la liste des neurones d'entréee
void NetLayer::setInput(Matrix<double> inputList) {
	this->inputs = inputList;
}
// Set your own weights, used for back propogation and adjusting weights


// Getters
Matrix<double> NetLayer::getInputs() {
	return this->inputs;
}
Matrix<double> NetLayer::getWeights() {
	return this->weights;
}
Matrix<double> NetLayer::getOutput() {
	return this->outputs;
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

 void Layer::setWeights(Matrix<double> s) {
	this.arete = s;
    }

void Layer::setEntree(Matrix<double> e) {
	this.arete = s;
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
