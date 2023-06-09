#ifndef __TRAININGFUNCTION_HPP__
#define __TRAININGFUNCTION_HPP__

#include <vector>
#include "Matrix.hpp"

class TrainingFunction
{
private:
public:
    /// @brief Constructeur
    TrainingFunction();

    /// @brief Fonction d activation sigmoid
    /// @param x
    static double sigmoid(double x);

    /// @brief Fonction d activation reLu
    /// @param x 
    static double reLu(double x);

    /// @brief Le cadre d utilisation de softmax est celui du probleme de classification multi-classe.
    /// @param x : vecteur de nombres reels
    static Matrix softmax(const Matrix &x);

    /// @brief Derivee de la fonction sigmoid
    /// @param x 
    static double sigmoid_derivative(double x);

    /// @brief Derivee de la fonction reLu
    /// @param x 
    static double relu_derivative(double x);    
    
    /// @brief La derivee de la fonction softmax est une matrice jacobienne, qui peut etre calculee a partir des derivees partielles de la fonction softmax.
    /// @param y : vecteur de nombres reels, qui doit etre la sortie de la fonction softmax appliquee a un vecteur d entree. 
    //static Matrix& softmax_derivative(const Matrix & y);

    /// @brief Destructeur
    ~TrainingFunction();
};

#endif
