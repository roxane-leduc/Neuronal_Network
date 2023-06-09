#include "OutputLayer.hpp"

//Constructeur
OutputLayer::OutputLayer(int sizeIn, int sizeOut,gen f ):Layer(sizeIn,sizeOut),result(0,0),Proba(0,0)
{
    GenM = f;
}


void OutputLayer::fonction_de_perte()
{
}


void OutputLayer::sortie()
{
    Proba=GenM(I);
}

Matrix& OutputLayer::getProba()
{
    return Proba;
}
void OutputLayer::obtenir_resultat()
{
}

//destructeur
OutputLayer::~OutputLayer()
{
}
