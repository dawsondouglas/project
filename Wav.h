#ifndef WAV_CODE
#define WAV_CODE

#include "Header.h"
#include "MetaData.h"
#include <string>

class Wav
{
private:
    Header header;
    unsigned char* eightBuffer;
    short* sixteenBuffer;   
    MetaData metadata;
    
public:
    bool isStereo = false;
    bool is16Bit = false;
    std::string name;
    Wav(unsigned char* buffer, Header header, MetaData metadata, std::string name);
    Wav(short* buffer, Header header, MetaData metadata, std::string name);
    unsigned char* get8BitBuffer();
    short* get16BitBuffer();
    int getBufferSize();
    Header& getHeader();
    MetaData& getMetaData();
    ~Wav();
};

#endif // WAV_CODE