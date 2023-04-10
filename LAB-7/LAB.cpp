#include "iostream"
using namespace std;

class DATE
{
	int day;
	int month;
	int year;

public:

	//Provide implementation setter 

	void setDay(int D)
	{
		if (D >= 1 && D <= 31)
		{
			this->day = D;
		}
		else
		{
			this->day = 1;
		}
		
	}

	void setMonth(int M)
	{
		if (M >= 1 && M <= 12)
		{
			this->month = M;
		}
		else
		{
			this->month = 1;
		}
		
	}

	void setYear(int Y)
	{

		if (Y >= 1900)
		{
			this->year = Y;
		}
		else
		{
			this->year= 1900;
		}

	}

	//Provide Implementation of getter

	int getDay()
	{
		return this->day;
	}

	int getMonth()
	{
		return this->month;
	}

	int getYear()
	{
		return this->year;
	}

	// provide the implementation of constructor
	
	//Paramenterized Constructor

	DATE(int D,int M,int Y)
	{
		setDay(D);
		setMonth(M);
		setYear(Y);
	}

	DATE(int M,int Y)
	{
		day = 1;
		setMonth(M);
		setYear(Y);
	}


	//Defalut Constructor
	DATE()
	{
		day = 1;
		month = 1;
		year = 1900;

	}

	//Overload The operator

	//make << operator for displaying information for obj

	friend ostream& operator <<(ostream& print,const DATE &obj)
	{
		string mon;

		switch (obj.month)
		{
		case 1:mon = "January";
		break;

		case 2:mon = "Fabuarary";
			break;

		case 3:mon = "March";
			break;
		case 4:mon = "April";
			break;

		case 5:mon = "May";
			break;

		case 6:mon = "June";
			break;

		case 7:mon = "July";
			break;

		case 8:mon = "August";
			break;

		case 9:mon = "September";
			break;

		case 10:mon = "October";
			break;

		case 11:mon = "November";
			break;

		case 12:mon = "December";
			break;
		}

		print << mon<<" "<< obj.day <<","<<obj.year<< endl;
		return print;
	}

	//make >> operator for getting information for obj

	friend istream& operator >>(istream& inp, DATE &obj)
	{
		char c;
		cout << "Enter The Date in the form month/day/year:";
		cin >> obj.month >> c >> obj.day >> c >> obj.year;

		obj.setDay(obj.day);
		obj.setMonth(obj.month);
		obj.setYear(obj.year);

		return inp;
	}


	//make +operator for the purpose of Public Holiday

	bool operator+()
	{
		//Put all The Public Dates

		if ((day == 5 && month == 2) || (day == 23 && month == 3) || (day == 1 && month == 5) || (day == 14 && month == 8) || (day == 9 && month == 11) || (day == 25 && month == 12))
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	//make - operator for returing the Date Difference

	int operator-(const DATE& obj)const
	{

		int days1 = day - obj.day;
		if (days1 > 0)
		{
			return days1;
		}
		else
		{
			return -(days1);
		}
	

	}

	//make Pre Increment Operator

	DATE operator ++()
	{

		++day;

		if (day > 31)
		{
			setDay(day);
			++month;

			if (month > 12)
			{
				setMonth(month);
				year++;
			}

		}
	
		return *this;
	}


	//Make Post Increment Operator


	DATE operator ++(int)

	{

		DATE oldstate(*this);

		++day;

		if (day > 31) 
		{
			setDay(day);
			++month;

			if (month > 12)
			{
				setMonth(month);
				year++;
			}

		}

		return oldstate;
	}

	//make Pre Decncrement Operator

	DATE operator --()
	{

		--day;

		if (day < 1) 
		{

			setDay(31);
			--month;

			if (month < 1)
			{
				setMonth(12);
				setYear(--year);
			}
			
		}

		return *this;
	}

	//make Post Decrement Operator

	DATE operator --(int)
	{
		DATE oldstate(*this);
		
		--day;

		if (day < 1) 
		{

			setDay(31);
			--month;

			if (month < 1)
			{
				setMonth(12);
				setYear(--year);
			}

		}

		return oldstate;
	}


	//making destructor

	~DATE()
	{
		cout << "Destructor Executed" << endl;
	}
};

int main()
{

	DATE obj1(31, 12, 2000),obj2(1,1,2001),obj3(24,3,2009);

	//Testing 

	cout << "The differnce between two Dates :" << obj1 - obj2 << endl;

  //testing increment
	++obj1;

	cout << obj1;

	//testing decrement

	--obj2;
	
	cout << obj2;

	//Testing Public Holiday

	if (+obj3)
	{
		cout << "It is Public Holiday" << endl;
	}
	else
	{
		cout << "It is not Public Holiday" << endl;
	}



	//
	DATE obj4;
	cin >> obj4;
	cout << obj4;
	return 0;
}