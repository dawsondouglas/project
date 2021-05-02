#ifndef PREPROCESS_CODE
#define PREPROCESS_CODE

#include "AudioManager.h"
#include "Header.h"

class PreprocessManager : public AudioManager<int>
{
private:
    Header header;
public:
    PreprocessManager(/* args */);
    ~PreprocessManager();
    void captureData(const std::string &fileName) override;
    void writeFile(const std::string &outFileName, Wav *wav) override;
    int getBuffer() override;
    Header getHeader() override;
    MetaData getMetaData() override;
    bool checkIfStereo();
    int processBitrate();
    void print() override;
};

#endif // PREPROCESS_CODE
