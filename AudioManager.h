#ifndef AUDIOMANAGER_CODE
#define AUDIOMANAGER_CODE

#include "Header.h"
#include "MetaData.h"
#include "Wav.h"
#include <string>
#include <fstream>
#include <iostream>

template <class T>
class AudioManager
{
    protected:
    Header header;
    MetaData metadata;

    public:
    virtual void captureData(const std::string &fileName) = 0;
    virtual T getBuffer() = 0;
    virtual Header getHeader() = 0;
    virtual MetaData getMetaData() = 0;
    virtual void writeFile(const std::string &outFileName, Wav *wav) = 0;
    virtual void print() = 0;
};


#endif // AUDIOMANAGER_CODE
