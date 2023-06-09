#include "Matrix.hpp"
#include "Network.hpp"
#include "DataSource.hpp"

#include <iostream>
#include <vector>
#include <cmath>

#include <opencv2/opencv.hpp>
using namespace std;

int test1(){
	const char* path = "data/mnist_train.csv";
	Matrix Xtrain, Ytrain; 
	DataSource::process_mnist_images(path, Xtrain, Ytrain);
	int inputs = Xtrain.getnbRows();
	int outputs = Ytrain.getnbRows();
	std::vector<int> layers = {10};
	std::unique_ptr<Network> ann(new Network(inputs,layers,outputs));
	ann->train(Xtrain, Ytrain, 0.1, 50, 10);
	
	const char* test_path = "data/mnist_test.csv";
	Matrix Xval, Yval; 
	DataSource::process_mnist_images(test_path, Xval, Yval);
	return ann->test(Xval, Yval, 200);

}

int main(){
	return test1();
    	
}