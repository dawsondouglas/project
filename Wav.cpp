#include "Wav.h"

Wav::Wav(unsigned char* buffer, Header header, MetaData metadata)
{
    if (header.num_channels == 2)
    {
        Wav::isStereo = true;
    }
    Wav::header = header;
    Wav::eightBuffer = buffer;
    Wav::metadata = metadata;       
}

Wav::Wav(short* buffer, Header header, MetaData metadata)
{
    if (header.num_channels == 2)
    {
        Wav::isStereo = true;
    }
    Wav::is16Bit = true;
    Wav::header = header;
    Wav::sixteenBuffer = buffer;
    Wav::metadata = metadata;
}

Wav::~Wav()
{
}