#ifndef MONO16BITMANAGER_CODE
#define MONO16BITMANAGER_CODE

#include "AudioManager.h"


class Mono16BitManager : public AudioManager<short*>
{
private:
    short* buffer;
public:
    Mono16BitManager(/* args */);
    ~Mono16BitManager();
    void captureData(const std::string &fileName) override;
    short* getBuffer() override;
    Header getHeader() override;
    MetaData getMetaData() override;
    void print() override;
};

#endif // MONO16BITMANAGER_CODE
