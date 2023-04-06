#ifndef __TRAININGFUNCTION_HPP__
#define __TRAININGFUNCTION_HPP__

class TrainingFunction
{
private:
public:
    //! Constructeur (comporte les principales fonctions d activation ainsi que leurs derivees)
    TrainingFunction(/* args */);
    float sigmoide();
    float reLu();
    //! La couche de sortie aura une seule 
    //! fonction d apprentissage possible qui 
    //! sera la fonction softMax et qui correspondra 
    //! aussi a la fonction de perte
    float softMax();
    float deriveeSigmoide();
    float deriveeRelu();
    float deriveeSoftmax();
    //! Destructeur
    ~TrainingFunction();
};

#endif
