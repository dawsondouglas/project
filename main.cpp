//Douglas Dawson & Jarrit Learoyd
//5/2/21
//Final Semester Project
//To store information in a CSV file that can import into any spreadsheet program

/** @file */
#include <iostream>
#include <vector>
#include "Mono8BitManager.h"
#include "Mono16BitManager.h"
#include "Stereo8BitManager.h"
#include "Stereo16BitManager.h"
#include "PreprocessManager.h"
#include "Wav.h"

using namespace std;

/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}

int main() {
    PreprocessManager *preprocessManager = new PreprocessManager();
    AudioManager<unsigned char*> *eightbitone = new Mono8BitManager();
    AudioManager<short*> *sixteenbitone = new Mono16BitManager();
    AudioManager<unsigned char*> *eightbittwo = new Stereo8BitManager();
    AudioManager<short*> *sixteenbittwo = new Stereo16BitManager();
    vector<Wav*> songs;
    preprocessManager->captureData("yes-8-bit-stereo.wav");
    int bitRate = preprocessManager->processBitrate();
    switch (bitRate)
    {
    case 8:
        if (preprocessManager->checkIfStereo())
        {
            eightbittwo->captureData("yes-8-bit-stereo.wav");
            eightbittwo->print();
            songs.push_back(new Wav(eightbittwo->getBuffer(),eightbittwo->getHeader(),eightbittwo->getMetaData()));
        }
        else
        {
            eightbitone->captureData("yes-8-bit-mono.wav");
            eightbitone->print();
            songs.push_back(new Wav(eightbitone->getBuffer(),eightbitone->getHeader(),eightbitone->getMetaData()));
        }      
        break;
    case 16:
        if (preprocessManager->checkIfStereo())
        {
            sixteenbitone->captureData("yes-16-bit-stereo.wav");
            sixteenbitone->print();
            songs.push_back(new Wav(sixteenbittwo->getBuffer(),sixteenbittwo->getHeader(),sixteenbittwo->getMetaData()));
        }
        else
        {
            sixteenbittwo->captureData("yes-16-bit-mono.wav");
            sixteenbittwo->print();
            songs.push_back(new Wav(sixteenbitone->getBuffer(),sixteenbitone->getHeader(),sixteenbitone->getMetaData()));
        }
        break;
    default:
        break;
    }

    return 0;
}
