#include "Echo.h"

Echo::Echo(float delayInSeconds, Wav* wav)
{
    Echo::delay = delayInSeconds * wav->getHeader().sample_rate;
    Echo::isStereo = wav->isStereo;
    Echo::is16Bit = wav->is16Bit;
    processBuffer(wav);
}
Echo::~Echo()
{

}
void Echo::processBuffer(Wav* wav )
{
    if (!is16Bit)
    {       
        auto buffer = wav->get8BitBuffer();
        uint8_t sample[wav->getBufferSize()];
        uint8_t delayed[wav->getBufferSize()];

        for (int i = 0; i < wav->getBufferSize(); i++)
        {
            sample[i] = buffer[i];
            if (i >= Echo::delay - 1)
            {
            delayed[i] = buffer[i - Echo::delay - 1] * .4;
            }
        }
        for (int i = Echo::delay - 1; i < wav->getBufferSize(); i++)
        {
            buffer[i] = (sample[i] + delayed[i]) / 2;
        }
              
    }
    else
    {        
        auto buffer = wav->get16BitBuffer();
        short* sample= new short[wav->getBufferSize()];
        short* delayed = new short[wav->getBufferSize()];

        for (int i = 0; i < wav->getBufferSize(); i++)
        {
            sample[i] = buffer[i];
            if (i >= Echo::delay - 1)
            {
            delayed[i] = buffer[i - Echo::delay - 1] * .4;
            }
        }
        for (int i = Echo::delay - 1; i < wav->getBufferSize(); i++)
        {
            buffer[i] = (sample[i] + delayed[i]) / 2;
        }
    }   
}