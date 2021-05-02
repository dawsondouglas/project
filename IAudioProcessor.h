#ifndef IAUDIOPROCESSOR_CODE
#define IAUDIOPROCESSOR_CODE

#include "Wav.h"

class IAudioProcessor
{
    public:
    virtual void processBuffer(Wav *wav) = 0;
};

#endif
