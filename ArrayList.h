#pragma once
#include <iostream>
#include <exception>
using namespace std;


template <class T>
class ArrayList
{
	int size;
	int capacity;
	T* InternalArray;

	void ResizeArray()
	{
		//Here we increase the capacity by 100,000 to make the Adding element into the array faster. 
		//and it will resize the array when the size reaches 100,000 element
		T* temp = new T[capacity + 100000];

		for (int i = 0;i < size;i++)
		{
			temp[i] = InternalArray[i];
		}

		delete[] InternalArray;
		InternalArray = temp;
		capacity += 100000;
	}

public:

	ArrayList(int capacity = 10)
	{
		this->capacity = capacity;
		size = 0;
		InternalArray = new T[capacity];
	}

	ArrayList(T array[], int arraySize)
	{
		size = arraySize;
		capacity = size + 10;



		InternalArray = new T[capacity];
		for (int i = 0;i < arraySize;i++)
		{
			InternalArray[i] = array[i];
		}
	}
	~ArrayList()
	{
		if (InternalArray)
		{
			delete[] InternalArray;
			InternalArray = nullptr;
		}
	}

	void Add(T Item)
	{
		if (size >= capacity)
		{
			ResizeArray();
		}


		InternalArray[size] = Item;
		size++;
	}

	bool InsertAt(int index, T value)
	{
		if (index < 0 || index > size)
		{
			return false;
		}

		if (size >= capacity)
		{
			ResizeArray();
		}

		for (int i = size;i > index;i--)
		{
			InternalArray[i] = InternalArray[i - 1];
		}
		InternalArray[index] = value;
		size++;
		return true;
	}

	bool Delete(int index)
	{
		if (index < 0 || index >= size)
			return false;

		for (int i = index;i < size - 1;i++)
		{
			InternalArray[i] = InternalArray[i + 1];
		}

		size--;
		return true;
	}

	bool Clear()
	{
		if (size > 0) {
			delete[] InternalArray;
			InternalArray = new T[capacity];
			size = 0;
			return true;
		}
		return false;
	}

	T& operator[](int Index)
	{
		if (Index >= size || Index < 0)
		{
			throw "Error, index out of range.";
		}
		return InternalArray[Index];
	}

	bool Contains(T Value)
	{
		for (int i = 0; i < size; i++)
		{
			if (InternalArray[i] == Value)
			{
				return true;
			}
		}
		return false;
	}

	int IndexOf(T Value)
	{

		for (int i = 0;i < size;i++)
		{
			if (InternalArray[i] == Value)
			{
				return i;
			}
		}
		return -1;
	}

	T GetValue(int index)
	{
		if (index < 0 || index >= size)
		{
			throw "Error, index out of range.";
		}
		return InternalArray[index];
	}

	int GetSize()
	{
		return size;
	}

	int GetCapacity()
	{
		return capacity;
	}

	bool IsEmpty()
	{
		return size == 0;
	}

	void Reverse()
	{
		int left = 0, right = size - 1;
		while (left < right)
		{
			T temp = InternalArray[left];
			InternalArray[left] = InternalArray[right];
			InternalArray[right] = temp;
			left++;
			right--;
		}
	}
};