//Douglas Dawson & Jarrit Learoyd
//5/2/21
//Final Semester Project
//To store information in a CSV file that can import into any spreadsheet program

/** @file */
#include <iostream>
#include <vector>
#include "EightBitManager.h"
#include "SixteenBitManager.h"
#include "PreprocessManager.h"
#include "Noisegate.h"
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
    AudioManager<unsigned char*> *eightbit = new EightBitManager();
    AudioManager<short*> *sixteenbit = new SixteenBitManager();
    vector<Wav*> songs;
    preprocessManager->captureData("yes-16-bit-stereo.wav");
    int bitRate = preprocessManager->processBitrate();
    switch (bitRate)
    {
    case 8:
            eightbit->captureData("yes-8-bit-stereo.wav");
            songs.push_back(new Wav(eightbit->getBuffer(),eightbit->getHeader(),eightbit->getMetaData()));

        break;
    case 16:
            sixteenbit->captureData("yes-16-bit-stereo.wav");
            songs.push_back(new Wav(sixteenbit->getBuffer(),sixteenbit->getHeader(),sixteenbit->getMetaData()));

        break;
    default:
        break;
    }
    Noisegate *noisegate = new Noisegate(10, songs[0], songs[0]->isStereo, songs[0]->is16Bit );
    cout << "test good";
    sixteenbit->writeFile("test.wav", songs[0]);

    return 0;
}
