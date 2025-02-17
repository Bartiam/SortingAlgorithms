#include "iostream"

/* Bubble sort with selection, sort in ascending or descending order */
// Default sort in ascending order
template <typename T>
void BubbleSorting(T* Array, const int& SIZE, const bool& SortAsOrDesOrder = true)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE - 1; ++j)
		{
			if (SortAsOrDesOrder)
			{
				if (Array[j] >= Array[j + 1])
				{
					std::swap(Array[j], Array[j + 1]);
				}
			}
			else
			{
				if (Array[j] <= Array[j + 1])
				{
					std::swap(Array[j], Array[j + 1]);
				}
			}
		}
	}
}



/* Insertion sort with selection, sort in ascending or descending order */
// Default sort in ascending order
template <typename T>
void InsertionSort(T* Array, const int& SIZE, const bool& SortAsOrDesOrder = true)
{
	int j;
	T CurrentElement;
	for (int i = 0; i < SIZE; ++i)
	{
		j = i - 1;
		T CurrentElement = Array[i]; 

		if (SortAsOrDesOrder)
		{
			while (j >= 0 && Array[j] > CurrentElement)
			{
				Array[j + 1] = Array[j];
				--j;	
			}
		}
		else
		{
			while (j >= 0 && Array[j] < CurrentElement)
			{
				Array[j + 1] = Array[j];
				--j;
			}
		}

		Array[j + 1] = CurrentElement;
	}
	
}



template <typename T>
void PrintArray(T* Array, const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << "Element: " << i << " = " << Array[i] << std::endl;
	}
}


int main()
{
	int size = 10;
	int* arr = new int[size] { 2, 4, 6, 1, -13, 0, 5, -2, 8, 32 };

	std::cout << "Without sorting. " << std::endl << std::endl;

	PrintArray(arr, size);

	// BubbleSorting(arr, size, false);
	// std::cout << std::endl << "BubbleSort! " << std::endl << std::endl;

	InsertionSort(arr, size, true);
	std::cout << std::endl << "InsertionSort! " << std::endl << std::endl;

	PrintArray(arr, size);

	return 0;
}