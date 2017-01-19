#include <iostream>
using namespace std;

void Exchange(int *A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int Parent(int i)
{
	return i / 2;
}

int LeftChild(int i)
{
	return 2 * i;
}

int RightChild(int i)
{
	return 2 * i + 1;
}

void MaxHeapIFY(int *A, int heapSize, int i)
{
	int l = LeftChild(i);
	int r = RightChild(i);
	int largest = i;
	if (l <= heapSize&&A[l] > A[i])
		largest = l;
	if (r <= heapSize&&A[r] > A[largest])
		largest = r;
	if (largest != i)
	{
		Exchange(A, i, largest);
		MaxHeapIFY(A, heapSize, largest);
	}
}

void BuildMaxHeap(int *A,int heapSize)
{
	for (int i = heapSize / 2; i >= 0; i--)
		MaxHeapIFY(A, heapSize, i);
}

void HeapSort(int *A, int length)
{
	BuildMaxHeap(A, length);
	for (int i = length; i >= 1; i--)
	{
		Exchange(A, 0, i);
		MaxHeapIFY(A, i - 1, 0);
	}
}

void main()
{
	int A[] = { 4,1,3,2,16,9,10,14,8,7 };
	HeapSort(A, 9);
	for (int i : A)
		cout << i << endl;
	system("pause");
}