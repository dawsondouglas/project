#ifndef NOISEGATE_CODE
#define NOISEGATE_CODE

#include "IAudioProcessor.h"

class Noisegate : public IAudioProcessor
{
    float threshold;
    bool isStereo;
    bool is16Bit;
public:
    Noisegate(float threshold, Wav *wav);
    ~Noisegate();
    void processBuffer(Wav *wav) override;
};
#endif
