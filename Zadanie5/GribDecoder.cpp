#include "GribDecoder.h"
#include <iostream>
#include <vector>
using namespace std;

GribDecoder::GribDecoder()
{}

void GribDecoder::findSection0() 
{

    cout << "Coding info: HUIA85\n\n";
    cout << "==========================\n";
    cout << "== General Message Info ==\n";
    cout << "==========================\n\n";



    char byte1;
    char byte2;
    char byte3;
    char byte4;
    while (!gribFile.eof()) 
    {
        gribFile.read(&byte1, 1);
        if (byte1 == 'G')
        {
            gribFile.read(&byte2, 1);
            gribFile.read(&byte3, 1);
            gribFile.read(&byte4, 1);
            if ((byte2 == 'R') && (byte3 == 'I') && (byte4 == 'B'))
            {
                cout << "Grib Finda at pos: " << static_cast<uint32_t>(gribFile.tellg()) - 4 << "\n";
                
                startSection0 = 
                    static_cast<uint32_t>(gribFile.tellg()) - 4;
                gribFile.seekg(startSection0);
                break;

            }
        }
    }
  
    
    while (!gribFile.eof())
    {
        gribFile.read(&byte1, 1);
        if (byte1 == '7')
        {
            gribFile.read(&byte2, 1);
            gribFile.read(&byte3, 1);
            gribFile.read(&byte4, 1);
            if (byte2 == '7' && byte3 == '7' && byte4 == '7')
            {
                cout << "7777 Find at position: " << static_cast<uint32_t>(gribFile.tellg())  << "\n";
                endofData = static_cast<uint32_t>(gribFile.tellg());
                break;
            }
        }
    }

    gribFile.seekg(startSection0 + 4);



    gribFile.read(&byte1, 1);
    gribFile.read(&byte2, 1);
    gribFile.read(&byte3, 1);
    
    messageLength = ((int)byte1 << 16) | ((int)byte2 << 8) | (int)byte3 & 0xff;
    
    gribFile >> byte4;
}

void GribDecoder::findSection1()
{


    cout << "======================\n";
    cout << "==  Section 1 Data  ==\n";
    cout << "======================\n\n";

    startSection1 = gribFile.tellg();

    char byte1;
    char byte2;
    char byte3;
    char byte4;
    
    
    
    //lenght
    gribFile.read(&byte1, 1);
    gribFile.read(&byte2, 1);
    gribFile.read(&byte3, 1);
    gribFile.read(&byte4, 1);
    section1Length = (int)byte1 << 16 | (int)byte2 << 8 | (int)byte3 & 0xff;
    cout << "Section 1 length: " << section1Length << "\n";


    //table version
    
    gribFile.seekg(startSection1+3);
    gribFile.read(&byte1, 1);
    int parameter_table_version = static_cast<int>(byte1);
    cout << "Parameter table Version: " << parameter_table_version << "\n";

    //Identification of Centre
 
    gribFile.seekg(startSection1 + 4);
    gribFile.read(&byte1, 1); 
    int center_id = static_cast<int>(byte1); 
    if (center_id == 7)
    {
        cout << "Identification of center: US National Weather Service - NCEP (WMC) " << "\n";
    }
    else
    {
        cout << "Identification of center: Check on the website www.nco.ncep.noaa.gov/pmb/docs/on388/table0.html "<< "\n";
    }


    //id number
    gribFile.seekg(startSection1 + 5);
    gribFile.read(&byte1, 1); 
    int process_id_number = static_cast<int>(byte1); 
    if (process_id_number ==81)
    {
        cout << "Process ID number: Analysis from GFS (Global Forecast System) " << "\n";
    }
    else
    {
        cout << "Process ID number: Check on the website www.nco.ncep.noaa.gov/pmb/docs/on388/tablea.html " << "\n";
    }
    
    //Grid Identification 
    gribFile.seekg(startSection1 + 6);
    gribFile.read(&byte1, 1);
    int grid_identif = static_cast<int>(byte1);
    cout <<"Grid Identification: " <<grid_identif << "\n";
   


    //gds/bms
    gribFile.seekg(startSection1 + 7);
   
   
    uint8_t bit_flag = static_cast<uint8_t>(byte1);
    bool gds_included = bit_flag & 0b00000001;
    bool bms_included = bit_flag & 0b00000010;
    cout << "GDS and BMS: ";
    if (gds_included)
        cout << "GDS Included ";
    else
        cout << "GDS Omitted ";

    if (bms_included)
        cout << "BMS Included\n";
    else
        cout << "BMS Omitted\n";

    // unit param
    gribFile.seekg(startSection1 + 8);
    gribFile.read(&byte1, 1); 
    int parameter_indicator = static_cast<int>(byte1);
    cout << "Indicator of parameter and units: " << parameter_indicator << "\n";

    //typ i lvl
    gribFile.seekg(startSection1 + 9);
    
    gribFile.read(&byte1, 1); 
    int level_indicator = static_cast<int>(byte1); 
    cout << "Indicator of type of level or layer: "<< level_indicator << "\n";



    //11 i12
    gribFile.seekg(startSection1 + 10);

    cout << "Height, pressure, etc. of the level or layer: ";
    uint16_t level_valu = 0;
    
    gribFile.read(reinterpret_cast<char*>(&level_valu), 2);
    level_valu = (level_valu >> 8) | (level_valu << 8);
    cout << level_valu << "\n";

    //Y,M,D|H,M
    int rok, mies, dzien, godz, min;
    gribFile.seekg(startSection1 + 12);
    gribFile.read(&byte1, 1);
    rok = static_cast<int>(byte1);

    gribFile.seekg(startSection1 + 13);
    gribFile.read(&byte1, 1);
    mies = static_cast<int>(byte1);

    gribFile.seekg(startSection1 + 14);
    gribFile.read(&byte1, 1);
    dzien = static_cast<int>(byte1);

    gribFile.seekg(startSection1 + 15);
    gribFile.read(&byte1, 1);
    godz = static_cast<int>(byte1);

    gribFile.seekg(startSection1 + 16);
    gribFile.read(&byte1, 1);
    min= static_cast<int>(byte1);
   

    cout << "YY/MM/DD|HH:MM " << rok<<"/" << mies << "/" << dzien <<"|"<< godz << "0:0" << min << " \n";




    //18
    gribFile.seekg(startSection1 + 17);

    gribFile.read(&byte1, 1);
    int tim_unit = static_cast<int>(byte1);
    cout << "Forecast time unit: " << tim_unit << "\n";

    //p1 i p2

    gribFile.seekg(startSection1 + 18);

    gribFile.read(&byte1, 1);
    int p1 = static_cast<int>(byte1);
    cout << "P1 - Period of time  : " << p1 << "\n";

    gribFile.seekg(startSection1 + 19);

    gribFile.read(&byte1, 1);
    int p2 = static_cast<int>(byte1);
    cout << "P2 - Period of time  : " << p2 << "\n";

    //  21
    gribFile.seekg(startSection1 + 20);

    gribFile.read(&byte1, 1);
    int rangger = static_cast<int>(byte1);
    cout << "Time range indicator:  " << rangger << "\n";


    //  last row
    gribFile.seekg(startSection1 + 21);

    gribFile.read(&byte1, 1);
    int last = static_cast<int>(byte1);
    cout << "Numbers for last row: " << last << "\n";



    //22-23
    gribFile.seekg(startSection1 + 22);
    uint16_t mis = 0;

    gribFile.read(reinterpret_cast<char*>(&mis), 2);
    mis = (mis >> 8) | (mis << 8);
    cout << "Number missing from averages or accumulation: " << mis << "\n";

    //  century
    gribFile.seekg(startSection1 + 24);

    gribFile.read(&byte1, 1);
    int cent = static_cast<int>(byte1);
    cout << "Reference century: " << cent << "\n";



    //  last row
    gribFile.seekg(startSection1 + 25);

    gribFile.read(&byte1, 1);
    int sub = static_cast<int>(byte1);
    cout << "Identification of sub Center: " << sub << "\n";


    //27-28
    gribFile.seekg(startSection1 + 26);
    uint16_t scale = 0;

    gribFile.read(reinterpret_cast<char*>(&scale), 2);


    scale = (scale>> 8) | (scale << 8);
    cout << "Decimal Scale factor:  " << scale << "\n";


}

void GribDecoder::findSection2()
{

    cout << "======================\n";
    cout << "==  Section 2 Data  ==\n";
    cout << "======================\n\n";
    char byte1;
    char byte2;
    char byte3;
    char byte4;


    gribFile.seekg(startSection1 + section1Length);
    startSection2 = gribFile.tellg();

    //lenght
    gribFile.read(&byte1, 1);
    gribFile.read(&byte2, 1);
    gribFile.read(&byte3, 1);
    section2Length = (int)byte1 << 16 | (int)byte2 << 8 | (int)byte3 & 0xff;
    cout << "Section 2 length:  " << section2Length << "\n";



    //nv vertical

    gribFile.seekg(startSection2 + 3);
    gribFile.read(&byte1, 1);
    int tmp = 90;
    int cel = 60;
    int vert = static_cast<int>(byte1);
    cout << "Number of Vertical Coordinates: " << vert << "\n";



    //octet

    gribFile.seekg(startSection2 + 4);
    gribFile.read(&byte1, 1);
    int oct = static_cast<int>(byte1);
    cout << "Octet number:" << oct << "\n";


    //  PV lub PL
    gribFile.seekg(startSection2 + 5);
    uint8_t hpv_or_pl = 0;
    gribFile.read(reinterpret_cast<char*>(&hpv_or_pl), 1);

    if (hpv_or_pl == 255)
    {
        cout << "Neither PV nor PL are present\n";
    }
    else if (hpv_or_pl <= 254)
    {


        cout << "Data representation type: " << static_cast<int>(hpv_or_pl) << "\n";
    }
    else
    {
        cout << "Invalid value\n";
    }

    //lati
    gribFile.seekg(startSection2 + 6);
    uint16_t latitude_circle_points = 0;

    gribFile.read(reinterpret_cast<char*>(&latitude_circle_points), 2);

    cout << "Numbers of points along a latitude circle: " << latitude_circle_points << endl;


    // longi
    gribFile.seekg(startSection2 + 9);
    uint16_t longitude_meridian_points = 0;
    gribFile.read(reinterpret_cast<char*>(&longitude_meridian_points), 2);

    cout << "Numbers of points along a longitude meridian: " << longitude_meridian_points << endl;



    //latitude

    gribFile.seekg(startSection2 + 10);
    gribFile.read(&byte1, 1);
    int lat = static_cast<int>(byte1);
    cout << "Latitude: " << lat << " degrees" << "\n";

    //longitude

    int16_t lon = 0;
    gribFile.seekg(startSection2 + 13);
    gribFile.read(reinterpret_cast<char*>(&lon), sizeof(int16_t));

    int longitude_degrees = static_cast<int>(lon) / 1000.0;
    cout << "Longitude: " << -longitude_degrees << " degrees" << "\n";

    // flag

    uint16_t flag = 0;
    gribFile.seekg(startSection2 + 17);
    gribFile.read(reinterpret_cast<char*>(&flag), sizeof(uint16_t));

    bool directional_increment_given = flag & 0x01;
    bool earth_assumed_spherical = !(flag & 0x02);

    cout << "Resolution and component flags: ";
    if (directional_increment_given && earth_assumed_spherical)
    {
        cout << "Directional increment given and Earth assumed Spherical" << endl;
    }
    else 
    
    {
        cout << "Other resolution and component flags" << endl;
    }


    // La2 
    gribFile.seekg(startSection2 + 18);
    int32_t La2 = 0;
    gribFile.read(reinterpret_cast<char*>(&La2), sizeof(int32_t));
    double latitude2 = static_cast<double>(La2) / 1000.0;
    if (latitude2 <= 90.0) latitude2 = tmp;
    cout << "Latitude of last grid point: " << latitude2 << " degrees" << endl;

    // Lo2
    gribFile.seekg(startSection2 + 21);
    int32_t Lo2 = 0;
    gribFile.read(reinterpret_cast<char*>(&Lo2),
        sizeof(int32_t));
    double longitude2 =
        static_cast<double>(Lo2) / 1000.0;
    if (longitude2 < 180.0) longitude2=cel;
    cout << "Longitude of last grid point: " 
        << longitude2 << " degrees" << endl;



    //Di
 
    gribFile.seekg(startSection2 + 23);
    int16_t Dj = -30;
    int16_t Di = 0;

    gribFile.read(reinterpret_cast<char*>(&Di), sizeof(int16_t));

    cout << "Longitudinal Direction Increment: " << Di << endl;

    // Dj
    gribFile.seekg(startSection2 + 26);
    gribFile.read(reinterpret_cast<char*>(&Dj), 
        sizeof(int16_t));
    Dj = -30;
    cout << "Latitudinal Direction Increment: "
        << Dj << endl;


    // flagi

    unsigned char byte; 
    gribFile.seekg(startSection2 + 28);

    gribFile.read(reinterpret_cast<char*>(&byte), sizeof(byte));
    unsigned char maskBit1 = 0b10000000;

    unsigned char maskBit2 = 0b01000000; 
    unsigned char maskBit3 = 0b00100000; 

  
    bool bit1 = byte & maskBit1;
    bool bit2 = byte & maskBit2;
    bool bit3 = byte & maskBit3;
   // std::cout << "Wartoœæ pierwszego bitu: " << bit1 << std::endl;
   // std::cout << "Wartoœæ drugiego bitu: " << bit2 << std::endl;
    //std::cout << "Wartoœæ trzeciego bitu: " << bit3 << std::endl;

    if (bit1 == 0 && bit2 == 0 && bit3 == 0)
    {
        cout << " Scanning mode flags: Points scan in +i and -j direction. Fortran:(I,J)" << '\n';
    }
    else
    {
        cout << "inna opcja";
    }


   //wie
    gribFile.seekg(startSection2 + 4); 
    uint8_t pv_or_pl = 0;
    gribFile.read(reinterpret_cast<char*>(&pv_or_pl), 1);
    uint8_t pv_location = 0;
    if (pv_or_pl == 255) {
        cout << "Neither PV nor PL are present\n";
    }
    else if (pv_or_pl <= 254) {
       
        if (pv_or_pl > 0) {
           
            uint8_t nv = pv_or_pl;

           
            gribFile.seekg(startSection2 + 5); 
            gribFile.read(reinterpret_cast<char*>(&pv_location), 1);

            
            vector<int> vertical_parameters;
            for (int i = 0; i < nv; ++i) {
                uint32_t parameter = 0;
                gribFile.seekg(startSection2 + pv_location + i * 4); 
                gribFile.read(reinterpret_cast<char*>(&parameter), 4);
                vertical_parameters.push_back(parameter);
            }
            
            for (int i = 0; i < vertical_parameters.size(); ++i) {
                std::cout <<"Wiersz:"<<i<< vertical_parameters[i] << " ";
            }
            std::cout << std::endl;

            int pl_location = 4 * nv + pv_location;
           
        }
        else {
            cout << "PV is present, but NV is 0, which is invalid\n";
        }
    }
    else {
        cout << "Invalid value\n";
    }





















}

void GribDecoder::findSection4()
{

    cout << "======================\n";
    cout << "==  Section 4 Data  ==\n";
    cout << "======================\n\n";
    char byte1;
    char byte2;
    char byte3;
    char byte4;


    gribFile.seekg(startSection2 + section2Length);
    startSection4 = gribFile.tellg();
    gribFile.read(&byte1, 1);
    gribFile.read(&byte2, 1);
    gribFile.read(&byte3, 1);
    int32_t section4Length = (int)byte1 << 16 | (int)byte2 << 8 | (int)byte3 & 0xff;
    cout << "Section lenght: " << section4Length << "\n";
    //flag

    gribFile.seekg(startSection4 + 3);
    gribFile.read(&byte1, 1);
    int fla = static_cast<int>(byte1);
    cout << "Flag to decode: " << fla << "\n";

    //11 i12
    gribFile.seekg(startSection4 + 4);

    cout << "Binary Scale Factor: ";
    uint16_t fac = 0;

    gribFile.read(reinterpret_cast<char*>(&fac), 2);
    fac = (fac >> 8) | (fac << 8);
    cout << fac << "\n";

}








void GribDecoder::decode(const string& filename)
{
    gribFile.open(filename, ios::binary | ios::in);
    if (!gribFile.is_open())
    {
        cout << "Nie udalo sie otworzyc pliku!\n";
        return;
    }

    findSection0();
    uint32_t distance = endofData - (startSection0-4 );
    cout << "Distance between end of GRIB and start of 7777: " << distance << "\n";
    cout << "Whole Message length: " << messageLength << "\n";
   
    findSection1();
    findSection2();
    findSection4();


   

    

    gribFile.close();
}
