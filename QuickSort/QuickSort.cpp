#include<iostream>
#include<ctime>
#define random(x) (rand()%x)
using namespace std;

void Exchange(int *A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int Partition(int *A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= x)
		{
			i += 1;
			Exchange(A, i, j);
		}
	}
	Exchange(A, i + 1, r);
	return i + 1;
}

int RANDOMIZED_PARTITION(int *A,int p, int r)
{
	srand((int)time(0));
	int i = random((r - p+1)) + p;
	Exchange(A, i, r);
	return Partition(A,p,r);
}

void RANDOMIZED_QUICKSORT(int *A, int p, int r)
{
	if (p < r)
	{
		int q = RANDOMIZED_PARTITION(A, p, r);
		RANDOMIZED_QUICKSORT(A, p, q - 1);
		RANDOMIZED_QUICKSORT(A, q + 1, r);
	}
}

void main() 
{
	for (int i = 0; i < 20; i++)
	{
		//cout << random(3) << endl;;
	}
	int A[8] = { 2,8, 7,1,3,5,6,4 };
	RANDOMIZED_QUICKSORT(A,0,7);
	for (int i = 0; i < 8; i++)
	{
		cout << A[i] << endl;
	}
	system("pause");
}