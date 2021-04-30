#ifndef STEREO16BITMANAGER_CODE
#define STEREO16BITMANAGER_CODE

#include "AudioManager.h"

class Stereo16BitManager : public AudioManager<short*>
{
private:
    short* buffer;
public:
    Stereo16BitManager(/* args */);
    ~Stereo16BitManager();
    void captureData(const std::string &fileName) override;
    short* getBuffer() override;
    Header getHeader() override;
    MetaData getMetaData() override;
    void print() override;
};

#endif // STEREO16BITMANAGER_CODE