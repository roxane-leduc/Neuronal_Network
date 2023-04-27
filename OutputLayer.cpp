#include "OutputLayer.hpp"

//Constructeur
OutputLayer::OutputLayer(int sizeIn, int sizeOut)
{
    tailleInput = sizeIn;
    tailleOutput = sizeOut;
    result = -1;
    Proba = vector<double>(sizeOut,0.0); //vecteur de taille "sizeOut" et qui ne contient que des 0
}

void OutputLayer::creer_derniere_couche(int tailleInput, int tailleOutput, TrainingFunction f)
{
}

void OutputLayer::fonction_de_perte()
{
}

void OutputLayer::enregistrer_vecteur_de_probabilite(Layer L)
{
}

void OutputLayer::obtenir_resultat()
{
}

//destructeur
OutputLayer::~OutputLayer()
{
}
