#include "Vector3d.h"
#include <cmath>
using namespace std;

double Vector3d::normaMax(){
	double norma;
	norma=sqrt((pow(x,2))+(pow(y,2))+(pow(z,2)));
	return norma;
}
