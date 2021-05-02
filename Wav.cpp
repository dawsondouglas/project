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

unsigned char* Wav::get8BitBuffer()
{
    return eightBuffer;
}

short* Wav::get16BitBuffer()
{
    return sixteenBuffer;
}

int Wav::getBufferSize()
{
    return header.data_bytes;
}

Header& Wav::getHeader()
{
    return header;
}

MetaData& Wav::getMetaData()
{
    return metadata;
}