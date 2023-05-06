#include "Layer.hpp"
#include <random>
#include <iostream>

//TACHES: mis à jour des poids
	// Commentaires
	//Calcul de la matrice des Deltas


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


// Setter

 void Layer::setEntree(Matrix<double> e) {
	this.entree = e;
    }

 void Layer::setEtiquette(Matrix<double> et) {
	this.etiq = et;
    }

void Layer::setPoids(Matrix<double> w) {
	this.arete = w;
    }


Layer::Layer(int Nbe, int Nbs)
{
      this.Nbe=Nbe;
      this.Nbs=Nbs;
}

// Permet de calculer la matrice des deltas pour la mise a jour des poids
// Elle prend 

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

// Affiche les poids de la matrice de poids

void Layer::displayWeight(Layer L)
{
	std::cout<<"Affichage de la matrice des poids"<<std::endl;
	for (int i=0;i<L.arete.nbRows;i++)
	{
		std::cout<<"Neurone_entree "<<i+1<<std::endl;
		for (int j=0;j<L.arete.nbColumns;i++)
		{	
			if(j==0)
				std::cout<<"w_0= "<<L.arete[i][0]<<std::endl;
			else
				std::cout<<"w_"<<j<<"= "<<L.arete[i][j]<<std::endl;
		}
		
	}
}


//Definition de la fonction d'activation

double Layer::fonctionActivation(double x) {
  
  //Fonction sigmoide standard 
    return 1 / (1 + std::exp(-x));
}


double Layer::dfonctionActivation(double x) {
  
  //Derivee de la fonction d'activation
	
    return 1 / (1 + std::exp(-x));
}

Layer::~Layer()
{
}
