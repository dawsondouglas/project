#ifndef STEREO8BITMANAGER_CODE
#define STEREO8BITMANAGER_CODE

#include "AudioManager.h"

class Stereo8BitManager : public AudioManager<unsigned char*>
{
private:
    unsigned char* buffer;
    
public:
    Stereo8BitManager(/* args */);
    ~Stereo8BitManager();
    void captureData(const std::string &fileName) override;
    unsigned char* getBuffer() override;
    Header getHeader() override;
    MetaData getMetaData() override;
    void print() override;
};

#endif // MONOMANAGER_CODE