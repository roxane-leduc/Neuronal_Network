#include <cmath>
#include <vector>
#include <iostream>

#include "TrainingFunction.hpp"

// Constructeur
TrainingFunction::TrainingFunction()
{
}

double TrainingFunction::sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

double TrainingFunction::reLu(double x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return 0;
    }
}

std::vector<double> TrainingFunction::softmax(const std::vector<double> &x)
{
    std::vector<double> y(x.size());
    double sum = 0.0;
    for (int i = 0; i < x.size(); i++)
    {
        y[i] = exp(x[i]);
        sum += y[i];
    }
    for (int i = 0; i < y.size(); i++)
    {
        y[i] /= sum;
    }
    return y;
}

double TrainingFunction::sigmoid_derivative(double x)
{
    double y = TrainingFunction::sigmoid(x);
    return y * (1 - y);
}

double TrainingFunction::relu_derivative(double x)
{
    if (x > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

std::vector<double> TrainingFunction::softmax_derivative(const std::vector<double> &y)
{
    std::vector<double> d(y.size());
    for (int i = 0; i < y.size(); i++)
    {
        double s = 0;
        for (int j = 0; j < y.size(); j++)
        {
            if (i == j)
            {
                s += y[i] * (1 - y[i]);
            }
            else
            {
                s -= y[i] * y[j];
            }
        }
        d[i] = s;
    }
    return d;
}

// Destructeur
TrainingFunction::~TrainingFunction()
{
}

int main(int argc, char *argv[], char *envp[])
{
    TrainingFunction f1 = TrainingFunction();
    TrainingFunction f2 = TrainingFunction();
    TrainingFunction f3 = TrainingFunction();

    std::cout << f1.sigmoid(3) << std::endl;
    std::cout << f1.reLu(3) << std::endl;

    std::cout << f1.sigmoid_derivative(3) << std::endl;
    std::cout << f1.relu_derivative(3) << std::endl;

    std::vector<double> sm1 = {13.0, 14.0, 15.0};
    std::vector<double> sm2 = f2.softmax(sm1);
    std::cout << sm2[0] << std::endl;

    std::vector<double> sm3 = f3.softmax_derivative(sm2);
    std::cout << sm3[0] << std::endl;
}