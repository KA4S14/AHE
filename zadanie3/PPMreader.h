#ifndef _PPMREADER_H_
#define _PPMREADER_H_


#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "ImageReader.h"

struct Pixel
{
	char r;
	char g;
	char b;
};


class PPMreader : ImageReader
{

public:

	PPMreader(std::string imgPath);

	void printImageInfo() override;
	void printMostFrequentColor() override;
	int calcualteNumberOfUniqueColors() override;



	std::pair<int, int> getMostFrequentColor();
	void printImgData();


private:

	std::fstream imgFile;
	std::vector<int> imgData;

	int width = 0;
	int height = 0;
	int depth = 0;



};






#endif // !_PPMREADER_H_