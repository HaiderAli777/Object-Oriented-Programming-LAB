#include"iostream"
using namespace std;
int main() {
	int x=2, y=8;
	int* ptrX = &x, * ptrY = &y;
	cout << "The Value of x = " << x << " And The adress = " << &x<<endl;
	cout << "The Value of ptrX = " << ptrX << " And The adress = " << &ptrX <<" The value of memory location where it points = "<<*ptrX<< endl;
	cout << "The Value of x = " << y << " And The adress = " << &y << endl;
	cout << "The Value of ptrX = " << ptrY << " And The adress = " << &ptrY << " The value of memory location where it points = " << *ptrY << endl;
	return 0;
}