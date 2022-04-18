#include "Image.h"
#include "Color.h"
#include "ppm.h"
typedef unsigned int ui;
#include <iostream>
using namespace std;

namespace imaging

{
	ui width;
	ui height;

	Color * Image::getRawDataPtr() {

		return buffer;
	}


	Image::Image() { //default constructor 
		width = 0;
		height = 0;
		buffer = nullptr;

	}


	Image::Image(unsigned int width, unsigned int height) {

		this->width = width;
		this->height = height;
		buffer = new Color[width*height];
	}

	Image::Image(unsigned int width, unsigned int height, const Color * data_ptr) {   //copy dataptr to buffer
		this->width = width;
		this->height = height;
		buffer = new Color[width*height];

		for (ui i = 0; i < width*height; i++) {
			buffer[i] = data_ptr[i];
		}

	}

	Image::~Image() {

		delete[]buffer;
	}



	Color Image::getPixel(ui x, ui y) const {

		if (x < width && y < height) {                  //if its in the boundries

			return buffer[y*width + x];
		}
		else {                                          //return black color

			return Color(0, 0, 0);
		}
	}

	void Image::setPixel(ui x, ui y, Color & value) {

		if (x < width && y < height) buffer[y*width + x] = value;
	}


	void Image::setData(const Color * & data_ptr)       //data ptr anafora se deikth 
	{

		if (buffer != nullptr) {
			for (ui i = 0; i < width*height; i++) {
				buffer[i] = data_ptr[i];
			}
		}

	}

	Image::Image(const Image &src) {                     //copy constructor anafora ston allo constructor mesw src
		width = src.width;
		height = src.height;
		buffer = new Color[width*height];
		for (ui i = 0; i < width*height; i++) {
			buffer[i] = src.buffer[i];                    //desmeuw neo xwro se periptwsh pou diagrafei to allo antikeimeno 
		}

	}

	Image & Image::operator= (const Image & right) {    //kos=ios;    //image & tupos epistrofhs panta mprosta

		if (this != &right)                                 //this deikths ston eauto tou kos,right deksia ths ana8eshs o ios  //an this diaforo dieu8 mnhmhs tou right an kos=kos
		{
			width = right.width;
			height = right.height;
			delete[] buffer;
				buffer = new Color[width*height];
			for (ui i = 0; i < width*height; i++) {
				buffer[i] = right.buffer[i];                    //desmeuw neo xwro se periptwsh pou diagrafei to allo antikeimeno 
			}
			
		}
		return *this;


	}

	bool Image::load(const std::string & filename, const std::string & format){        //format=ppm  gtr.ppm
		int w;
		int h;
		
		for(ui i=3;i<=1;i--)															//If its not ppm false
			if ((filename[filename.length() - i]) != format[i - 3])
			{
				cout << "false format" << endl;
				return false;
			}

		float *data = ReadPPM(filename.c_str(), &w, &h);

			if (data == nullptr) return false;
			delete []	buffer;
			buffer = new Color[w*h];
			width = w;
			height = h;
				for (ui i=0; i < width*height;i++){
					buffer[i] = Color(data[3 * i], data[3 * i + 1], data[3 * i + 2]);

					}
				delete[] data;
				return true;
	
	}

	bool Image::save(const std::string & filename, const std::string & format) {
		for (ui i = 3; i <= 1; i--)															//If its not ppm false
			if ((filename[filename.length() - i]) != format[i - 3])
			{
				cout << "false format" << endl;
				return false;
			}
			if (buffer == nullptr) return false;
			float * data = new float[width*height * 3];
			ui j = 0;
			for (ui i = 0; i < width*height; i++) {
				data[j] = buffer[i].r;
				j++;
				data[j] = buffer[i].g;
				j++;
				data[j] = buffer[i].b;
				j++;
			}
			WritePPM(data, width, height, filename.c_str());
			delete [] data;
			return true;
		}

}