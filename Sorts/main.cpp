#include "iostream"

/* Bubble sort with selection, sort in ascending or descending order */
// Default sort in ascending order
template <typename T>
void BubbleSorting(T Array[], const int& SIZE, const bool& SortAsOrDesOrder = true)
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
void InsertionSort(T Array[], const int& SIZE, const bool& SortAsOrDesOrder = true)
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




template<typename T>
void Heapify(T Array[], const int& SIZE, const int& index, const bool& MaxOrMin = true)
{
	int parentElement = index;
	const int left = index * 2 + 1;
	const int right = index * 2 + 2;

	if (MaxOrMin)
	{
		if (left < SIZE && Array[left] > Array[parentElement]) parentElement = left;
		if (right < SIZE && Array[right] > Array[parentElement]) parentElement = right;
	}
	else
	{
		if (left < SIZE && Array[left] < Array[parentElement]) parentElement = left;
		if (right < SIZE && Array[right] < Array[parentElement]) parentElement = right;
	}

	if (parentElement != index)
	{
		std::swap(Array[index], Array[parentElement]);

		Heapify(Array, SIZE, parentElement, MaxOrMin);
	}

}


/* Heap sort with selection, sort in ascending or descending order */
// Default sort in ascending order
template<typename T>
void HeapSort(T Array[], const int& SIZE, const bool& SortAsOrDesOrder = true)
{
	for (int i = SIZE / 2 - 1; i >= 0; --i)
	{
		Heapify(Array, SIZE, i, SortAsOrDesOrder);
	}

	for (int i = SIZE - 1; i > 0; --i)
	{
		std::swap(Array[0], Array[i]);

		Heapify(Array, i, 0, SortAsOrDesOrder);
	}
}


template <typename T>
void PrintArray(T Array[], const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << "Element: " << i << " = " << Array[i] << std::endl;
	}
}



class Animal
{
public:
	virtual void Voice()
	{
		std::cout << "Some sounds." << std::endl;
	}
};


class Dog : public Animal
{
public:
	virtual void Voice() override
	{
		std::cout << "BARK! BARK! BARK! " << std::endl;
	}
};



int main()
{
	int size = 10;
	int* arr = new int[size] { 2, 4, 6, 1, -13, 0, 5, -2, 8, 32 };

	std::cout << "Without sorting. " << std::endl << std::endl;

	// PrintArray(arr, size);
	// 
	// BubbleSorting(arr, size, false);
	// std::cout << std::endl << "BubbleSort! " << std::endl << std::endl;
	// 
	// InsertionSort(arr, size, true);
	// std::cout << std::endl << "InsertionSort! " << std::endl << std::endl;
	// 
	// PrintArray(arr, size);

	PrintArray(arr, size);

	std::cout << std::endl << "HeapSort! " << std::endl << std::endl;
	HeapSort(arr, size, true);
	
	PrintArray(arr, size);


	delete[] arr;
	return 0;
}