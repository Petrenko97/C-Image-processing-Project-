#include "ppm.h"
#include <iostream>
#include <fstream> //gia ifstream
typedef unsigned int ui;
using namespace std;
#include <string>
namespace imaging
{
	float * ReadPPM(const char * filename, int * w, int * h) //den anhkei se klasei ara de bazw ::
	{
		ifstream Readtxt = ifstream(filename, ios_base::in | ios_base::binary);
		if (Readtxt.good()) {                         //an exei anoiksei kala to txt 
			string header;                           //header
			Readtxt >> header;
			if (header !=  "P6") {
				cout << "Wrong Header" << endl;
				return nullptr;
			}
			int width;                                 //width
			Readtxt >> width;
			if (width <= 0) {
				cout << "Wrong width" << endl;
				return nullptr;
			}
			int height;                                //height
			Readtxt >> height;
			if (height <= 0) {
				cout << "Wrong height" << endl;
				return nullptr;
			}
			int Color_depth;
			Readtxt >> Color_depth;
			if (Color_depth != 255) {
				cout << "Color depth" << endl;
				return nullptr;                           //Color Depth
			}
			Readtxt.get();                                     //epeidh einai byte gia na allaksei grammh prepei na diabasei 
			

			*w = width;
			*h = height;

			float * data = new float[width*height * 3];
			unsigned char color;

				for (ui i = 0; i < width*height * 3; i++) {
					Readtxt.read((char *)&color, 1);                                //Readtxt.read(&color,1) kai ta bazw 1-1  /255 unsigned char color;   Readtxt.close() //den allazei grammh 
					*(data+i) = ((float)color) /  255;
				}
				Readtxt.close();
				return data;
		}
		else
		{
			cout << "file didnt open";
				return nullptr;

		}


	}

	bool WritePPM(const float * data, int w, int h, const char * filename) {

		if (data == nullptr) return false;
		ofstream Writetxt = ofstream(filename, ios_base::out | ios_base::binary);
		if (Writetxt.good()) {                         //an exei anoiksei kala to txt
			string header="P6";                           //header
			Writetxt << header << endl;
			int width=w;                                 //width
			Writetxt << width << endl;
			int height=h;                                //height
			Writetxt << height << endl;
			int Color_depth=255;                          //header
			Writetxt << Color_depth << endl;
			unsigned char color;
			for (ui i = 0; i < width*height * 3; i++) {
				color = (*data) * 255;
				data++;
				Writetxt.write((char *)&color, 1);
			}
			Writetxt.close();
			return true;
		}
		else
		{
			return false;
		}

	}

















}