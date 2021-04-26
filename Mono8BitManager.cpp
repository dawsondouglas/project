#include "Mono8BitManager.h"

Mono8BitManager::Mono8BitManager(/* args */)
{
}

Mono8BitManager::~Mono8BitManager()
{
}

void Mono8BitManager::captureData(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    char* file_content;
    if(file.is_open()){
        file.read((char*)&header, sizeof(Header));
        
    }

}

void Mono8BitManager::print(){
    std::cout << header.riff_header << std::endl;
    std::cout << header.wav_size << std::endl;
    std::cout << header.fmt_header << std::endl;
    std::cout << header.fmt_chunk_size << std::endl;
    std::cout << header.audio_format << std::endl;
    std::cout << header.num_channels << std::endl;
}