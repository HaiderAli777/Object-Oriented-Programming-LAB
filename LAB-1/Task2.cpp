#include "iostream"
using namespace std;
int main() {
	int number;
	cout << "Enter The Size Of Array";
	cin >> number;
	int* arr = new int(number);
	int* k = new int(number / 2);
	int value=0,m=0;
	for (int i = 0;i < number;i++) {
		cout << "Enter The [" << i << "] Element :";
		cin >> *(arr+i);
	}
	for (int i = 0;i < number;i++) {
		for (int j = 0;j < 2;j++) {
			value = value + *(arr+i);
			i++;
		}
		*(k+m) = value;
		m++;
	    i--;
		value = 0;
	}
	for (int i = 0;i < m;i++) {
		cout << "The Value : " << k[i]<<endl;
	}
	return 0;
}