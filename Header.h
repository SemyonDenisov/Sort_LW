#pragma once
#include <vector>
using namespace std;
struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};
void Print(vector<int>& arr);
stats Bubble_Sort(vector<int>& arr);
stats Quick_Sort(vector<int>& arr, int left,int right);
stats Merge_Sort(vector<int> &arr);