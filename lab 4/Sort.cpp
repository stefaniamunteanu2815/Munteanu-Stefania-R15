#include "Sort.h"
#include <iostream>
#include <stdarg.h>
#include <cstdlib>
using namespace std;

Sort::Sort(int* lista, int count)
{
	this->count = count;
	this->lista = new int[count];
	for (int i = 0; i < count; i++)
		this->lista[i] = lista[i];
}
Sort::Sort(const int arr[], int count)
{
	this->count = count;
	lista = new int[count];
	for (int i = 0; i < count; i++)
		lista[i] = arr[i];
}
Sort::Sort(int count, int maxi, int mini)
{
	this->count = count;
	lista = new int[count];
	for (int i = 0; i < count; i++)
	{
		lista[i] = mini + rand() % (maxi - mini + 1);
	}
}
Sort::Sort(int count, ...)
{
	this->count = count;
	lista = new int[count];
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		lista[i] = va_arg(args, int);
	}
	va_end(args);
}
Sort::Sort(const char* numbers)
{
	count = 1;
	for (int i = 0; numbers[i] != '\0'; i++)
		if (numbers[i] == ',')
			count++;
	lista = new int[count];
	int idx = 0;
	int num = 0;
	for (int i = 0; numbers[i] != '\0'; i++)
	{
		if (numbers[i] == ',')
		{
			lista[idx++] = num;
			num = 0;
		}
		else
		{
			num = num * 10 + (numbers[i] - '0');
		}
	}
	lista[idx] = num;
}
void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < count; i++)
	{
		int x = lista[i];
		int j = i - 1;
		if (ascendent)
		{
			while (j >= 0 && lista[j] > x)
			{
				lista[j + 1] = lista[j];
				j--;
			}
		}
		else
		{
			while (j >= 0 && lista[j] < x)
			{
				lista[j + 1] = lista[j];
				j--;
			}
		}
		lista[j + 1] = x;
	}
}
void Sort::QuickSort(bool ascendent)
{
	int leftStack[64], rightStack[64];
	int top = -1;

	leftStack[++top] = 0;
	rightStack[top] = count - 1;

	while (top >= 0)
	{
		int left = leftStack[top];
		int right = rightStack[top--];

		int i = left;
		int j = right;
		int pivot = lista[(left + right) / 2];
		if (ascendent)
		{
			while (i <= j)
			{
				while (lista[i] < pivot) i++;
				while (lista[j] > pivot) j--;

				if (i <= j)
				{
					int temp = lista[i];
					lista[i] = lista[j];
					lista[j] = temp;
					i++;
					j--;
				}
			}
		}
		else
		{
			while (i <= j)
			{
				while (lista[i] > pivot) i++;
				while (lista[j] < pivot) j--;

				if (i <= j)
				{
					int temp = lista[i];
					lista[i] = lista[j];
					lista[j] = temp;
					i++;
					j--;
				}
			}
		}
		if (left < j)
		{
			leftStack[++top] = left;
			rightStack[top] = j;
		}

		if (i < right)
		{
			leftStack[++top] = i;
			rightStack[top] = right;
		}
	}
}
void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (ascendent)
			{
				if (lista[j] > lista[j + 1])
				{
					int aux = lista[j];
					lista[j] = lista[j + 1];
					lista[j + 1] = aux;
				}
			}
			else
			{
				if (lista[j] < lista[j + 1])
				{
					int aux = lista[j];
					lista[j] = lista[j + 1];
					lista[j + 1] = aux;
				}
			}
		}
	}
}
void Sort::Print()
{
	for (int i = 0; i < count; i++) cout << lista[i] << " ";
	cout << '\n';

}
int Sort::GetElementsCount()
{
	return count;
}
int Sort::GetElementFromIndex(int index)
{
	return lista[index];
}