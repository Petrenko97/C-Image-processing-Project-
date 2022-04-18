#include <iostream>
#include "Color.h"
#include "Image.h"
typedef unsigned int ui;
using namespace std;
using namespace imaging;

int main(int argc,char *argv[]) {



	string filename;
	if (argc == 1) { //mege8os enotlhs 
		cout << "file name of the Image to load: ";  //den exw to orisma dld onoma arxeiou
		cin >> filename;
	}
	if(argc==2) {
	    filename= argv[1];
	}
	Image * img = new Image();
	bool x=img->load(filename, "ppm");
	if (x == true) {
	ui w = img->getWidth();
	ui h = img->getHeight();
	for (ui i = 0; i < w;i++) {
		for (ui j = 0; j < h; j++) {
			Color p;
			p = img->getPixel(i, j);
			Color n = Color(1, 1, 1) - p;
			img->setPixel(i, j, n);
		
		}


	}


	cout << "Image dimensions are: " << w << "x" << h << endl;
	string outfilename = filename.replace(filename.length() - 4, 8, "_neg.ppm");
	img->save(outfilename, "ppm");



	}

	delete img;
	return 0;
}