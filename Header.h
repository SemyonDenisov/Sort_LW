#pragma once
struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};
void Print(int* arr,size_t size);
stats Bubble_Sort(int* arr, size_t size);
stats Quick_Sort(int* arr, size_t size);