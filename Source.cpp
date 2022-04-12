#include "Header.h"
#include <iostream>
using namespace std;
int main()
{
	int arr[] = { 1,7,3,9,5,6,1,3 };
	int arr1[] = { 1,7,3,9,5,6,1,3 };
	stats reu;
	reu = Bubble_Sort(arr, 8);
	cout << reu.comparison_count << endl << reu.copy_count << endl;
	Print(arr, 8);
	stats res = Quick_Sort(arr, 8);
	cout << res.comparison_count << endl << res.copy_count<<endl;
	Print(arr, 8);
	return 0;
}