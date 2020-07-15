/*
Dieser Algorithmus stellt den Quicksort-Alg. auf ein Array dar. Quicksort ist ein schneller, rekursiver,
nicht-stabiler Sortieralgorithmus, der nach dem Prinzip Teile und herrsche arbeitet.
Die hier implementierte Version wird mittels eines Stacks iterativ implementiert.
Quelle: https://de.wikipedia.org/wiki/Quicksort#Iteratives_Quicksort,
        http://www.geeksforgeeks.org/iterative-quick-sort/
*/
#include "dimension.h" // allgemein definiert, da es in jedem source-file verwendet wird
#include <stdio.h>
 
using namespace std;

// Vertausche Array-Elemente
void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
// führt einen Durchgang durch und gibt neues Pivotelement zurück
int partition (int* arr, int left, int right)
{
    int x = arr[right];
    int i = (left - 1);
 
    for (int j = left; j <= right- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}
 
void quickSort (int* arr, int left, int right)
{
	int *stack = 0;      // Zeiger definieren und sichern
	stack = new int[right - left + 1]; // Speicher anfordern für Stack
    int top = -1;
    stack[++top] = left;
    stack[++top] = right;
	// wiederhole solange bis Stack leer ist
    while ( top >= 0 )
    {
		
		// entnehme Elemente vom Stack
        right = stack[top--];
        left = stack[top--]; 
		
        int pivot = partition(arr, left, right);
		
		// Wenn Elemente links vom Pivotelement sind pushe sie auf den Stack
        if ( pivot-1 > left )
        {
            stack[ ++top ] = left;
            stack[ ++top ] = pivot - 1;
        }
		
		// Wenn Elemente rechts vom Pivotelement sind pushe sie auf den Stack
        if ( pivot+1 < right )
        {
            stack[ ++top ] = pivot + 1;
            stack[ ++top ] = right;
        }
    }
	delete[] stack;  // Speicher freigeben
}

// zum testen
void print(int* a, int N)
{
    for(int i = 0 ; i < N ; i++)
	{
        cout << a[i];
		if(i != N -1){
			cout << ",";
		}
	}
	cout << endl;
} 


int main()
{
	int n = getDimension();
	cerr << "C++,quickSort," << n << ",";
	int *arr = 0;      // Zeiger definieren und sichern
	arr = new int [n]; // Speicher anfordern
	unsigned long long w;
	for (int i = 0; i < n; i++)
	{
		w = (7*i) % 10000; // Array mit Werten zwischen 0 und 10000
		arr[i] = w;
	}
    //cout << "Before sorting : " << endl;
    //print(arr, n);
	if (n > 0)
	{
		quickSort(arr, 0, n-1);		// übergibt das gesasmte Array, den linken und rechten Rand
	}
    //cout << endl << "After sorting : " << endl;
	if(n > 0 && n < 1000000){
    	print(arr, n);
	}
    delete[] arr;      // Freigabe des Speichers
	arr = 0;           // Zeiger sichern
    return 0;
}