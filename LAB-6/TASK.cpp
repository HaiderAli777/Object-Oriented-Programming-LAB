#include "iostream"
using namespace std;
#include "string"

class Student
{
	string firstname;
	int regNo;
	string lastname;
	string program;
	float cgpa;

public:
	

	//parameterized constructor

	Student(string fname, int reg, string lname, string prog,float cg)
	{
		setFirstName(fname);
		setRe(reg);
		setLastName(lname);
		setCGPA(cg);
		setProgram(prog);

	}

	Student(string fname, int regNo,string prog)
	{
		setFirstName(fname);
		setRe(regNo);
		setProgram(prog);
		lastname = "";
		cgpa = -1;
	}

	Student(string fname, int regNo, string prog, string ln)
	{
		setFirstName(fname);
		setRe(regNo);
		setProgram(prog);
		setLastName(ln);
		cgpa = -1;
	}

	//Copy Constructor

	Student(Student& obj)
	{
		setFirstName(obj.firstname);
		setRe(obj.regNo);
		setLastName(obj.lastname);
		setCGPA(obj.cgpa);
		setProgram(obj.program);
	}


	// ALL Setter For Each Data Member

	void setFirstName(string fname1)
	{
		firstname = fname1;
	}

	void setRe(int  reg)
	{
		if (reg >= 501 && reg <= 565)
		{
			regNo = reg;
		}
		else
		{
			regNo = 0;
		}
	}

	void setLastName(string ln)
	{
		lastname = ln;
	}

	void setProgram(string prog)
	{
		program = prog;
	}
	void setCGPA(float cg)
	{
		if (cg >= 0 && cg <= 4)
		{
			cgpa = cg;
		}
		else
		{
			cgpa = -1;
		}
	 }

	// ALL Getter For Each Data Member

	string getFName()
	{
		return firstname;
	}
	string getLName()
	{
		return lastname;
	}

	int getRe()
	{
		return regNo;
	}

	string getProg()
	{
		return program;
	}
	float getCGPA()
	{
		return cgpa;
	 }

	//Member Function

	void set(int reg, string fname, string lname, string prog,float cg)
	{
		setFirstName(fname);
		setRe(reg);
		setLastName(lname);
		setCGPA(cg);
		setProgram(prog);
	}

	void read()
	{

		cout << "Enter The First Name of Employee :";
		getline(cin, firstname);

		cout << "Enter The Regno of Employee :";
		cin >> regNo;
		setRe(regNo);

		cout << "Enter The CGPA of Employee :";
		cin >> cgpa;
		setCGPA(cgpa);

		cin.ignore();
		cout << "Enter The Last Name of Employee :";
		getline(cin, lastname);

		cout << "Enter The Program of Employee :";
		getline(cin, program);

	}

	void write() {

		cout << firstname << "\t\t\t" << regNo << "\t\t" << lastname << "\t\t\t" << program << "\t\t\t" <<cgpa<< endl;

	}


	bool IsFistSemester()
	{
		if (cgpa == -1) {
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isPromoted()
	{
		if (cgpa >= 2) {
			return true;
		}
		else
		{
			return false;
		}
	}

	float getPercentage()
	{
		if (cgpa >= 0) {
			return (cgpa / 4.0) * 100;
		}
		else
		{
			return -1;
		}
	}

	//destructor

	~Student()
	{
		cout << "Destructor Executed...." << endl;
	}
};


int main()
{

	Student obj1("Haider",50, "BSCS", "Ali"),obj2("Qasim", 2, "Junaid", "BSIT", 2),obj3(obj1);
	obj1.read();
	if (obj1.IsFistSemester()) {
		cout << "YOU ARE IN FIRST SEMESTER" << endl;
	}
	if (obj1.isPromoted()) {
		cout << "YOU ARE PROMOTED" << endl;
	}

	obj1.write();

	obj2.write();
	obj3.write();
	
	return 0;
}
