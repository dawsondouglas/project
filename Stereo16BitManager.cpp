#include "Stereo16BitManager.h"

Stereo16BitManager::Stereo16BitManager(/* args */)
{
}

Stereo16BitManager::~Stereo16BitManager()
{
}

void Stereo16BitManager::captureData(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&header, sizeof(Header));
        Stereo16BitManager::buffer = new short[header.data_bytes];
        file.read((char*)buffer, header.data_bytes);
        file.read((char*)&metadata, sizeof(MetaData));
    }
}

short* Stereo16BitManager::getBuffer()
{
    return Stereo16BitManager::buffer;
}

Header Stereo16BitManager::getHeader()
{
    return Stereo16BitManager::header;
}

MetaData Stereo16BitManager::getMetaData()
{
    return Stereo16BitManager::metadata;
}

void Stereo16BitManager::print(){
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