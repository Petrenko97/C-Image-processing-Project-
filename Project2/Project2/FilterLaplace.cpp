#include "Vec3.h"
#include "Filter.h"
#include "Image.h"
using namespace imaging;

FilterLaplace::FilterLaplace() :FilterBlur(3) {
	buffer[0] = 0, buffer[1] = 1, buffer[2] = 0, buffer[3] = 1, buffer[4] = -4, buffer[5] = 1, buffer[6] = 0, buffer[7] = 1, buffer[8] = 0;
}

Image FilterLaplace::operator <<(const Image &image)//de mporw na allaksw thn eikona
{
	Image Limage(image);
	for (ui i = 0; i < Limage.getWidth(); i++) { //1
		for (ui j = 0; j < Limage.getHeight(); j++) {//2
			Color newPixel(0, 0, 0);//pixel exei 0 kai meta kanoume thn a8roistikh praksh 
			for (int m = -1; m <= 1; m++) { //3
				for (int n = -1; n <= 1; n++) { //4
					if (i + m >= 0 && j + n >= 0 && i + m < Limage.getWidth() && j + n < Limage.getHeight()) { //in boundries
						newPixel += getItem(m + 1, n + 1)*image.getItem(i + m, j + n);
					}
				}//4
			}//3 
			Color min = newPixel.clampToUpperBound(1.0);
			Color max = min.clampToLowerBound(0);
			Limage.setItem(i, j, max);
		}//2
	}//1

	return Limage;

}