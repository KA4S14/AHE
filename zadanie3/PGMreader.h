#ifndef _PGMREADER_H_
#define _PGMREADER_H_


#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "ImageReader.h"

class PGMreader : ImageReader
{

public:

	PGMreader(std::string imgPath);

	void printImageInfo() override;
	void printMostFrequentColor() override;
	int calcualteNumberOfUniqueColors() override;

	




	std::pair<int, int> getMostFrequentColor();
	void printImgData();
	void rotationImg();


private:

	std::fstream imgFile;
	std::vector<int> imgData;

	int width = 0;
	int height = 0;
	int greyLvl=0;



};





























#endif // !_PGMREADER_H_

