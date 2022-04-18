#include <iostream>
#include "Array.h"
#include "Image.h"
#include "Filter.h"
#include <stdio.h>
typedef unsigned int ui;
using namespace std;
using namespace imaging;

int main(int argc, char *argv[]) {
	string filename = "null";
	/*	int fileSpot = 0;
	for (ui i = 0; filename !="\n" ; i++) {
	fileSpot++;
	} */
	if (argc < 4) {
		cout << "filter dont exist !!";
		return 0;
	}
	filename = argv[argc - 1];
	Image  img;
	bool x = img.load(filename, "ppm");
	Color a, c; //linear
	float g; //gamma
	float N;
	Filter * filt;
	if (x == true) {
		ui i = 1;
		while (string(argv[i]) != filename)								// Kanw to argv[i] string kai meta to sygkrino
		{
			if (string(argv[i]) == "-f") {
				i++; //to choose filter
				if (string(argv[i]) == "linear") {
					a = Color(atof(argv[i + 1]), atof(argv[i + 2]), atof(argv[i + 3]));
					c = Color(atof(argv[i + 4]), atof(argv[i + 5]), atof(argv[i + 6]));
					filt=new FilterLinear(a, c);
					cout << "I'm doing filter Linear" << endl;
					img = *filt << img;							// Epeidi o operator << epistrefei tin allagmeni eikona, kratame tin allagi stin img
					delete filt;
					i += 7;
				}//if1
				if (string(argv[i]) == "gamma") {
					g = atof(argv[i + 1]);  //argument to float
					 filt= new FilterG(g);
					 cout << "I'm doing filter G" << endl;
					img = *filt << img;
					delete filt;
					i += 2;
				}//if2
				 if (string(argv[i]) == "laplace") {
					// N = atof(argv[i + 1]);  //argument to float
					filt=new FilterLaplace();
				    img = *filt << img;
					delete filt;
					 i++;
		      }//if3
				 if (string(argv[i]) == "blur") {
					 N = atof(argv[i + 1]);  //argument to float
					 filt = new FilterBlur(N);
					 img = *filt << img;
					 delete filt;
					 i+=2;
				 }//if3
			}//-f
		}//while


		string outfilename;       
		int lastc = -1;               
		for (int i = 0; i < filename.length() - 1; i++) {      //an filename einai path
			if (filename[i] == '\\') {           // to \\ to metraei ws ena 
				lastc = i;
			}

		}
		if (lastc > 0) {  //sketo onoma eikonas
			string ssfirst = filename.substr(0, lastc + 1);
			string sslast = filename.substr(lastc + 1, filename.length());
			string ssmiddle = "filtered_";
			outfilename = ssfirst + ssmiddle + sslast;
		}
		else {
			outfilename = "filtered_" + filename;
		}

		img.save(outfilename, "ppm");



	} //else not good load
	return 0;
}


