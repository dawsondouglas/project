#ifndef EIGHTBITMANAGER_CODE
#define EIGHTBITMANAGER_CODE

#include "AudioManager.h"

class EightBitManager : public AudioManager<unsigned char*>
{
private:
    unsigned char* buffer;
public:
    EightBitManager(/* args */);
    ~EightBitManager();
    void captureData(const std::string &fileName) override;
    unsigned char* getBuffer() override;
    Header getHeader() override;
    MetaData getMetaData() override;
    void writeFile(const std::string &outFileName, Wav *wav) override;
    void print() override;
};

#endif // EIGHTBITMANAGER_CODE