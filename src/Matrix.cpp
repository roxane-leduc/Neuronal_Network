#include <iostream>
#include <random>
#include "Matrix.hpp"

// Classe erreur pour la classe matrice


// Constructeur

Matrix::Matrix()
{
    nbRows = 0;
    nbColumns = 0;
    weight = NULL;
}

Matrix::Matrix(int nbRowsParam, int nbColumnsParam)
{
    // Mise à jour du nombre de colonnes et de lignes
    nbColumns = nbColumnsParam;
    nbRows = nbRowsParam;

    // Création dynamique du tableau 2D de double
    std::default_random_engine generator;
    weight = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        weight[i] = new double[nbColumns];
        for (int j = 0; j < nbColumns; j++)
        {
            weight[i][j] = 0;
        }
    }
}

Matrix::Matrix(double **weightParam, int nbRowsParam, int nbColumnsParam)
{
    nbColumns = nbColumnsParam;
    nbRows = nbRowsParam;
    weight = weightParam;
}

// Constructeur par copie
Matrix::Matrix(const Matrix &other)
{
    nbRows = other.nbRows;
    nbColumns = other.nbColumns;
    weight = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        weight[i] = new double[nbColumns];
        for (int j = 0; j < nbColumns; j++)
        {
            weight[i][j] = other.weight[i][j];
        }
    }
}

// Set & Get

double **Matrix::getPoids()
{
    return weight;
}


double Matrix::getPoidsIndex(int i, int j)
{
    if (i >= 0 && i < nbRows && j >= 0 && j < nbColumns)
    {
        return weight[i][j];
    }
    else
        exit(1);
}


int Matrix::getnbRows()const
{
    return nbRows;
}

int Matrix::getnbColumns()const
{
    return nbColumns;
}

void Matrix::setPoids(int i, int j, double poids)
{
    weight[i][j] = poids;
}

void Matrix::setnbRows(int R)
{
    nbRows = R;
}

void Matrix::setnbColumns(int C)
{
    nbColumns = C;
}

// Affichage

void Matrix::affichage()
{
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            std::cout << weight[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Destructeur

Matrix::~Matrix()
{
    if (weight != NULL)
    {
        for (int i = 0; i < nbRows; i++)
        {
            delete[] weight[i];
        }
        delete[] weight;
        weight = NULL;
    }
}

// Surcharge opérateur
// Opérateur =
Matrix &Matrix::operator=(const Matrix &A)
{
    if (this != &A)
    {
        for (int i = 0; i < nbRows; i++)
        {
            delete[] weight[i];
        }
        delete[] weight;

        nbRows = A.nbRows;
        nbColumns = A.nbColumns;
        weight = new double *[nbRows];
        for (int i = 0; i < nbRows; i++)
        {
            weight[i] = new double[nbColumns];
            for (int j = 0; j < nbColumns; j++)
            {
                weight[i][j] = A.weight[i][j];
            }
        }
    }
    return *this;
}

// Opérateur +

Matrix Matrix::operator+(const Matrix &A)
{
    // Si un problème au niveau de la taille des matrices alors on renvoie un message d'erreur
    try
    {
        if (A.nbColumns != nbColumns || A.nbRows != nbRows)
        {
            erreurMatrice E(1);
            throw(E);
        }
    }
    catch (erreurMatrice &tmp)
    {
        std::cout << "Problème dans la taille des matrices pour l'addition" << std::endl;
        exit(1);
    }
    // Sinon on peut effectuer l'addition entre les deux matrices
    Matrix sum = Matrix(nbRows, nbColumns);

    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            sum.setPoids(i, j, weight[i][j] + A.weight[i][j]);
        }
    }
    return sum;
}

// Opérateur -

Matrix Matrix::operator-(const Matrix &A)
{
    // Si un problème au niveau de la taille des matrices alors on renvoie un message d'erreur
    try
    {
        if (A.nbColumns != nbColumns || A.nbRows != nbRows)
        {
            erreurMatrice E(1);
            throw(E);
        }
    }
    catch (erreurMatrice &tmp)
    {
        std::cout << "Problème dans la taille des matrices pour l'addition" << std::endl;
        exit(1);
    }
    // Sinon on peut effectuer l'addition entre les deux matrices
    Matrix sub = Matrix(nbRows, nbColumns);

    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            sub.setPoids(i, j, weight[i][j] - A.weight[i][j]);
        }
    }
    return sub;
}

// Opérateur *
// Matrice * matrice
Matrix Matrix::operator*(const Matrix &A)
{
    // Si un problème au niveau de la taille des matrices alors on renvoie un message d'erreur
    try
    {
        if (nbColumns != A.nbRows)
        {
            erreurMatrice E(2);
            throw E;
        }
    }
    catch (erreurMatrice &tmp)
    {
        std::cout << "Problème dans la taille des matrices pour la multiplication" << std::endl;
        exit(1);
    }

    // Sinon on peut effectuer la multiplication entre les deux matrices
    Matrix product = Matrix(nbRows, A.nbColumns);
    double prodtmp = (double)0;
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < A.nbColumns; j++)
        {
            for (int k = 0; k < nbColumns; k++)
            {
                prodtmp += weight[i][k] * A.weight[k][j];
            }
            product.setPoids(i, j, prodtmp);
            prodtmp = 0;
        }
    }
    return product;
}

// Lois pour les poids
// Loi normale :
void Matrix::creerGaussien(double mu, double stddev)
{
    // Création du générateur de random
    std::default_random_engine generator;
    generator.seed(time(0));

    // Paramétrisation de la loi normale
    std::normal_distribution<double> distribution(mu, stddev);

    // Mise à jour des valeurs des poids
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            weight[i][j] = distribution(generator);
        }
    }
}

// Loi uniforme :
void Matrix::creerUniforme(double a, double b)
{
    // Création du générateur de random
    std::default_random_engine generator;
    generator.seed(time(0));

    // Paramétrisation de la loi uniforme
    std::uniform_real_distribution<double> distribution(a, b);

    // Mise à jour des valeurs des poids
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            weight[i][j] = distribution(generator);
        }
    }
}

// Operations elementaires

// Transposition de matrice :

Matrix Matrix::transposition()
{
    // Création de la nouvelle matrice
    Matrix transpose = Matrix(nbColumns, nbRows);

    // Modification des poids de la nouvelle matrice
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            transpose.setPoids(j, i, weight[i][j]);
        }
    }
    return transpose;
}

// Constante fois une matrice :

Matrix Matrix::cstMultMat(const double &c)
{
    // Création de la nouvelle matrice
    Matrix res = Matrix(nbColumns, nbRows);

    // Modification des poids de la nouvelle matrice
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            res.setPoids(i, j, weight[i][j] * c);
        }
    }
    return res;
}

// Produit de vecteur pour avoir une matrice :
// this : vecteur colonne et A : vecteur ligne
Matrix Matrix::vecteurMultVecteurT(const Matrix &A)
{
    // Si un problème au niveau de la taille des matrices alors on renvoie un message d'erreur : this pas un vecteur colonne
    //                                                                                           A pas un vecteur ligne
    try
    {
        if (nbColumns != 1 || A.nbRows != 1 || nbRows != A.nbColumns)
        {
            erreurMatrice E(1);
            throw(E);
        }
    }
    catch (erreurMatrice &tmp)
    {
        std::cout << "Problème dans la taille des matrices (vecteurs) pour le produit donnant une matrice" << std::endl;
        exit(1);
    }
    // Sinon on peut effectuer le produit
    Matrix res = Matrix(nbRows, A.nbColumns);
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < A.nbColumns; j++)
        {
            res.setPoids(i, j, weight[i][0] * A.weight[0][j]);
        }
    }
    return res;
}

// Produit de vecteur pour avoir un réel :
// this : vecteur ligne et A : vecteur colonne
double Matrix::vecteurDot(const Matrix &A)
{
    // Si un problème au niveau de la taille des matrices alors on renvoie un message d'erreur : this pas un vecteur ligne
    //                                                                                           A pas un vecteur colonne
    try
    {
        if (nbRows != 1 || A.nbColumns != 1 || nbColumns != A.nbRows)
        {
            erreurMatrice E(1);
            throw(E);
        }
    }
    catch (erreurMatrice &tmp)
    {
        std::cout << "Problème dans la taille des matrices (vecteurs) pour le produit scalaire" << std::endl;
        exit(1);
    }
    // Sinon on peut effectuer le produit
    double res;
    for (int i = 0; i < nbColumns; i++)
    {
        res += weight[0][i] * A.weight[i][0];
    }
    return res;
}

// Produit matriciel d'Hadamard :
// this : matrice et A : matrice
Matrix Matrix::multiplicationHadamard(const Matrix &A)
{

    // Si elles n'ont pas la même taille
    try
    {
        if (nbColumns != A.nbColumns || A.nbRows != nbRows)
        {
            erreurMatrice E(1);
            throw(E);
        }
    }
    catch (erreurMatrice &tmp)
    {
        std::cout << "Problème dans la taille des matrices (vecteurs) pour le produit donnant une matrice" << std::endl;
        exit(1);
    }

    // Sinon on peut faire le calcul du produit matricielle d'Hadamard
    Matrix res = Matrix(nbRows, nbColumns);
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            res.setPoids(i, j, weight[i][j] * A.weight[i][j]);
        }
    }

    return res;
}

// Plus grand élément d'un vecteur :
// this : vecteur colonne
int Matrix::elementGrand()
{
    // Si la matrice this n'est pas un vecteur colonne
    try
    {
        if (nbColumns != 1)
        {
            erreurMatrice E(1);
            throw(E);
        }
    }
    catch (erreurMatrice &tmp)
    {
        std::cout << "Problème dans la taille du vecteur : pas un vecteur colonne" << std::endl;
        exit(1);
    }
    // Sinon on cherche le plus petit élément et son indice
    int res = 0;
    for (int i = 1; i < nbRows; i++)
    {
        if (weight[i][0] < weight[res][0])
            res = i;
    }
    return res;
}

// Renvoyer la matrice ne contenant que certaines colonnes de la matrice :

Matrix Matrix::troncature(int debut, int fin)
{
    // Si un problème au niveau des indices des colonnes que l'on veut récupérer
    try
    {
        if (debut < 0 || fin > (nbRows - 1) || debut > fin)
        {
            erreurMatrice E(1);
            throw(E);
        }
    }
    catch (erreurMatrice &tmp)
    {
        std::cout << "Problème dans les indices début et fin" << std::endl;
        exit(1);
    }

    // Sinon on peut effectuer la troncature sur les colonnes
    Matrix res = Matrix(nbRows, fin - debut + 1);
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < res.getnbColumns(); j++)
        {
            res.setPoids(i, j, weight[i][j + debut]);
        }
    }

    return res;
}

// Ajouter une ligne à la matrice :

void Matrix::ajouterLigneUn()
{
    int nbRowsTmp = nbRows;
    // On crée un tableau temporaire pour stocker les valeurs des poids
    double **tmp = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        tmp[i] = new double[nbColumns];
    }
    // On transfère la valeur des poids dans le tableau temporaire
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            tmp[i][j] = weight[i][j];
        }
    }
    // On libère la mémoire du tableau des poids de la matrice
    for (int i = 0; i < nbRows; i++)
    {
        delete[] this->weight[i];
    }
    delete[] weight;
    // On augmente le nombre de ligne car on en ajoute une
    nbRows++;
    // On alloue de la mémoire pour le nouveau tableau de poids et on le remplit
    weight = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        weight[i] = new double[nbColumns];
        for (int j = 0; j < nbColumns; j++)
        {
            // Si on est à la dernière ligne du tableau alors on met des 0
            if (i == nbRowsTmp)
                weight[i][j] = 1;
            // Sinon on prend les poids du tableau temporaire
            else
                weight[i][j] = tmp[i][j];
        }
    }
    // On libère la mémoire du tableau temporaire
    for (int i = 0; i < nbRows; i++)
    {
        delete[] tmp[i];
    }
    delete[] tmp;
}

void Matrix::ajouterLigne(const Matrix &Ligne)
{
    // Si la matrice que l'on veut ajouter en bas de la matrice Ligne n'est pas un vecteur ligne
    try
    {
        if (Ligne.nbRows != 1)
        {
            erreurMatrice E(1);
            throw(E);
        }
    }
    catch (erreurMatrice &tmp)
    {
        std::cout << "Problème dans la taille du vecteur Ligne : pas un vecteur ligne" << std::endl;
        exit(1);
    }
    // Sinon on peut l'ajouter
    int nbRowsTmp = nbRows;
    // On crée un tableau temporaire pour stocker les valeurs des poids
    double **tmp = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        tmp[i] = new double[nbColumns];
    }
    // On transfère la valeur des poids dans le tableau temporaire
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            tmp[i][j] = weight[i][j];
        }
    }
    // On libère la mémoire du tableau des poids de la matrice
    for (int i = 0; i < nbRows; i++)
    {
        delete[] this->weight[i];
    }
    delete[] weight;
    // On augmente le nombre de ligne car on en ajoute une
    nbRows++;
    // On alloue de la mémoire pour le nouveau tableau de poids et on le remplit
    weight = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        weight[i] = new double[nbColumns];
        for (int j = 0; j < nbColumns; j++)
        {
            // Si on est à la dernière ligne du tableau il faut prendre les valeurs du vecteur ligne
            if (i == nbRowsTmp)
                weight[i][j] = Ligne.weight[0][j];
            // Sinon on prend les poids du tableau temporaire
            else
                weight[i][j] = tmp[i][j];
        }
    }
    // On libère la mémoire du tableau temporaire
    for (int i = 0; i < nbRows; i++)
    {
        delete[] tmp[i];
    }
    delete[] tmp;
}

// Ajouter une colonne à la matrice :

void Matrix::ajouterColonneVide()
{
    int nbColumnTmp = nbColumns;
    // On crée un tableau temporaire pour stocker les valeurs des poids
    double **tmp = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        tmp[i] = new double[nbColumns];
    }
    // On transfère la valeur des poids dans le tableau temporaire
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            tmp[i][j] = weight[i][j];
        }
    }
    // On libère la mémoire du tableau des poids de la matrice
    for (int i = 0; i < nbRows; i++)
    {
        delete[] this->weight[i];
    }
    delete[] weight;
    // On augmente le nombre de colonne car on en ajoute une
    nbColumns++;
    // On alloue de la mémoire pour le nouveau tableau de poids et on le remplit
    weight = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        weight[i] = new double[nbColumns];
        for (int j = 0; j < nbColumns; j++)
        {
            // Si on est à la dernière ligne du tableau alors on met des 0
            if (j == nbColumnTmp)
                weight[i][j] = 0;
            // Sinon on prend les poids du tableau temporaire
            else
                weight[i][j] = tmp[i][j];
        }
    }
    // On libère la mémoire du tableau temporaire
    for (int i = 0; i < nbRows; i++)
    {
        delete[] tmp[i];
    }
    delete[] tmp;
}

void Matrix::ajouterColonne(Matrix Colonne)
{
    try
    {
        if (Colonne.nbColumns != 1)
        {
            erreurMatrice E(1);
            throw(E);
        }
    }
    catch (erreurMatrice &tmp)
    {
        std::cout << "Problème dans la taille du vecteur Colonne : pas un vecteur colonne" << std::endl;
        exit(1);
    }

    int nbColumnTmp = nbColumns;
    // On crée un tableau temporaire pour stocker les valeurs des poids
    double **tmp = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        tmp[i] = new double[nbColumns];
    }
    // On transfère la valeur des poids dans le tableau temporaire
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            tmp[i][j] = weight[i][j];
        }
    }
    // On libère la mémoire du tableau des poids de la matrice
    for (int i = 0; i < nbRows; i++)
    {
        delete[] this->weight[i];
    }
    delete[] weight;
    // On augmente le nombre de ligne car on en ajoute une
    nbColumns++;
    // On alloue de la mémoire pour le nouveau tableau de poids et on le remplit
    weight = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        weight[i] = new double[nbColumns];
        for (int j = 0; j < nbColumns; j++)
        {
            // Si on est à la dernière ligne du tableau il faut prendre les valeurs du vecteur colonne
            if (j == nbColumnTmp)
                weight[i][j] = Colonne.weight[i][0];
            // Sinon on prend les poids du tableau temporaire
            else
                weight[i][j] = tmp[i][j];
        }
    }
    // On libère la mémoire du tableau temporaire
    for (int i = 0; i < nbRows; i++)
    {
        delete[] tmp[i];
    }
    delete[] tmp;
}

// Calculer la somme des éléments d'une matrice :

double Matrix::element_sum()
{
    double res = 0;
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            // std::cout << res << std::endl;
            res = res + weight[i][j];
        }
    }
    return res;
}

// Appliquer une fonction sur chaque élément de la matrice :

Matrix Matrix::apply_function(double (*function)(double))
{
    Matrix temps= *this ;
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumns; j++)
        {
            temps.setPoids(i,j,(*function)(weight[i][j]));
        }
    }
    return temps;
}

void Matrix::emplace_back(Matrix& f){
    

    try
    {
        if (nbRows != f.nbRows)
        {
            erreurMatrice E(4);
            throw(E);
        }
    }
    catch (erreurMatrice &tmp)
    {
        std::cout << "Problème dans la taille du vecteur Ligne : ne peut pas concatener" << std::endl;
        exit(1);
    }

    int nbColumnTmp = nbColumns+f.nbColumns;
    // On crée un tableau temporaire pour stocker les valeurs des poids
    double **tmp = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        tmp[i] = new double[nbColumnTmp];
    }
    // On transfère la valeur des poids dans le tableau temporaire
    for (int i = 0; i < nbRows; i++)
    {
        for (int j = 0; j < nbColumnTmp; j++)
        {
            if (j<nbColumns)
                tmp[i][j] = weight[i][j];
            else 
                tmp[i][j] = f.weight[i][j-nbColumns];
        }
    }

    // On libère la mémoire du tableau des poids de la matrice
    for (int i = 0; i < nbRows; i++)
    {
        delete[] this->weight[i];
    }
    delete[] weight;
    nbColumns = nbColumnTmp;
    // On alloue de la mémoire pour le nouveau tableau de poids et on le remplit
    weight = new double *[nbRows];
    for (int i = 0; i < nbRows; i++)
    {
        weight[i] = new double[nbColumns];
        for (int j = 0; j < nbColumns; j++)
        {
                weight[i][j] = tmp[i][j];
        }
    }
    // On libère la mémoire du tableau temporaire
    for (int i = 0; i < nbRows; i++)
    {
        delete[] tmp[i];
    }
    

}



// Test pour la méthode pour appliquer une fonction sur chaque élément de la matrice
// On définit la fonction
double fois2(double i)
{
    return 2 * i;
}

int main(int argc, char *argv[], char *envp[])
{
    Matrix test1 = Matrix(2, 1);
    Matrix test2 = Matrix(1, 2);
    Matrix test3 = Matrix(2, 1);
    Matrix test4 = Matrix(3, 3);
    test1.creerGaussien(0, 1);
    test2.creerUniforme(0, 1);
    test3.creerUniforme(0, 1);
    test4.creerUniforme(1, 2);
    test1.affichage();
    std::cout << std::endl;
    test2.affichage();
    std::cout << std::endl;
    test3.affichage();
    std::cout << std::endl;
    test4.affichage();
    std::cout << std::endl;

    //Matrix test5 = test4.troncature(2, 1);
    //test5.affichage();

    double (*pf)(double);
    pf = &fois2;
    test4.affichage();
    test4.apply_function(pf);
    test4.affichage();
}
