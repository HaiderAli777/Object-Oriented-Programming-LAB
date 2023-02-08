#include "iostream"
#include "string"
using namespace std;

class Car 

{
	//private Members
	int yearModel;
	string make;
	int speed;



public:
	

//Parameterized Constructor 
	
	Car(int YearM, string M)
	{
		yearModel = YearM;
		make = M;
		speed = 0;
	}

	//Copy Constructor
	Car( Car &obj1)
	{
		yearModel =obj1.yearModel;
		make = obj1.make;
		speed = obj1.speed;
	}

	

	//All Getter Function

	int getYearM() {
		return yearModel;
	}

	string getMake() {
		return make;
	}

	int getSpeed() {
		return speed;
	}

	//All Setter Function
	void  setYearM(int M) {
		yearModel=M;
	}

	void setMake(string name) {
		make = name;
	}

	void setSpeed(int sp) {
		speed=sp;
	}

	//Member Function

	void setCar(int YM, string M, int sped)
	{
		yearModel = YM;
		make = M;
		speed = sped;

	}

	void getCar()
	{
		cout << "Enter The Year Model :";
		cin >> yearModel;

		cin.ignore();
		cout << "Enter The Make : ";
		getline(cin,make);

		cout << "Enter The Speed : ";
		cin >> speed;

	}

	//just for Checking
	void putCar()
	{
		cout << yearModel << "\t\t" << make << "\t" << speed << endl;
	}

	//Accelerate And Brake

	void Accelate() 
	{
		speed = speed + 5;
	}

	void Break()
	{
		speed = speed - 5;
	}

	//Destructor
	~Car()
	{
		cout << "Destructor Executed ....." << endl;
	}
};




int main()
{
	
	

	Car obj1(2001, "Honda"),obj2(2002, "SUZUKI"),obj3(2003, "GLORY"),obj4(2004, "DFSK"),obj5(2005, "ALTO");
	obj1.getCar();
	obj2.getCar();
	obj3.getCar();
	obj4.getCar();
	obj5.getCar();

	cout << "YEAR MODEL" << "\t" << "MAKE" << "\t" << "SPEED"<<endl;

	obj1.putCar();
	obj2.putCar();
	obj3.putCar();
	obj4.putCar();
	obj5.putCar();
	return 0;
}