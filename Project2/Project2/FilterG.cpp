#include <stdio.h>      
#include <math.h>       
#include "Filter.h"
#include "Image.h"
using namespace imaging;

FilterG::FilterG(float g) {
	this->g = g;
}

FilterG::FilterG(const FilterG & src) {
	this->g = src.g;
}

Image FilterG::operator <<(const Image &image)//de mporw na allaksw thn eikona
{
	Image Limage(image);
	for (ui i = 0; i<Limage.getWidth(); i++) {
		for (ui j = 0; j < Limage.getHeight(); j++) {
			Color color = Limage.getItem(i, j);
			color.r = pow(color.r, g);
			color.g = pow(color.g, g);
			color.b = pow(color.b, g);
			Limage.setItem(i, j, color);
		}
	}
	return Limage;

}