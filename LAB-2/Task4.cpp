#include"iostream"
using namespace std;
void getMinMax(int *array,int size,int *ptrMax,int *ptrMin) {
	*ptrMin = *(array + 0);
	*ptrMax= *(array + 0);
	for (int i = 1;i < size;i++) {
		if (*(ptrMin) > *(array + i)) {
			*ptrMin = *(array + i);
		}
		if (*(ptrMax) < *(array + i)) {
			*ptrMax = *(array + i);
		}
	}
}
int main() {
	int arr[10]={-1,23,3,4,5,6,7,8,9,10},Max=0,Min=0;
	getMinMax(arr, 10,&Max,&Min);
	cout << "Maximum Value :" << Max<<endl;
	cout << "Mainimum Value :" << Min << endl;
	return 0;
}