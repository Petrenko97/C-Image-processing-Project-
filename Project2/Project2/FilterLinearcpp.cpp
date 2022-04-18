#include "Filter.h"
#include "Image.h"
using namespace imaging;

FilterLinear::FilterLinear(Color a, Color c) {
	this->a = a;
	this->c = c;
}

FilterLinear::FilterLinear(const FilterLinear & src) {
	this->a = src.a;
	this->c = src.c;
}


Image FilterLinear::operator <<(const Image &image)//de mporw na allaksw thn eikona
{
	Image Limage(image);
	for (ui i = 0;i<Limage.getWidth();i++) {
		for (ui j = 0; j < Limage.getHeight();j++) {
			Color color = Limage.getItem(i, j);
			color = a*color + c;
			if (color.g > 1)color.g = 1.0;
			if (color.r > 1)color.r = 1.0;
			if (color.b > 1)color.b = 1.0;
			if (color.g < 0)color.g = 0.0;
			if (color.r < 0)color.r = 0.0;
			if (color.b < 0)color.b = 0.0;

			Limage.setItem(i, j, color);
		}
	}
	return Limage;

}