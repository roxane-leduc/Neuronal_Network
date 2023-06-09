#ifndef __OUTPUTLAYER_HPP__
#define __OUTPUTLAYER_HPP__

#include "Layer.hpp"
#include "TrainingFunction.hpp"

#include <vector>
using std::vector;

typedef Matrix (*gen)(const Matrix&);

class OutputLayer : public Layer
{
private:
    //! Sortie du reseau
    Matrix  result;
    Matrix Proba;
    gen GenM;//généralisation méthode , softmax pour plus de cas.
    
public:
    //! Constructeur
    OutputLayer();
    OutputLayer(int sizeIn,int sizeOut, gen f= TrainingFunction::softmax);
    //! Creer la couche de sortie
    //void creer_derniere_couche(int tailleInput, int tailleOutput, TrainingFunction f);
    //! Prend en parametre une fonction correspondant a la fontion de perte du reseau, ici, l entropie croise
    void fonction_de_perte();
    //! Enregistre le resultat dans l attribut Proba
    void obtenir_resultat();
    void sortie();


    Matrix& getProba();
    Matrix getResult();
    //! Destructeur
    ~OutputLayer();

};

#endif