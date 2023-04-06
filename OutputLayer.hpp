#ifndef __OUTPUTLAYER_HPP__
#define __OUTPUTLAYER_HPP__

#include "Layer.hpp"
#include "TrainingFunction.hpp"

#include <vector>
using std::vector;

class OutputLayer : public Layer
{
private:
    //! Sortie du reseau
    int result;
    vector<double> Proba;
    int tailleInput;
    int tailleOutput;

public:
    //! Constructeur
    OutputLayer();
    //! Creer la couche de sortie
    void creer_derniere_couche(int tailleInput, int tailleOutput, TrainingFunction f);
    //! Prend en parametre une fonction correspondant a la fontion de perte du reseau, ici, l entropie croise
    void fonction_de_perte();
    //! Enregistre le resultat dans l attribut Proba
    void enregistrer_vecteur_de_probabilite(Layer L);
    void obtenir_resultat();
    //! Destructeur
    ~OutputLayer();
};

#endif