#include "PGMreader.h"
#include <cstring>
#include<sstream>
#include<map>

PGMreader::PGMreader(std::string imgPath)
{

	imgFile.open(imgPath, std::ios::in);
	if (imgFile.good())
	{
		std::string magicNum;
		std::string line;
		std::string com;
		
		int pxValue;

		try
		{
			getline(imgFile, magicNum);
			if (magicNum == "P2")

			{
				std::stringstream ss(line);



				while (getline(imgFile, line))
				{
					if (!line.empty() && line[0] != '#')

					{
						if (width != 0 && height != 0)
						{
							ss.clear();
							ss.str(line);

							while (ss >> pxValue)

							{
								imgData.push_back(pxValue);


							}

						}
						else
						{
							ss.clear();
							ss.str(line);
							ss >> width >> height;

							getline(imgFile, line);
							ss.clear();
							ss.str(line);
							ss >> greyLvl;
						}
					}
					else
					{
						com += line + "\n";
					}
				}



			}
			else
			{
				std::cout << "File is other tipe than PGM \n";
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << "\n";
		}
		imgFile.close();
	
	
	}
	else
	{
		std::cout << "Cannot open the file "
			<< imgPath << "\n";
	}


}

void PGMreader::printImageInfo()
{

	std::cout << "Width j height :" << width << "j"
		<< height << "\n";

	std::cout << "Number of unique colors: "
		<< calcualteNumberOfUniqueColors() << "\n";

	std::cout << "Most frequent color: "
		<< getMostFrequentColor().first << "\n";

	std::cout << "Number of most frequent color: "
		<< getMostFrequentColor().second << "\n";

}

void PGMreader::printMostFrequentColor()
{

	std::cout << "Most frequent color: "
		<< getMostFrequentColor().first << "\n";

	std::cout << "Number of most frequent color: "
		<< getMostFrequentColor().second << "\n";

}

int PGMreader::calcualteNumberOfUniqueColors()
{
	std::map<int, int> colorFmap;
	for (int element : imgData)
	{
		colorFmap[element]++;
	}
	return colorFmap.size();
}

std::pair<int, int> PGMreader::getMostFrequentColor()
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

void PGMreader::printImgData()
{
	for (int i = 0; i < imgData.size(); ++i)
	{
		std::cout << imgData[i] << " ";
		if ((i + 1) % width == 0) std::cout << "\n";


	}
}

void PGMreader::rotationImg()
{
	







}


