#ifndef NORMALIZATION_CODE
#define NORMALIZATION_CODE

#include "IAudioProcessor.h"
#include <algorithm>

class Normalization : public IAudioProcessor
{
    int negativeNormal;
    bool isStereo;
    bool is16Bit;
public:
    Normalization(int normal, Wav *wav);
    ~Normalization();
    void processBuffer(Wav *wav) override;
};

#endif