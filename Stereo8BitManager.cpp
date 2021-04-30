#include "Stereo8BitManager.h"

Stereo8BitManager::Stereo8BitManager(/* args */)
{
}

Stereo8BitManager::~Stereo8BitManager()
{
}

void Stereo8BitManager::captureData(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&header, sizeof(Header));
        Stereo8BitManager::buffer = new unsigned char[header.data_bytes];
        file.read((char*)buffer, header.data_bytes);
        file.read((char*)&metadata, sizeof(MetaData));
    }
}

unsigned char* Stereo8BitManager::getBuffer()
{
    return Stereo8BitManager::buffer;
}

Header Stereo8BitManager::getHeader()
{
    return Stereo8BitManager::header;
}

MetaData Stereo8BitManager::getMetaData()
{
    return Stereo8BitManager::metadata;
}

void Stereo8BitManager::print(){
    std::cout << header.riff_header << std::endl;
    std::cout << header.wav_size << std::endl;
    std::cout << header.fmt_header << std::endl;
    std::cout << header.fmt_chunk_size << std::endl;
    std::cout << header.audio_format << std::endl;
    std::cout << header.num_channels << std::endl;
    std::cout << header.byte_rate << std::endl;
    std::cout << header.sample_rate << std::endl;
    std::cout << metadata.list_header << std::endl;
    std::cout << metadata.meta_size << std::endl;
    std::cout << metadata.info_header << std::endl;
    std::cout << metadata.meta_sub1 << std::endl;
    std::cout << metadata.sub1_characters << std::endl;
    std::cout << metadata.sub1_data << std::endl;    
}