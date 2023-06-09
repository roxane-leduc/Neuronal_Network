#ifndef NETWORK_H
#define NETWORK_H
#include "Matrix.hpp"
#include "Layer.hpp"
#include "OutputLayer.hpp"
#include <vector>

using namespace std;

class Network{

    public:
            Network(const int intputDim, vector<int> & hidDim, const int outputDim);
            //Network(int intputDim, vector<int> hidDim, int outputDim,vector<char*> fonctions_activations);
            void setCouche(Layer& L);
            void dispaly_result();
            double calcul_fiabilite(Matrix& TestYset);
            void train(Matrix& TrainXset,Matrix& TrainYset, double leaningRate,int batchsize,int epochs);
            double test(Matrix& TestXset,Matrix& TestYset,int batchsize);
            ~Network();

    private: 
            vector<Layer> couches;
            OutputLayer fcouche;
            void forward_propagation(Matrix & TrainXset);
            void backward_propagation(Matrix &  TrainYset);
            void update_weight(double learningRate);
            double cross_entropy(Matrix& TrainYset);


};
#endif
