#include "Filter.h"
#include "Image.h"
#include "Array.h"
using namespace imaging;

FilterBlur::FilterBlur(int N) :Array(N,N) {
	this->N = N;
	for (ui i = 0; i < N*N; i++) {
			buffer[i]=1.0/(N*N);
		}
}

Image FilterBlur::operator << (const Image &image) {
	Image Limage(image);
	for (ui i = 0; i < Limage.getWidth(); i++) { //1
		for (ui j = 0; j < Limage.getHeight(); j++) {//2
			Color newPixel(0,0,0);//pixel exei 0 kai meta kanoume thn a8roistikh praksh 
			for (int m = -N/2; m <= N/2; m++) { //3
				for (int n = -N/2; n <= N/2; n++) { //4
					if (i + m >= 0 && j + n >= 0 && i + m < Limage.getWidth() && j + n < Limage.getHeight()) { //in boundries
						 newPixel = newPixel+ getItem(m + N / 2, n + N / 2)*image.getItem(i + m, j + n);
					}
					else { //the pixel from the unfiltered photo
						newPixel= image.getItem(i, j);
					}
				}//4
			}//3 
			if (newPixel.g > 1)newPixel.g = 1.0;
			if (newPixel.r > 1)newPixel.r = 1.0;
			if (newPixel.b > 1)newPixel.b = 1.0;
			if (newPixel.g < 0)newPixel.g = 0.0;
			if (newPixel.r < 0)newPixel.r = 0.0;
			if (newPixel.b < 0)newPixel.b = 0.0;
			Limage.setItem(i, j, newPixel);
		}//2
	}//1
	return Limage;
}