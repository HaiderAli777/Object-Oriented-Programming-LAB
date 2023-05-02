#include <iostream>
using namespace std;
template <typename T>

class Array
{

	T* data;
	int size;

public:

	//Make Constructor


	Array()
	{

		this->size = 5;
		data = new T[size];

		for (int i = 0;i < size;i++)
		{
			data[i] = 0;
		}

	}

	Array(int size)
	{

		if (size < 0)
		{
			this->size = 0;
		}
		else
		{
			this->size = size;
		}


		data = new T[size];

		for (int i = 0;i < size;i++)
		{
			data[i] = 0;
		}

	}

	

	Array(const Array& obj)
	{

		size = obj.size;
		data = new T[size];

		for (int i = 0;i < size;i++)
		{

			data[i] = obj.data[i];

		}

	}

	//Make Functions

	int getSize()
	{
		return size;
	}


	void setElement(T k, int i)

	{
		if (i<0 || i>size)
		{
			cout << "Your Index is Out of Range " << endl;
		}
		else
		{
			data[i] = k;
		}
	}

	int countElement(T key)
	{
		int count = 0;

		for (int i = 0;i < size;i++)
		{
			if (data[i] == key)
			{
				count++;
			}
		}

		return count;


	}


	//Make Assignment Operator

	Array operator=(const Array& obj)
	{
		if (this != &obj)
		{
			if (size == obj.size)
			{
				for (int i = 0;i < size;i++)
				{
					data[i] = obj.data[i];
				}

				return *this;
			}
			else
			{
				delete[] data;
				size = obj.size;
				data = new T[size];

				for (int i = 0;i < size;i++)
				{

					data[i] = obj.data[i];

				}

				return *this;

			}
		}
	}

	Array getSubArray(int startIndex, int endIndex)
	{
		int count = 0;
		int s = endIndex - startIndex;


		if (s > 0 && startIndex >= 0 && endIndex < size)
		{

			Array object(s + 1);

			for (int i = startIndex;i <= endIndex;i++)
			{

				object.data[count] = data[i];
				++count;
			}

			return object;

		}
		else
		{
			cout << "SUBCOLLECTION IS NOT CREATED::" << endl;
			Array object(0);
			object.data = NULL;
			return object;
		}
	}

	//stream Insertion operator

	friend ostream& operator<< (ostream& print, const Array& obj)
	{

		for (int i = 0;i < obj.size;i++)
		{
			print << "First Element " << i << " :";
			print << obj.data[i] << endl;
		}
		return print;
	}

	friend istream& operator>> (istream& inp, const Array& obj)
	{

		for (int i = 0;i < obj.size;i++)
		{
			cout << "First Element " << i << " :";
			inp >> obj.data[i];
		}
		return inp;
	}

	//Addition Operator

	bool operator==(const Array& obj1) const
	{
		
		if (obj1.size == size)
		{
			
			for (int i = 0;i < size;i++)
			{

				if (obj1.data[i] != data[i])
				{
					return false;
				}

			}

			return true;
		}
		else
		{
			return false;
		}

		
	}

	Array operator+(const Array& obj)const
	{
		int counter = 0;
		Array obj1;
		obj1.size = size + obj.size;
		obj1.data = new T[obj1.size];

		for (int i = 0;i < obj1.size;i++)
		{
			if (i < size)
			{
				obj1.data[i] = data[i];
			}
			else
			{
				obj1.data[i] = obj.data[counter];
				counter++;
			}
			

		}

		return obj1;

	}

	//Here Make a Subscript

	int& operator[](int index)
	{

		if (index >= 0 && index < size)
		{
			return data[index];
		}
		else
		{
			cout << "Index Is Out of Bound" << endl;

			int garbage = -1;
			return  garbage;
		}
	}

	int operator[](int index) const
	{

		if (index >= 0 && index < size)
		{
			return data[index];
		}
		else
		{

			cout << "Index Is Out of Bound" << endl;

			int garbage = -1;
			return  garbage;
		}
	}

	//Make Default Constructor

	~Array()
	{
		delete[]data;
	}


};

int main()
{


	//Testing >> << operator
	Array<int>obj1;
	Array <int> obj2;
	

	cin >> obj1;
	cin >> obj2;

	Array <int> obj3 = obj2;


	cout << obj1 + obj2;

	cout << (obj1==obj2);

	cout << obj3;

	cout << obj3.getSubArray(2, 4);

	obj2[0] = 0;

	cout << obj2;



	return 0;
}