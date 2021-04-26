#ifndef STEREO8BITMANAGER_CODE
#define STEREO8BITMANAGER_CODE

#include "AudioManager.h"

class Stereo8BitManager : public AudioManager
{
private:
    unsigned char* leftBuffer;
    unsigned char* rightBuffer;
public:
    Stereo8BitManager(/* args */);
    ~Stereo8BitManager();
};

Stereo8BitManager::Stereo8BitManager(/* args */)
{
}

Stereo8BitManager::~Stereo8BitManager()
{
}


#endif // MONOMANAGER_CODE