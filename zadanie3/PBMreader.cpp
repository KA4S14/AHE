#include "PBMreader.h"
#include <cstring>
#include<sstream>

PBMreader::PBMreader(std::string imgPath)
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
			if (magicNum == "P1") 

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
				std::cout << "File is other type than PBM \n";
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
			<< imgPath<< "\n";
	}

}

void PBMreader::printImageInfo()
{
	
	std::cout << "Width x height :" << width << "x"
		<< height << "\n";

	std::cout << "Number of unique colors: "
		<< calcualteNumberOfUniqueColors() << "\n";

	std::cout << "Most frequent color: "
		<< getMostFrequentColor().first<<"\n";

	std::cout << "Number of most frequent color: " 
		<< getMostFrequentColor().second << "\n";

}

void PBMreader::printMostFrequentColor()
{
	std::cout << "Most frequent color: "
		<< getMostFrequentColor().first << "\n";

	std::cout << "Number of most frequent color: "
		<< getMostFrequentColor().second << "\n";
}

int PBMreader::calcualteNumberOfUniqueColors()
{
	return 2;
}

std::pair<int, int> PBMreader::getMostFrequentColor()
{	// what, how many
	std::pair<int, int> wh;

	int zeroCounter = 0;
	int oneCounter = 0;

	for (int element : imgData)
	{
		if (element == 0)
		{
			
			zeroCounter++;
		}
		else
		{
			oneCounter++;
		}
	}

	if (zeroCounter > oneCounter)
	{
		wh.first = 0;
		wh.second = zeroCounter;
	}
	else
	{
		wh.first = 1;
		wh.second = oneCounter;
	}



	return wh;
}

void PBMreader::printImgData()
{
	for (int i = 0; i < imgData.size(); ++i)
	{
		std::cout << imgData[i] << " ";
		if ((i + 1) % width == 0) std::cout << "\n";


	}

}
