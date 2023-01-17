#include "iostream"
using namespace std;
float celsius(float f) {
	cout << f << endl;;
	float c = (5*(f - 32))/9;
	cout << c << endl;
	return c;
}
int main() {
	cout << "The Table That Convert Farenhite To Celsius Are Below" << endl;
	for (float fa =0;fa <=20;fa++) {
		float cel=celsius(fa);
		cout << fa << " Temprature == " << cel << " Temprature"<<endl;
	}
	return 0;
}