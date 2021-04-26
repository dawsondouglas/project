#ifndef AUDIOMANAGER_CODE
#define AUDIOMANAGER_CODE

#include "Header.h"
#include <string>

class AudioManager
{
    protected:
    Header header;

    public:
    virtual void captureData(const std::string &fileName) = 0;
    virtual void print() = 0;
};


#endif // AUDIOMANAGER_CODE
