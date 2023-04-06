#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <vector>
using std::vector;

class Matrix
{
private:
    int nbColumns;
    int nbRows;
    vector<vector<double>> weight;

public:
    //! Constructeur (le parametre fait reference a la methode d initialisation de la matrice)
    Matrix(int choixInitialisation);
    void affichage();
    Matrix creerGaussien(int taille);
    Matrix creerUniforme(int taille);
    //! Operations elementaires
    Matrix addition(Matrix A, Matrix B);
    Matrix multiplication(Matrix A, Matrix B);
    Matrix transposition(Matrix A);
    Matrix cstMultMat(double c, Matrix A);
    Matrix vecteurMultVecteurT(Vecteur A, Vecteur B);
    double vecteurDot(Vecteur A, Vecteur B);
    int elementGrand(Veteur proba);
    Matrix ajouterLigne(Matrix A);
    Matrix ajouterColonne(Matrix A);
    //! Destructeur
    ~Matrix();
};

#endif
