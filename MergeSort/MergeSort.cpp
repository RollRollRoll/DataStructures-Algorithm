#include <iostream>
#include <climits>
using namespace std;

void Merge(int *A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];
	for (int i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (int i = 0; i < n2; i++)
		R[i] = A[q + i + 1];
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int i = 0, j = 0;
	for (int k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
}

void MergeSort(int *A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

void main()
{
	int A[] = { 2,4,5,7,1,2,3,6 };
	MergeSort(A, 0, 7);
	for (int i = 0; i < 8; i++)
		cout << A[i] << endl;
	system("pause");
}