#include "Mono16BitManager.h"

Mono16BitManager::Mono16BitManager(/* args */)
{
}

Mono16BitManager::~Mono16BitManager()
{
}

void Mono16BitManager::captureData(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&header, sizeof(Header));
        Mono16BitManager::buffer = new short[header.data_bytes];
        file.read((char*)buffer, header.data_bytes);
        file.read((char*)&metadata, sizeof(MetaData));
    }

}

short* Mono16BitManager::getBuffer()
{
    return Mono16BitManager::buffer;
}

Header Mono16BitManager::getHeader()
{
    return Mono16BitManager::header;
}

MetaData Mono16BitManager::getMetaData()
{
    return Mono16BitManager::metadata;
}

void Mono16BitManager::print(){
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
