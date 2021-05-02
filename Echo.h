#ifndef ECHO_CODE
#define ECHO_CODE

#include "IAudioProcessor.h"
#include "Wav.h"

class Echo : public IAudioProcessor
{
    int delay;
    bool isStereo;
    bool is16Bit;
public:
    Echo(int delay, Wav &wav, bool isStereo, bool is16Bit);
    ~Echo();
    void processBuffer() override;
};

#endif
