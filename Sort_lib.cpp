#pragma once
#include <stdio.h>
#include "Header.h"
#include <iostream>
#include <vector>

void Print(std::vector<int>& arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}
stats Bubble_Sort(std::vector<int>& arr)
{
    stats res;
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        for (size_t j = 0; j < arr.size() - i - 1; j++)
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

stats re;
vector<int> merge(vector<int> a, vector<int> b)
{
    int aindex = 0;
    int bindex = 0;
    int cindex = 0;
    vector<int> c(a.size() + b.size());
    while ((aindex < a.size()) && (bindex < b.size()))
    {
        if (a[aindex] < b[bindex])
        {
            c[cindex] = a[aindex];
            aindex++;
        }
        else
        {
            c[cindex] = b[bindex];
            bindex++;
        }
        re.comparison_count++;
        re.copy_count++;
        cindex++;
    }
    while (aindex < a.size())
    {
        c[cindex++] = a[aindex++];
        re.copy_count++;
    }
    while (bindex < b.size())
    {
        c[cindex++] = b[bindex++];
        re.copy_count++;
    }
    return c;
}

stats Merge_Sort(vector<int>& arr)
{
    int i = 0;
    int j = arr.size() - 1;
    int k = 0;
    int f = arr.size() - 1;
    vector<int>res(arr.size());
    bool left = true;
    while (i < j)
    {
        vector<int>a;
        vector<int>b;
        vector<int>c;
        while ((arr[i] <= arr[i + 1]) && (i < j) && (i < arr.size()))
        {
            re.comparison_count++;
            a.push_back(arr[i]);
            i++;
        }
        a.push_back(arr[i]);
        i++;
        while ((arr[j] <= arr[j - 1]) && (i < j) && (j < arr.size()))
        {
            re.comparison_count++;
            b.push_back(arr[j]);
            j--;
        }
        if (i <= j)
        {
            b.push_back(arr[j]);
            j--;
        }
        c = merge(a, b);
        if (left)
        {

            int d = 0;
            for (int g = k; g < c.size() + k; g++)
            {
                res[g] = c[d];
                d++;
                re.copy_count++;
            }
            k = k + c.size();
            left = false;
        }
        else
        {
            int d = 0;
            for (int g = f; g > f - c.size(); g--)
            {
                res[g] = c[d];
                d++;
                re.copy_count++;
            }
            f = f - c.size();
            left = true;
        }
        if (c.size() == arr.size())
        {
            for (int i = 0; i < res.size(); i++)
                cout << res[i];
            return re;
        }
    }
    if (i != arr.size())
    {
       re= Merge_Sort(res);
    }
    return re;
}

stats result;
stats Quick_Sort(std::vector<int>& arr, int left,int right )
{
    int base; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    base = arr[left];
    while (left < right) // пока границы не сомкнутся
    {
        while ((arr[right] >= base) && (left < right))
        {
            right--; // сдвигаем правую границу пока элемент right больше base
            result.comparison_count++;
        }
        if (left != right) // если границы не сомкнулись
        {
            arr[left] = arr[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
            result.copy_count++;
        }
        while ((arr[left] <= base) && (left < right))
        {
            left++; // сдвигаем левую границу пока элемент [left] меньше base
            result.comparison_count++;
        }
        if (left != right) // если границы не сомкнулись
        {
            arr[right] = arr[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу влево
            result.copy_count++;
        }
    }
    arr[left] = base; // ставим разрешающий элемент на место
    result.copy_count++;
    base = left;
    left = l_hold;
    right = r_hold;
    if (left < base) // Рекурсивно вызываем сортировку для левой и правой части массива
        Quick_Sort(arr, left, base - 1);
    if (right > base)
        Quick_Sort(arr, base + 1, right);
    return result;
}