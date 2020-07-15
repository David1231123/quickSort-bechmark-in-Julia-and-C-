/*
Dieser Source File ist dafür da um die Dimension aus der dim.txt einzulesen und an 
den jeweiligen Algortihmus zurückzugeben.
*/
#include "dimension.h"
#include <fstream>

using namespace std;

int getDimension()
{    
	ifstream n_txt;
	n_txt.open("../dim.txt");
	if ( !n_txt.is_open()) {
		cerr << "C++: Could not open dim.txt" << endl;
		exit(EXIT_FAILURE);
	}
	
	unsigned long long n;                                                                                                                                                                                                                                                                                                                                                                                                                              
	n_txt >> n;
	n_txt.close();
	return n;
}



