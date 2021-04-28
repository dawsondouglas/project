#ifndef PREPROCESS_CODE
#define PREPROCESS_CODE

#include "AudioManager.h"
#include "Header.h"

class PreprocessManager : public AudioManager
{
private:
    Header header;
public:
    PreprocessManager(/* args */);
    ~PreprocessManager();
    void captureData(const std::string &fileName) override;
    bool processChannels();
    int processBitrate();
    void print() override;
};

#endif // PREPROCESS_CODE
