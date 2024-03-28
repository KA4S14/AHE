

#include <iostream>
#include "PBMreader.h"
#include "PGMreader.h"
#include "PPMreader.h"
int main()
{
    std::cout << "Hello World!\n";
  /* 
    PBMreader j("letterj.pbm");
    j.printImgData();
    j.printImageInfo();
    
      */
  
   PGMreader jd("ex.pgm");
   jd.printImgData();
   jd.printImageInfo();
   jd.rotationImg();

 
   PPMreader jk("feep.ppm");
   jk.printImgData();
   jk.printImageInfo();
   

}

