#ifndef WAV_CODE
#define WAV_CODE

#include "Header.h"
#include "MetaData.h"

class Wav
{
private:
    Header header;
    unsigned char* eightBuffer;
    short* sixteenBuffer;
    bool isStereo = false;
    bool is16Bit = false;
    MetaData metadata;
    
public:
    Wav(unsigned char* buffer, Header header, MetaData metadata);
    Wav(short* buffer, Header header, MetaData metadata);
    ~Wav();
};

#endif // WAV_CODE