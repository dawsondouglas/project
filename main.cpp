//Douglas Dawson & Jarrit Learoyd
//5/2/21
//Final Semester Project
//To store information in a CSV file that can import into any spreadsheet program

/** @file */
#include <iostream>
#include <vector>
#include <filesystem>
#include "EightBitManager.h"
#include "SixteenBitManager.h"
#include "PreprocessManager.h"
#include "Noisegate.h"
#include "Echo.h"
#include "Normalization.h"
#include "Wav.h"
#include <dirent.h>
#include <sys/types.h>

using namespace std;

void manageProcessors(vector<Wav*> songs);

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


int main() {
    PreprocessManager *preprocessManager = new PreprocessManager();
    AudioManager<unsigned char*> *eightbit = new EightBitManager();
    AudioManager<short*> *sixteenbit = new SixteenBitManager();
    vector<Wav*> songs;
    vector<string> rawWav;
    string songName;   
    bool failed;
    bool condition = true;
    int input;
while (condition)
{
    do
    {       
        failed = false;
        cout << "Audio Processor\n\n1. Collect Files\n2. List Files";
        cout << "\n3. Process Files\n4. Apply Effect Processing\n5. Write New Files\n6. Exit";
        cout << "\n\nChoice: ";
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(80, '\n');
            failed = true;
        }
        if (input > 6 || input < 1)
        {
            failed = true;
        }
    } while (failed);

    switch (input)
    {
    case 1:
        {
            struct dirent *entry;
            char* path = getcwd(path, 100);
            DIR *dir = opendir(path);
            vector<string> rawFiles;
            
            if (dir == NULL) {
                cout << "Closed due to null directory";
                return 0;
            }
            while ((entry = readdir(dir)) != NULL) {
                rawFiles.push_back(string(entry->d_name)); 
            }
            closedir(dir);
            
            for (size_t i = 0; i < rawFiles.size(); i++)
            {
                if (rawFiles[i].find(".wav") != string::npos)
                {
                    rawWav.push_back(rawFiles[i]);
                }               
            }
        }   
            cout << endl;    
        break;
    case 2:
        for (size_t i = 0; i < rawWav.size(); i++)
        {
            cout << rawWav[i] << endl;
        }
        cout << endl;
        break;
    case 3:
        {
            for (size_t i = 0; i < rawWav.size(); i++)
            {
                string songName = rawWav[i];
                preprocessManager->captureData(songName);
                int bitRate = preprocessManager->processBitrate();
                switch (bitRate)
                {
                case 8:
                        eightbit->captureData(songName);
                        songs.push_back(new Wav(eightbit->getBuffer(),eightbit->getHeader(),eightbit->getMetaData(), songName));

                    break;
                case 16:
                        sixteenbit->captureData(songName);
                        songs.push_back(new Wav(sixteenbit->getBuffer(),sixteenbit->getHeader(),sixteenbit->getMetaData(), songName));
                    break;
                default:
                    break;
                }
            }          
        }
        break;
    case 4:
        manageProcessors(songs);
        break;
    case 5:
        {
            for (size_t i = 0; i < songs.size(); i++)
            {
                if (songs[i]->is16Bit)
                {
                    sixteenbit->writeFile("new-" + songs[i]->name,songs[i]);
                }
                else
                {
                    eightbit->writeFile("new-" + songs[i]->name,songs[i]);
                }
                
            }
        }
      break;  
    case 6:
        condition = false;
        cout << "Goodbye!";
        break;
    }
}
    return 0;
}

void manageProcessors(vector<Wav*> songs){
    bool failed;
    int input;
    bool switches[songs.size()][3];
    float noisegateValue = 10;
    float echoValue = .5;
    int normalizationValue = 6;

    for (size_t i = 0; i < songs.size(); i++)
    {
        for (size_t x = 0; x < 3; x++)
        {
            switches[i][x] = false;
        }
        
    }
    while (true)
    {
        do
        {       
            failed = false;
            cout << "\nName\t\t\tNoisegate\tEcho\tNormalization\n";
            for (size_t i = 0; i < songs.size(); i++)
            {
                cout << i + 1 << ". " << songs[i]->name << "\t\t";
                for (size_t x = 0; x < 3; x++)
                {
                    if (x != 2)
                    {
                        cout << switches[i][x] << "\t";
                    }
                    else
                    {
                        cout << switches[i][x] << endl;
                    }
                }
                
            }
            cout << songs.size() + 1 << ". Change Values\n";
            cout << songs.size() + 2 << ". Process\nChoice: ";
            cin >> input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(80, '\n');
                failed = true;
            }
            if (input > songs.size() + 2  || input < 0)
            {
                failed = true;
            }
        } while (failed);

        if (input == songs.size() + 1)
        {
            do
            {       
                failed = false;
                cout << "Change values:\n1. Noisegate (percent)\t" << noisegateValue;
                cout << "\n2. Echo (seconds delay)\t" << echoValue << "\n3. Normalization (negative db)\t" << normalizationValue;
                cout << "\n4. Back\nChoice: ";
                cin >> input;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(80, '\n');
                    failed = true;
                }
                if (input > 4 || input < 1)
                {
                    failed = true;
                }
            } while (failed);

            switch (input)
            {
            case 1:
                do
                {       
                    failed = false;
                    cout << "Please enter a new value for the noisegate as percent: ";
                    cin >> noisegateValue;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(80, '\n');
                        failed = true;
                    }
                    if (noisegateValue > 100 || noisegateValue < 0)
                    {
                        failed = true;
                    }
                } while (failed);
                break;
            case 2:
                do
                {       
                    failed = false;
                    cout << "Please enter a new value for the echo in seconds: ";
                    cin >> echoValue;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(80, '\n');
                        failed = true;
                    }
                    if (echoValue < 0)
                    {
                        failed = true;
                    }
                } while (failed);
                break;
            case 3:
                do
                {       
                    failed = false;
                    cout << "Please enter a new value for the normalization, this will be treated as a negative db: ";
                    cin >> echoValue;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(80, '\n');
                        failed = true;
                    }
                } while (failed);
                break;
            case 4:
                break;
            }

            continue;
        }
        

        if (input == songs.size() + 2)
        {
            for (size_t i = 0; i < songs.size(); i++)
            {
                if (switches[i][0] == true)
                {
                    Noisegate *noisegate = new Noisegate(noisegateValue, songs[i]);
                    noisegate->~Noisegate();
                }
                if (switches[i][1] == true)
                {
                    Echo *echo = new Echo(echoValue,songs[i]);
                }
                if (switches[i][2] == true)
                {
                    Normalization *normalization = new Normalization(normalizationValue, songs[i]);
                }
            }         
            break;
        }

        for (size_t i = 0; i < songs.size(); i++)
        {
            if (input == i + 1 )
            {
                do
                {       
                    failed = false;
                    cout << songs[i]->name << "\n1. Noisegate\n2. Echo\n3. Normalization\nChoice: ";
                    cin >> input;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(80, '\n');
                        failed = true;
                    }
                    if (input > 3 || input < 1)
                    {
                        failed = true;
                    }
                } while (failed);

                switch (input)
                {
                case 1:
                    if (switches[i][0] == false)
                    {
                        switches[i][0] = true;
                    }
                    else
                    {
                        switches[i][0] = false;
                    }                   
                    break;
                case 2:
                    if (switches[i][1] == false)
                    {
                        switches[i][1] = true;
                    }
                    else
                    {
                        switches[i][1] = false;
                    }                   
                    break;
                case 3:
                    if (switches[i][2] == false)
                    {
                        switches[i][2] = true;
                    }
                    else
                    {
                        switches[i][2] = false;
                    }                   
                    break;    
                default:
                    break;
                }
            }
            
        }
    }    
}
