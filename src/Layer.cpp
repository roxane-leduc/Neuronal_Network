#include "Layer.hpp"
#include <random>
#include <iostream>

//! TACHES: Telecharger et configurer visual studio

//! Constructeurs de layer 
//
Layer::Layer()
{
	this->Nbe = 0;
	this->Nbs = 0;
}

Layer::Layer(int ne, int ns,activation_function f,activation_function d):arete(ne,ns),delta(),entree(),I()
{
	arete.creerGaussien(0,0.5);

  	Fonction = f;
  	deriveFonction = d;



}
Layer::~Layer()
{

}


Layer::Layer(int ne, int ns, Matrix nentree, Matrix narete, Matrix nbiais, Matrix netiq, Matrix ndelta)
{

	Nbe = ne;
	Nbs = ns;
	arete = narete;
	biais = nbiais;
	etiq = netiq;
	delta = ndelta;
	entree = nentree;
}

//! Fonctions

void Layer::Sortie()
{
	//! Matrice des poids ce sont les precedentes (de la couche avant)

	//! produit matrice vecteur avec W : matrice des poids , I vecteur des entrees, X, vecteur des sorties X = W * E

	sortie = arete * entree;

	//! Cette sortie ne prend pas en compte les w_0 du coup on va les rajouter:

	//for (int i = 0; i < sortie.getnbRows(); i++)
	//	sortie.weight[i][0] = sortie.weight[i][0] + biais.weight[i][0];

	//! sauvegarde la valeur du produit matriciel sortie*entree avant transformation avec la fonction d'activation

	I = sortie;

	//! Applique la fonction d'activation a toutes les sorties

	//return sortie;
}



void Layer::activation(Layer& dernier)
{
	
	dernier.Sortie();
	dernier.delta = I;
	entree = dernier.I.apply_function(dernier.Fonction);
	entree.ajouterLigneUn();


}
Matrix Layer::getI()const
{
	return I;
}

Matrix Layer::getEntree()
{
	return entree;
}

Matrix& Layer::getArete() {
	return arete;
}

void Layer::setDeltas(const Matrix& de){
	delta = de;
}

Matrix Layer::getSortie()
{
	return sortie;
}

Matrix Layer::getDelta()
{
	return delta;
}

Matrix Layer::getBiais()
{
	return biais;
}

Matrix Layer::getD()
{
	return delta;
}

void Layer::setEntree(Matrix& e)
{
	entree = e;
	
}

void Layer::setEtiquette(Matrix et)
{
	etiq = et;
}

void Layer::setArete(Matrix& w) {
	arete = w;
}

void Layer::calculerDelta(Layer& L)
{
	double Ij;
	double dj;
	double s;
	double n = 1;

	for (int j = 0; j < L.delta.nbColumns; j++)
	{
		for (int i = 0; i < arete.nbColumns; i++)
		{
			delta.weight[i][j] =0;
			for(int k =0 ; k< arete.nbRows;k++)
				delta.weight[i][j] += L.delta.weight[k][j] * arete.weight[k][i]; 
			delta.weight[i][j] = delta.weight[i][j]*(*deriveFonction)(I.weight[i][j]);
		}


	}
}

void Layer::displayWeight()
{
	std::cout << "Affichage de la matrice des poids" << std::endl;
	for (int i = 0; i < arete.nbRows; i++)
	{
		std::cout << "Neurone_entree " << i + 1 << std::endl;
		for (int j = 0; j < arete.nbColumns; i++)
		{
			if (j == 0)
				std::cout << "w_0= " << arete.weight[i][0] << std::endl;
			else
				std::cout << "w_" << j << "= " << arete.weight[i][j] << std::endl;
		}
	}
}


