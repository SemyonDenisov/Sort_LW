#define _XM_NO_INTRINSICS_
#include "Header.h"
#include <iostream>
#include <vector>
using namespace std;
vector <int> enter()
{
	size_t n;
	cin >> n;
	vector<int> arr;
	for (size_t i = 0; i < n; i++)
	{
		size_t member;
		cin >> member;
		arr.push_back(member);
	}
	return arr;
}
int main()
{
	vector<int>arr = enter();
	vector<int>arr1 = { 1,7,3,9,5,6,1,3,0,7 };
	stats reu;
	Print(arr);
	reu = Bubble_Sort(arr);
	Print(arr);
	cout << reu.comparison_count << endl << reu.copy_count << endl;
	Print(arr1);
	stats res = Quick_Sort(arr1, 0,9);
	Print(arr1);
	cout << res.comparison_count << endl << res.copy_count<<endl;
	vector<int> arr2 = { 3,1,7,9,6,4,2,2,10,8 };
	Print(arr2);
	stats resu = Merge_Sort(arr2);
	cout << endl;
	cout << resu.comparison_count << endl << resu.copy_count << endl;
	return 0;
}