#include "Image.h"
using namespace imaging;
class Filter {
  
	public:
		virtual Image operator << (const Image &image) = 0;
		Filter 
};

class FilterLinear :public Filter {
private:
	Color a;
	Color c;
public:
	FilterLinear(Color a, Color c); 
	Image operator <<(const Image &image);

	FilterLinear(const FilterLinear & src);
};

class FilterG :public Filter {
private:
	float g;
public:
	FilterG(float g); 

	Image operator <<(const Image &image);

	FilterG(const FilterG & src);
};

class FilterBlur :public Filter,public Array<float> {
private:
	int N;
public:
	FilterBlur(int N);

	Image operator <<(const Image &image);
};

class FilterLaplace :public FilterBlur {
private:

public:
	FilterLaplace();

	Image operator <<(const Image &image);
};
