#include "Normalization.h"
#include <iostream>

Normalization::Normalization(int negativeNormal, Wav* wav)
{
    Normalization::negativeNormal = negativeNormal;
    Normalization::isStereo = wav->isStereo;
    Normalization::is16Bit = wav->is16Bit;
    processBuffer(wav);
}

Normalization::~Normalization()
{

}

void Normalization::processBuffer(Wav *wav)
{
    if (!is16Bit)
    {
        auto buffer = wav->get8BitBuffer();
        int peak = 0;
        for (size_t i = 0; i < wav->getBufferSize(); i++)
        {
            if (buffer[i] > peak)
            {
                peak = (int)buffer[i];
            }        
        }
        std::cout << peak;
        int normal = 255 - peak - negativeNormal;
        std::cout << normal;
        for (size_t i = 0; i < wav->getBufferSize(); i++)
        {
            buffer[i] += normal;
        }
    }
    else
    {
        auto buffer = wav->get16BitBuffer();
        short peak = 0;
        for (size_t i = 0; i < wav->getBufferSize(); i++)
        {
            if (buffer[i] > peak)
            {
                peak = buffer[i];
            }        
        }
        std::cout << peak;
        int normal = 32167 - peak - negativeNormal;
        std::cout << normal;
        for (size_t i = 0; i < wav->getBufferSize(); i++)
        {
            buffer[i] += normal;
        }
    }
 
}