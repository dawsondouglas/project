#include "Noisegate.h"

Noisegate::Noisegate(float threshold, Wav* wav, bool isStereo, bool is16Bit)
{
    Noisegate::threshold = threshold / 100.;
    Noisegate::isStereo = isStereo;
    Noisegate::is16Bit = is16Bit;
    processBuffer(wav);
}

Noisegate::~Noisegate()
{
}

void Noisegate::processBuffer(Wav* wav )
{
    if (!is16Bit)
    {
        int upperBound = Noisegate::threshold * 128 + 128;
        int lowerBound = 128 - (Noisegate::threshold * 128);
        if (!isStereo)
        {
            unsigned char* buffer =  wav->get8BitBuffer();
            auto bufferSize = wav->getBufferSize();
            for (int i = 0; i < bufferSize; i++)
            {
                if ((int)buffer[i] <= upperBound && (int)buffer[i] >= lowerBound)
                {
                    buffer[i] = 128;
                }       
            }
        }
        else
        {
            unsigned char* buffer =  wav->get8BitBuffer();
            unsigned char* leftBuffer = new unsigned char[wav->getBufferSize() / 2];
            unsigned char* rightBuffer = new unsigned char[wav->getBufferSize() / 2];
            int x = 0;
            auto bufferSize = wav->getBufferSize();
            for (int i = 0; i < bufferSize; i++)
            {
                leftBuffer[x] = buffer[i];
                i++;
                rightBuffer[x] = buffer[i];
                x++;
            }
            
            for (int i = 0; i < bufferSize / 2; i++)
            {
                if ((int)leftBuffer[i] <= upperBound && (int)leftBuffer[i] >= lowerBound &&
                    (int)rightBuffer[i] <= upperBound && (int)rightBuffer[i] >= lowerBound)
                {
                    rightBuffer[i] = 128;
                    leftBuffer[i] = 128;
                }       
            }
            x = 0;
            for (int i = 0; i < bufferSize; i++)
            {
                buffer[i] = leftBuffer[x];
                i++;
                buffer[i] = rightBuffer[x];
                x++;
            }
            
        }     
    }
    else
    {
        int upperBound = Noisegate::threshold * 32167;
        int lowerBound = Noisegate::threshold * -32167;
         if (!isStereo)
        {
            short* buffer =  wav->get16BitBuffer();
            auto bufferSize = wav->getBufferSize();
            for (int i = 0; i < bufferSize; i++)
            {
                if ((int)buffer[i] <= upperBound && (int)buffer[i] >= lowerBound)
                {
                    buffer[i] = 0;
                }       
            }
        }
        else
        {
            short* buffer =  wav->get16BitBuffer();
            short* leftBuffer = new short[wav->getBufferSize() / 2];
            short* rightBuffer = new short[wav->getBufferSize() / 2];
            int x = 0;
            auto bufferSize = wav->getBufferSize();
            for (int i = 0; i < bufferSize; i++)
            {
                leftBuffer[x] = buffer[i];
                i++;
                rightBuffer[x] = buffer[i];
                x++;
            }
            
            for (int i = 0; i < bufferSize / 2; i++)
            {
                if ((int)leftBuffer[i] <= upperBound && (int)leftBuffer[i] >= lowerBound &&
                    (int)rightBuffer[i] <= upperBound && (int)rightBuffer[i] >= lowerBound)
                {
                    rightBuffer[i] = 0;
                    leftBuffer[i] = 0;
                }       
            }
            x = 0;
            for (int i = 0; i < bufferSize; i++)
            {
                buffer[i] = leftBuffer[x];
                i++;
                buffer[i] = rightBuffer[x];
                x++;
            }
            
        }     
    }
    
}