#include "iostream"

using namespace std;

int main() 
{

	int size,sum=0;

	cout << "Enter The size of array : ";
	cin >> size;

	int *arr = new int[size];

	for (int i = 0;i < size;i++) 
	{
		cout << "Enter The (" << i + 1 << ")element : " ;
		cin >> *(arr + i);
	}

	for (int i = 0;i < size;i++)
	{
	  sum = sum + *(arr + i) ;
	}

	cout << "The Sum :" << sum << endl;

	delete[] arr;
	return 0;
}