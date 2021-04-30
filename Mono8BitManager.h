#ifndef MONO8BITMANAGER_CODE
#define MONO8BITMANAGER_CODE

#include "AudioManager.h"


class Mono8BitManager : public AudioManager<unsigned char*>
{
private:
    unsigned char* buffer;
public:
    Mono8BitManager(/* args */);
    ~Mono8BitManager();
    void captureData(const std::string &fileName) override;
    unsigned char* getBuffer() override;
    Header getHeader() override;
    MetaData getMetaData() override;
    void print() override;
};

#endif // MONO8BITMANAGER_CODE