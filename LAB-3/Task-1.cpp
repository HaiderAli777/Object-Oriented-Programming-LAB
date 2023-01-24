#include "iostream"

using namespace std;

int main() 
{

	float* ptrX = NULL,*ptrY=NULL;

	float* x = new float(4.5);

	float* y = new float(9.3);

	ptrX = x;

	ptrY = y;

	cout << "The address of ptrX : " << &ptrX <<"The value of : " << ptrX <<"The value where it point to : " << *ptrX<<endl;
	cout << "The address of ptrX : " << &ptrY << "The value of : " << ptrY << "The value where it point to : " << *ptrY;
	
	delete x;

	delete y;
	return 0;
}