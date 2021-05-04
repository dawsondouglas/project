#ifndef SIXTEENBITMANAGER_CODE
#define SIXTEENBITMANAGER_CODE

#include "AudioManager.h"


class SixteenBitManager : public AudioManager<short*>
{
private:
    short* buffer;
public:
    SixteenBitManager(/* args */);
    ~SixteenBitManager();
    void captureData(const std::string &fileName) override;
    void writeFile(const std::string &outFileName, Wav *wav) override;
    short* getBuffer() override;
    Header getHeader() override;
    MetaData getMetaData() override;
    void print() override;
};

#endif // SIXTEENBITMANAGER_CODE
