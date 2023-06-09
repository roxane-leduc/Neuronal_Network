#ifndef __DATASOURCE_HPP__
#define __DATASOURCE_HPP__

#include <string>
#include <vector>
#include "Matrix.hpp"



namespace DataSource
{

    int process_mnist_images(const char * path, Matrix& Xtrain , Matrix& Ytrain,int nr_images=100 );

    int process_mnist_csv(const char* filename, Matrix & Xtrain, Matrix & Ytrain);


};

#endif