#ifndef _GRIBDECODER_H
#define _GRIBDECODER_H

#include <string>
#include<fstream>

class GribDecoder 
{
private:
    std::fstream gribFile;
    uint32_t startSection0=0;
    uint32_t startSection1 = 0;
    int32_t section1Length = 0;
    int32_t startSection2 = 0;
    int32_t section2Length = 0;
    
    int32_t startSection4 = 0;
    int32_t section4Length = 0;
    uint32_t endofData=0;
    int messageLength=0;

    void findSection0();
    void findSection1();
    void findSection2();
    void findSection4();

public:
    GribDecoder();
    void decode(const std::string& filename);
};

#endif // GRIBDECODER_H



