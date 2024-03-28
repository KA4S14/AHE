#pragma once
#ifndef _PBMREADER_H_
#define _PBMREADER_H_

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "ImageReader.h"


class PBMreader : public ImageReader
{
public: 

	PBMreader(std::string imgPath);

	void printImageInfo() override;
	void printMostFrequentColor() override;
	int calcualteNumberOfUniqueColors() override;



	std::pair<int, int> getMostFrequentColor();
	void printImgData();


private:

	std::fstream imgFile;
	std::vector<int> imgData;

	int width=0;
	int height=0;



};


#endif // !_PBMREADER_H_
