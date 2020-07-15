/*
http://www.cplusplus.com/reference/cstdlib/qsort/
https://cppsecrets.com/users/1442971101051149897110100971154850485464103109971051084699111109/C00-boostsortpdqsort.php
*/
#include "dimension.h" 
#include <boost/lambda/lambda.hpp>
#include <boost/sort/pdqsort/pdqsort.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
 
using namespace std;
using namespace boost::sort; // using namespace so that we don't have to write it every time

int main()
{
	int n = getDimension();
	cerr << "C++,quickSort_boost," << n << ",";
	
	vector<int> arr(n);
	for(int i = 0; i < n; ++i){  // [n, n-1, ..., 1] => worst case
		arr[i] = n - i;
	}
	
	if (n > 0){
 		pdqsort_branchless(arr.begin(), arr.end(), [](const int &a, const int &b){return ( a < b );});
	}
		
	return 0;
}



