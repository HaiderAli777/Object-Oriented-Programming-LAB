#include<iostream>
using namespace std;
class Employe
{
	string firstName;
	string Lastname;
	string SSR;

public:
	Employe(string fname,string ln,string SS)
	{
		this->firstName = fname;
		this->Lastname = ln;
		this->SSR = SS;
	}


	string getLname()
	{
		return Lastname;
	}

	string getFname()
	{
		return firstName;
	}
	string SS()
	{
		return SSR;
	}
	void setLname(string ln)
	{
		this->Lastname = ln;
	}
	void setSS(string SS)
	{
		this->SSR = SS;
	}
	void setFname(string fn)
	{
		this->firstName = fn;
	}

	virtual void Print()
	{
		cout << Lastname << endl;
		cout << firstName << endl;
		cout << SSR << endl;
	}

	virtual  double earnings() = 0;
};


class SalariedEmployed:public Employe
{
	double WeeklySalary;

public:

	SalariedEmployed(string fl,string ln,string ss):Employe(fl,ln,ss)
	{
		this->WeeklySalary = 0;
	}

	double getSalaryEmploy()
	{
		return WeeklySalary;
	}
	void setSalary(double WS)
	{
		this->WeeklySalary = WS;
	}

	virtual void Print()
	{
		cout << WeeklySalary << endl;
		Employe::Print();

	}

	double earnings()
	{
		return WeeklySalary;
	}

  };

class HourlyEmploy:public Employe
{
	double hour;
	double Wage;

public:

	HourlyEmploy(string fl, string ln, string ss) :Employe(fl,ln,ss)
	{
		this->hour = 0;
		this->Wage = 0;
	}

	double getHour()
	{
		return hour;
	}
	double getWage()
	{
		return Wage;
	}
	void setHour(double h)
	{
		this->hour = h;
	}
	void setWage(double w)
	{
		this->Wage = w;
	}

	virtual void Print()
	{
		
		Employe::Print();
		cout << hour<<endl;
		cout << Wage << endl;
	}

	double earnings()
	{
		return hour * Wage;
	}

};

class CommisionEmploye:public Employe
{
	double grossSale;
	double CommisionRate;

public:

	CommisionEmploye(string fl, string ln, string ss) :Employe(fl,ln,ss)
	{
		this->grossSale = 0;
		this->CommisionRate = 0;
	}

	double getGross()
	{
		return grossSale;
	}
	double getComssionRate()
	{
		return CommisionRate;
	}
	void setGross(double gross)
	{
		this->grossSale = gross;
	}
	void setCommisRa(double com)
	{
		this->CommisionRate = com;
	}

	virtual void Print()
	{

		Employe::Print();
		cout << grossSale << endl;
		cout << CommisionRate<< endl;
	}

	double earnings()
	{
		return CommisionRate*grossSale;
	}
};

class BasePlusCommisionEmploye:public CommisionEmploye
{
	double BaseSalary;

public:

	BasePlusCommisionEmploye(string fl, string ln, string ss) :CommisionEmploye(fl,ln,ss)
	{
		this->BaseSalary = 0;
	}

	double getBaseS()
	{
		return BaseSalary;
	}
	
	void setBaseS(double h)
	{
		this->BaseSalary = h;
	}
	

	virtual void Print()
	{

		Employe::Print();
		CommisionEmploye::Print();
		cout << BaseSalary;
	}

	double earnings()
	{
		return CommisionEmploye::earnings() + BaseSalary;
	}
};

int main()
{
	Employe* E[4];
	SalariedEmployed obj1("Haider","Ali","1234");
	obj1.setSalary(10202);
	CommisionEmploye obj2("Rauf", "Ali", "1234");
	obj2.setCommisRa(22.7);
	obj2.setGross(33.5);
	BasePlusCommisionEmploye obj3("Anas", "Ali", "1234");
	obj3.setBaseS(2220);
	HourlyEmploy obj4("Zohaib", "Ali", "1234");
	obj4.setHour(1);
	obj4.setWage(3);
	E[0] = &obj1;
	E[1] = &obj2;
	E[2] = &obj3;
	E[3] = &obj4;

	for (int i = 0;i < 4;i++)
	{
		E[1]->Print();
		E[1]->earnings();
	}

}