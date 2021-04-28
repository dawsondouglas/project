#ifndef AUDIOMANAGER_CODE
#define AUDIOMANAGER_CODE

#include "Header.h"
#include "MetaData.h"
#include <string>
#include <fstream>

class AudioManager
{
    protected:
    Header header;
    MetaData metadata;

    public:
    virtual void captureData(const std::string &fileName) = 0;
    virtual void print() = 0;
};


#endif // AUDIOMANAGER_CODE
