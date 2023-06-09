#include "Network.hpp"
#include <vector>
#include <cmath>
using namespace std;

Network::Network(const int inputDim, vector<int> & hidDim,const int outputDim)
{

    int h0=inputDim , h1=hidDim[0];
    
    Layer* couche = new Layer(h1,h0+1); 
    this->couches.emplace_back(move(*couche)); // std::move()

    for (int i=1;i< hidDim.size();i++ )
    {
        h0=h1;
        h1=hidDim[i];
        Layer* couche(new Layer(h1,h0+1));
        this->couches.emplace_back(move(*couche));
    }
    OutputLayer* f = new OutputLayer(outputDim,h1+1);
    this->fcouche = *f;
   
}


Network::~Network(){//& ça marche?

    OutputLayer * f = &fcouche;
    delete f;
    f=nullptr;
    Layer* t;
    for(int i=0 ; i < this->couches.size() ;++i )
    {
        t = &couches[i];
        delete t;
    }
    t=nullptr;

}



void Network::forward_propagation(Matrix& TrainXset)
{
    /*Forward propagate the provided inputs through the Network
    * update the matrix arete for all the layers
    **/
    //image is a column
   TrainXset.ajouterLigneUn();
   this->couches[0].setEntree(TrainXset);
   
   for (int i =1 ; i< this->couches.size() ; i++)
   {
        this->couches[i].activation(couches[i-1]);
   }
   this->fcouche.activation(this->couches[this->couches.size()-1]);
   fcouche.Sortie();
   fcouche.sortie();


}

double Network::cross_entropy(Matrix& TrainYset){
    /* Calculate cross entropy loss if the predictions and true values are given
    **/
   int batch_size = TrainYset.getnbRows();

   Matrix z=fcouche.getProba().apply_function(log);
   z= z.multiplicationHadamard(TrainYset);
   double error=z.element_sum();
   return (-error/batch_size);

}

void Network::backward_propagation(Matrix& TrainYset){
    /*
     *  Compute deltas of each layer 
     *  delta_L : delta of the final layer 
     **/
    Matrix delta_L=this->fcouche.getProba()-TrainYset; //soustraction
    fcouche.setDeltas(delta_L);//setDelta
    for(int i = this-> couches.size()-1;i >= 0;i--) 
        couches[i].calculerDelta(couches[i+1]);//dimension
    
}


void Network::update_weight(double learningRate){
    /*batch gradient descent with batch size as number of training examples
    **/
   Matrix z; Matrix c;
        z=fcouche.getEntree().transposition();
        z= fcouche.getDelta()*z;
        z= z.cstMultMat(learningRate/fcouche.getEntree().getnbColumns());
        c=fcouche.getArete()-z;
        fcouche.setArete(c);
   for (int i=0 ; i<= couches.size()-1;i++){
        z= couches[i].getEntree().transposition();
        z= couches[i].getDelta()*z;
        z= z.cstMultMat(learningRate/couches[i].getEntree().getnbColumns());
        c=couches[i].getArete()-z;
        couches[i].setArete(c);
   }
      
}
void Network::train(Matrix& TrainX ,Matrix & TrainY,double learningRate,int batch_size,int epochs=10)
{
    /* Train the Neural Network and change weights
        train epochs times with dataset 
    **/
   int e=0;
   while (e< epochs){

    int it =0; 
    double error = 0;
    while (it+ batch_size< TrainX.getnbRows()){

        Matrix TrainXset =TrainX.troncature(it,it+batch_size);
         //size 
        Matrix TrainYset = TrainY.troncature(it ,it+batch_size);

        forward_propagation(TrainXset);
        error += cross_entropy(TrainYset);
        backward_propagation(TrainYset);
        update_weight(learningRate);
        it+=batch_size;
    }


    e++;
   }


}
double Network::test(Matrix& TestX, Matrix& TestY,int batchsize)
{
    /* Calculer the validation error over the Test set;
     * 
     */
    int it =0 ;
    double error =0;
    double fiabilite=0;
    int turn =0;

    while (it + batchsize < TestX.getnbRows())
    {
        Matrix TestXset =TestX.troncature(it,it+batchsize);
         //size 
        Matrix TestYset = TestY.troncature(it,it+batchsize);

        forward_propagation(TestXset);
        error += cross_entropy(TestYset);
        fiabilite += calcul_fiabilite(TestYset);

        turn++;
    }
    fiabilite /= turn;
    return fiabilite;
    
}
double Network::calcul_fiabilite(Matrix& Y)
{
    Matrix z=fcouche.getResult()-Y ;
    int count=0;
    for( int i=0;i< z.getnbRows();i++)
        for (int j=0; j< z.getnbColumns();j++)
            if(z.getPoidsIndex(i,j)==0) count++;
    
    double res = count/Y.getnbRows();
    return res;
}

