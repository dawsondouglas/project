#ifndef MONO8BITMANAGER_CODE
#define MONO8BITMANAGER_CODE

#include "AudioManager.h"
#include <iostream>

class Mono8BitManager : public AudioManager
{
private:
    unsigned char* buffer;
public:
    Mono8BitManager(/* args */);
    ~Mono8BitManager();
    void captureData(const std::string &fileName) override;
    void print() override;
};

#endif // MONO8BITMANAGER_CODE