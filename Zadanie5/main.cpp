#include "gribdecoder.h"

int main() 
{
    GribDecoder decoder;
    decoder.decode("all.grib");
    return 0;
}
