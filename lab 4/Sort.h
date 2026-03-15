#pragma once
class Sort
{
    int* lista;
    int count;
public:
    Sort(int count, int maxi, int mini);
    Sort(const int arr[], int count);
    Sort(int* lista, int count);
    Sort(int count, ...);
    Sort(const char* numbers);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};