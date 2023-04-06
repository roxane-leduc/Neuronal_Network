#ifndef __DATASOURCE_HPP__
#define __DATASOURCE_HPP__

#include <string>
#include <vector>
using std::string;
using std::vector;

class DataSource
{
private:
    //! Pourcentage de donnees que le reseau utilisera pour l apprentissage
    double ap;
    //! Pourcentage de donnees que le reseau utilisera pour le test
    double test;
    //! Permet de savoir quelle base a ete choisie
    string dataBase;
    //! Garder en memoire les donnees necessaires pour l apprentissage
    vector<vector<int>> trainXSet;
    //! Sorties du reseau pour l apprentissage
    vector<int> trainYSet;
    //! Garder en memoire les donnees necessaires pour le test
    vector<vector<int>> testXSet;
    //! Sorties du reseau pour le test
    vector<int> testYSet;

public:
    //! Constructeur 
    DataSource();
    //! Convertis les donnees dans un format approprie pour l etude
    void convert(string dataBase, vector<int> dataArray);
    //! Destructeur
    ~DataSource();
};

#endif