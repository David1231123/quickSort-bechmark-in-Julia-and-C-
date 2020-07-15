/*
http://www.cplusplus.com/reference/cstdlib/qsort/
https://www.programiz.com/cpp-programming/library-function/cstdlib/qsort
*/
#include "dimension.h" 
#include <stdio.h>
#include <stdlib.h>    // qsort 
 
using namespace std;

int main()
{
	int n = getDimension();
	cerr << "C++,quickSort_stdlib," << n << ",";

	int *arr = new int[n];  // Zeiger definieren und sichern
	for(int i = 0; i < n; ++i){  // array for sorting
		arr[i] = n - i;
	}

	if (n > 0){
 		qsort(arr, n, sizeof(int), [](const void * a, const void * b){return ( *(int*)a - *(int*)b );});
	}
	
	delete[] arr;   
    return 0;
}