#include"iostream"
using namespace std;
void subtractbypointer(double *ptrA,double *ptrB,double *ptrR) {
	*ptrR = *ptrA - *ptrB;
}
int main() {
	double a=0, b=0, c=0;
	cout << "Enter The Value of a :";
	cin >> a;
	cout << endl<<"Enter The Value of b :";
	cin >> b;
	subtractbypointer(&a, &b,&c);
	cout << "The Difference Between A And B = " << c;
	return 0;
}