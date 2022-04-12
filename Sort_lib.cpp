#pragma once
#include <stdio.h>
#include "Header.h"
#include <iostream>
void Print(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}
stats Bubble_Sort(int* arr, size_t size)
{
    stats res;
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                res.comparison_count++;
                res.copy_count++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return res;
}

stats result;
stats Quick_Sort(int* arr, size_t size) {
    int i = 0;
    int j = size - 1;
    int base = arr[size / 2];
    do {
        while (arr[i] < base) {
            i++;
            result.comparison_count++;
        }
        while (arr[j] > base) {
            j--;
            result.comparison_count++;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
            result.copy_count++;
        }
    } while (i <= j);
    if (j > 0) {
        Quick_Sort(arr, j + 1);
    }
    if (i < size) {
        Quick_Sort(&arr[i], size - i);
    }
    return result;
}