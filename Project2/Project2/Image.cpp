#include "Image.h"
#include "Vec3.h"
#include "ppm.h"
#include "Array.h"
typedef unsigned int ui;
#include <iostream>
using namespace std;

using namespace math;
namespace imaging

{

	Image::Image():Array() { //default constructor 
	}


	Image::Image(unsigned int width, unsigned int height):Array(width,height) {
	}

	Image::Image(unsigned int width, unsigned int height, const Color * data_ptr):Array(width,height,data_ptr) {   //copy dataptr to buffer
	}

	Image::Image(const Image &src):Array(src) {                     //copy constructor anafora ston allo constructor mesw src
	}

	Image & Image::operator= (const Image & right) {    //kos=ios;    //image & tupos epistrofhs panta mprosta
		if (&right != this) {
			Array::operator=(right);
		}
		return *this;
	}

	bool Image::load(const std::string & filename, const std::string & format){        //format=ppm  gtr.ppm
		int w;
		int h;
		
		for (ui i = 3; i <= 1; i--) {															//If its not ppm false
			if ((filename[filename.length() - i]) != format[i - 3])
			{
				cout << "false format" << endl;
				return false;
			}
		}
		float *data = ReadPPM(filename.c_str(), &w, &h);

			if (data == nullptr) return false;
			buffer.resize(w*h);
			width = w;
			height = h;
				for (ui i=0; i < width*height;i++){
					buffer[i] = Color(data[3 * i], data[3 * i + 1], data[3 * i + 2]);

					}
				delete[] data;
				return true;
	
	}

	bool Image::save(const std::string & filename, const std::string & format) {
		for (ui i = 3; i <= 1; i--) {														//If its not ppm false
			if ((filename[filename.length() - i]) != format[i - 3])
			{
				cout << "false format" << endl;
				return false;
			}
		}
			if (buffer.size()==0) return false;
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