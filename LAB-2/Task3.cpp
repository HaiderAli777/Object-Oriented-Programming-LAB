#include "iostream"
using namespace std;
void arrayBypointer(float* ptr,int size) {
	for (int i = 0;i < size;i++) {
		cout << "The Array Element Address :" << (ptr + i) << " With its Value : " << *(ptr + i)<<endl;
	}
}
int main() {
	float array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	arrayBypointer(array,10);
	return 0;
}