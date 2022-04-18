#pragma once

#include <vector>
using namespace std;

typedef unsigned int ui;

namespace math
{
	template <typename T>
	class Array
	{
	protected:
		ui width;
		ui height;
		vector<T>  buffer;
	public:
		Array(ui width, ui height) :buffer(width*height) {
			this->width = width;
			this->height = height;
		}

		Array() :buffer(0) {
			width = 0;
			height = 0;
		}
		Array(ui width, ui height, const T* data_ptr) :buffer(width*height) {
			this->width = width;
			this->height = height;
			for (ui i = 0; i < width*height; i++) {
				buffer[i] = data_ptr[i];
			}
		}
		Array(const Array <T> &src) :buffer(src.width*src.height) {                     //copy constructor anafora ston allo constructor mesw src
			width = src.width;
			height = src.height;
			for (ui i = 0; i < width*height; i++) {
				buffer[i] = src.buffer[i];                    //desmeuw neo xwro se periptwsh pou diagrafei to allo antikeimeno 
			}

		}

		void setData(const T * & data_ptr)       //data ptr anafora se deikth 
		{

			if (buffer.size != 0) {
				for (ui i = 0; i < width*height; i++) {
					buffer[i] = data_ptr[i];
				}
			}

		}

		Array <T> operator= (const Array <T> & right) {    //kos=ios;    //image & tupos epistrofhs panta mprosta

			if (this != &right)                                 //this deikths ston eauto tou kos,right deksia ths ana8eshs o ios  //an this diaforo dieu8 mnhmhs tou right an kos=kos
			{
				width = right.width;
				height = right.height;
				buffer.resize(right.width*right.height);
				for (ui i = 0; i < width*height; i++) {
					buffer[i] = right.buffer[i];                    //desmeuw neo xwro se periptwsh pou diagrafei to allo antikeimeno 
				}

			}
			return *this;
		}

		void setItem(ui x, ui y, T & value) {

			if (x < width && y < height) buffer[y*width + x] = value;
		}
		const unsigned int getWidth() const { return width; }

		const unsigned int getHeight() const { return height; }

		T getItem(ui x, ui y) const {

			if (x < width && y < height) {                  //if its in the boundries

				return buffer[y*width + x];
			}
			else {                                          //return black color

				return T();
			}
		}



		T * getRawDataPtr() {

			return &buffer[0];
		}

		T & operator()(ui i, ui j) {
			if (i < width && j < height)
			{
				return buffer[j*width + i];
			}
			else {
				return buffer[0];

			}

		}
	};



}

