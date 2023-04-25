#ifndef __TRAININGFUNCTION_HPP__
#define __TRAININGFUNCTION_HPP__

#include <vector>

class TrainingFunction
{
private:
public:
    /// @brief Constructeur
    TrainingFunction();

    /// @brief Fonction d activation sigmoid
    /// @param x
    double sigmoid(double x);

    /// @brief Fonction d activation reLu
    /// @param x 
    double reLu(double x);

    /// @brief Le cadre d utilisation de softmax est celui du probleme de classification multi-classe.
    /// @param x : vecteur de nombres reels
    std::vector<double> softmax(const std::vector<double> &x);

    /// @brief Derivee de la fonction sigmoid
    /// @param x 
    double sigmoid_derivative(double x);

    /// @brief Derivee de la fonction reLu
    /// @param x 
    double relu_derivative(double x);    
    
    /// @brief La derivee de la fonction softmax est une matrice jacobienne, qui peut etre calculee a partir des derivees partielles de la fonction softmax.
    /// @param y : vecteur de nombres reels, qui doit etre la sortie de la fonction softmax appliquee a un vecteur d entree. 
    std::vector<double> softmax_derivative(const std::vector<double> &y);

    /// @brief Destructeur
    ~TrainingFunction();
};

#endif
