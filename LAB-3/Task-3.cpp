#include "iostream"

using namespace std;

int* getPositiveNumbers(const int ar[], const int  s, int& newArraySize)
{
	int* pos = new int[10];//there an other solution that first find size and then make dynamic array
		int j = 0;
	for (int i = 0;i < s;i++)
	{
		if (ar[i] >= 0)
		{
			*(pos + j) = ar[i];
			j++;
		}

	}
	newArraySize = j - 1;
	if (j== 0) {
		return NULL;
	}
	else {
		return pos;
	}
}

int main()
{

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int newArraysize = 0;
	int *newArr = getPositiveNumbers(arr, 10,newArraysize);
	cout << newArraysize << endl << endl<<"sdsds";

	
	if (newArr == NULL) {
		cout << "There Is No positive number ";
	}
	else {
		for (int i = 0;i < newArraysize;i++) {
			cout << *(newArr + i) << endl;
		}
	}
	delete[] newArr;
	return 0;
}