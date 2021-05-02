#include "SixteenBitManager.h"

SixteenBitManager::SixteenBitManager(/* args */)
{
}

SixteenBitManager::~SixteenBitManager()
{
}

void SixteenBitManager::captureData(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&header, sizeof(Header));
        SixteenBitManager::buffer = new short[header.data_bytes];
        file.read((char*)buffer, header.data_bytes);
        file.read((char*)&metadata, sizeof(MetaData));
    }

}

void SixteenBitManager::writeFile(const std::string &outFileName, Wav *wav) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&wav->getHeader(),sizeof(Header));
    outFile.write((char*)wav->get16BitBuffer(), wav->getBufferSize());
    outFile.write((char*)&wav->getMetaData(), sizeof(MetaData));
    outFile.close();
}

short* SixteenBitManager::getBuffer()
{
    return SixteenBitManager::buffer;
}

Header SixteenBitManager::getHeader()
{
    return SixteenBitManager::header;
}

MetaData SixteenBitManager::getMetaData()
{
    return SixteenBitManager::metadata;
}

void SixteenBitManager::print(){
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
