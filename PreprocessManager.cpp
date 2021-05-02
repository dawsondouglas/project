#include "PreprocessManager.h"

PreprocessManager::PreprocessManager(/* args */)
{
}

PreprocessManager::~PreprocessManager()
{
}

void PreprocessManager::captureData(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&header, sizeof(Header));        
    }   
}
bool PreprocessManager::checkIfStereo()
{
    if (header.num_channels == 2)
    {
        return true;
    }
    else return false;
}
int PreprocessManager::processBitrate()
{
    return ((header.byte_rate / header.num_channels) / header.sample_rate) * 8;
}

int PreprocessManager::getBuffer()
{
    return 0;
}

void PreprocessManager::writeFile(const std::string &outFileName, Wav *wav)
{
}

Header PreprocessManager::getHeader()
{
    return PreprocessManager::header;
}

MetaData PreprocessManager::getMetaData()
{
    return PreprocessManager::metadata;
}

void PreprocessManager::print() {

}