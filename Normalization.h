#ifndef NORMALIZATION_CODE
#define NORMALIZATION_CODE

#include "IAudioProcessor.h"

class Normalization : public IAudioProcessor
{
    float range;
    bool isStereo;
    bool is16Bit;
public:
    Normalization(int range, Wav &wav, bool isStereo, bool is16Bit);
    ~Normalization();
    void processBuffer(Wav *wav) override;
};

#endif