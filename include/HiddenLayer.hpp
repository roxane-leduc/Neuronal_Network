#ifndef __CHEQUE_HPP__
#define __CHEQUE_HPP__

#include "Layer.hpp"

class HiddenLayer : public Layer
{
private:
    float result;

public:
    HiddenLayer();
    ~HiddenLayer();
};

#endif