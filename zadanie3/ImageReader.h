#pragma once
#ifndef _IMAGE_READER_H
#define _IMAGE_READER_H


class ImageReader
{
public: 
	virtual void printImageInfo();
	virtual void printMostFrequentColor();
	virtual int calcualteNumberOfUniqueColors();
};






#endif // !_IMAGE_READER_H
