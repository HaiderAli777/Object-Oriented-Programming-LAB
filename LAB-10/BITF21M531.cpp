#include "iostream"

using namespace std;

class FeetInches
{
private:
	int feet;			// To hold a number of feet
	int inches;			// To hold a number of inches

	void simplify()
	{
		if (inches >= 12)
		{
			feet += (inches / 12);
			inches = inches % 12;
		}
		else if (inches < 0)
		{
			feet -= ((abs(inches) / 12) + 1);
			inches = 12 - (abs(inches) % 12);
		}
	}

public:
	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
	}

	FeetInches(const FeetInches& right)
	{
		feet = right.feet;
		inches = right.inches;
		simplify();
	}

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
		simplify();
	}

	// Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	FeetInches operator + (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches + right.inches;
		temp.feet = feet + right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator - (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches - right.inches;
		temp.feet = feet - right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator * (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches * right.inches;
		temp.feet = feet * right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator ++ ()
	{
		++inches;
		simplify();

		return *this;
	}

	FeetInches operator ++ (int)
	{
		FeetInches temp(feet, inches);

		inches++;
		simplify();

		return temp;
	}

	FeetInches operator -- ()
	{
		--inches;
		simplify();

		return *this;
	}

	FeetInches operator -- (int)
	{
		FeetInches temp(feet, inches);

		inches--;
		simplify();

		return temp;
	}

	bool operator > (const FeetInches& right)
	{
		bool status;

		if (feet > right.feet)
			status = true;
		else if (feet == right.feet && inches > right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator < (const FeetInches& right)
	{
		return !(*this > right);
	}

	bool operator >= (const FeetInches& right)
	{
		bool status;

		if (feet >= right.feet)
			status = true;
		else if (feet == right.feet && inches >= right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator <= (const FeetInches& right)
	{
		return !(*this >= right);
	}

	bool operator == (const FeetInches& right)
	{
		bool status;

		if (feet == right.feet && inches == right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator != (const FeetInches& right)
	{
		return !(*this == right);
	}

	friend ostream& operator << (ostream&, const FeetInches&);
	friend istream& operator >> (istream&, FeetInches&);
};

ostream& operator << (ostream& out, const FeetInches& obj)
{
	out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

	return out;
}

istream& operator >> (istream& in, FeetInches& obj)
{
	cout << "Enter Feet:\t";
	in >> obj.feet;

	cout << "Enter Inches:\t";
	in >> obj.inches;

	return in;
}

class RoomDimension
{
	FeetInches lenght;
	FeetInches width;

public:
	

	void setLength(FeetInches len)
	{
		this->lenght = len;
	}

	void setWidth(FeetInches Width)
	{
		this->width = Width;
	}

	FeetInches getLenght()
	{
		return lenght;
	}
	FeetInches getWidth()
	{
		return width;
	}

	RoomDimension(FeetInches W, FeetInches L)
	{
		this->lenght = L;
		this->width = W;
	}

	FeetInches AreaFun()
	{
		return lenght * width;
	}

	void DisplayFunc()
	{
		cout << lenght.getFeet() << endl;
		cout << width.getInches() << endl;
	}
	

};

class RoomCarpet
{
	RoomDimension roomSize;
	float costPersquareroot;

public:

	RoomCarpet(RoomDimension obj,float f):roomSize(obj),costPersquareroot(f)
	{
		
	}

	void setRoomSize(RoomDimension roomSize)
	{
		this->roomSize = roomSize;
	}

	void setWidth(float costPer)
	{
		this->costPersquareroot = costPer;
	}

	RoomDimension getRoomSize()
	{
		return roomSize;
	}
	float getCostPersquareRoot()
	{
		return costPersquareroot;
	}

	void RoomCarpetDisplay()
	{
	
		cout << costPersquareroot;
		cout << roomSize.AreaFun();
	}

	

	float TotalCost()
	{
		return costPersquareroot*roomSize.AreaFun().getFeet();
	}


};

int main()
{
	FeetInches len(3, 8);
	FeetInches  wid(5, 8);
	RoomDimension R(len, wid);
	RoomCarpet Red(R,2.2f);
	cout << "The Total Cost" << endl;
	cout<< Red.TotalCost();



}