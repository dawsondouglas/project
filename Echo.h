#ifndef ECHO_CODE
#define ECHO_CODE

#include "IAudioProcessor.h"

class Echo : public IAudioProcessor
{
    int delay;
    bool isStereo;
    bool is16Bit;
public:
    Echo(float delayInSeconds, Wav* wav);
    ~Echo();
    void processBuffer(Wav *wav) override;
};

#endif
