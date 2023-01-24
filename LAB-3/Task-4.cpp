#include "iostream"

using namespace std;

void GetevenOdd(const int ar[], const int n_ar, int*& even, int& even_n, int*& odd, int& odd_n)
{
	even_n = 0, odd_n = 0;


	for (int i = 0;i < n_ar;i++)
	{
		if (ar[i] % 2 == 0)
		{
			even_n++;
		}
		else
		{
			odd_n++;
		}
	}


	if (even_n != 0) {
		even = new int[even_n];
		int j = 0;
		for (int i = 0;i < 10;i++)
		{
			if (ar[i] % 2 == 0)
			{
				*(even + j) = ar[i];
				j++;
			}
		}
	}

	if (odd_n != 0) {
		odd = new int[odd_n];
		int j = 0;
		for (int i = 0;i < 10;i++)
		{
			if (ar[i] % 2 != 0)
			{
				*(odd + j) = ar[i];
				j++;
			}
		}
	}

}

int main()
{
	int arr[10] = { 1,3,5,7,8,15,17,19,21,23 };
	int* even = NULL, * odd = NULL;
	int even_n, odd_n;
	GetevenOdd(arr, 10, even, even_n, odd, odd_n);


	if (even != NULL) {
		cout << "There is an Even Number :" << endl;
		for (int i = 0; i < even_n; i++)
		{
			cout << *(even + i) << endl;
		}
	}
	else {
		cout << "There Is no Even number" << endl;
	}
	if (odd != NULL) {
		cout << "There is an Odd Number :" << endl;
		for (int i = 0; i < odd_n; i++)
		{
			cout << *(odd + i) << endl;
		}
	}
	else
	{
		cout << "There Is no Odd number" << endl;
	}
	delete[]even;
	delete[]odd;
	return 0;
}