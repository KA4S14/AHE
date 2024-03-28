#include "PPMreader.h"
#include<sstream>
#include<map>

PPMreader::PPMreader(std::string imgPath)
{
    imgFile.open(imgPath, std::ios::in);
    if (imgFile.good()) {
        std::string magicNum;
        std::string line;
        std::stringstream ss;

        int pxValue;
        Pixel px;
        char space;

        getline(imgFile, magicNum);
        if (magicNum == "P3") 
        {
            while (getline(imgFile, line)) 
            {
                if (!line.empty() && line[0] != '#') 
                {
                    if (width != 0 && height != 0) 
                    {
                        
                        ss.clear();
                        ss.str(line);
                        while (ss >> px.r >> px.g >> px.b)
                        {
                           // ss >> px.r >> px.g >> px.b;

                            pxValue = (px.r << 16) | (px.g << 8) | px.b;


                            imgData.push_back(pxValue);
                        }
                       
                                             
                                            
                        
                    }
                    else {
                        ss.clear();
                        ss.str(line);
                        ss >> width >> height;

                        getline(imgFile, line);
                        ss.clear();
                        ss.str(line);
                        ss >> depth;
                    }
                }
            }
        }
        else {
            std::cout << "File is other type than PPM\n";
        }
        imgFile.close();
    }
    else {
        std::cout << "Cannot open the file " << imgPath << "\n";
    }
}


void PPMreader::printImageInfo()
{
    std::cout << "Width x height :" << width << "x"
        << height << "\n";

    std::cout << "Number of unique colors: "
        << calcualteNumberOfUniqueColors() << "\n";

    std::cout << "Most frequent color: "
        << getMostFrequentColor().first << "\n";

    std::cout << "Number of most frequent color: "
        << getMostFrequentColor().second << "\n";

}

void PPMreader::printMostFrequentColor()
{
    std::cout << "Most frequent color: "
        << getMostFrequentColor().first << "\n";

    std::cout << "Number of most frequent color: "
        << getMostFrequentColor().second << "\n";
}

int PPMreader::calcualteNumberOfUniqueColors()
{
    std::map<int, int> colorFmap;
    for (int element : imgData)
    {
        colorFmap[element]++;
    }
    return colorFmap.size();
}

std::pair<int, int> PPMreader::getMostFrequentColor()
{
    int mFreq = 0;
    std::map<int, int> colorFmap;
    std::pair<int, int> mFreqColor;
    for (int element : imgData)
    {
        colorFmap[element]++;
    }
    for (const auto& pair : colorFmap)
    {
        if (pair.second >= mFreq)
        {
            mFreq = pair.second;
            mFreqColor = pair;
        }
    }

    return mFreqColor;
}

void PPMreader::printImgData()
{
    Pixel px;
    for (int i = 0; i < imgData.size(); ++i)
    {   
        if ((i + 1) % width == 0)
        {
            std::cout << "\n";
        }
        else
        {
            px.r = imgData[i] >> 16;
            px.g = imgData[i] >> 8;
            px.b = imgData[i];

            std::cout << px.r << " ";
            std::cout << px.g << " ";
            std::cout << px.b << " ";

        }
       
     
        


    }
}
