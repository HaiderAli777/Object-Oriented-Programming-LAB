#include <iostream>
using namespace std;

class Collection
{

	int* data;
	int size;

public:

	//Make Constructor

	Collection(int size)
	{

		if (size < 0)
		{
			this->size = 0;
		}
		else 
		{
			this->size = size;
		}

		
		data = new int[size];

		for (int i = 0;i < size;i++)
		{
			data[i] = 0;
		}

	}

	Collection(int ar[], int size)
	{

		if (size < 0)
		{
			this->size = 0;
		}
		else
		{
			this->size = size;
		}

		data = new int[size];

		for (int i = 0;i < size;i++)
		{

			data[i] = ar[i];

		}

	}

	Collection(const Collection& obj)
	{

		size = obj.size;
		data = new int[size];

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


	void setElement(int k, int i)

	{
		if (i<0 || i>size)
		{
			cout << "Your Index is Out of Range "<<endl;
		}
		else
		{
			data[i] = k;
		}
	}

	int countElement(int key)
	{
		int count=0;

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

	Collection operator=(const Collection &obj)
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
				data = new int[size];

				for (int i = 0;i < size;i++)
				{

					data[i] = obj.data[i];

				}

				return *this;

			}
		}
	}

	 Collection getSubCollection(int startIndex, int endIndex)
	{
		int count=0;
		int s = endIndex - startIndex;
		

		if (s > 0 && startIndex>=0 &&endIndex<size)
		{

			Collection object(s + 1);

			for (int i = startIndex;i <=endIndex;i++)
			{
			
				object.data[count] = data[i];
					++count;
		  }
			
			return object;

		}
		else
		{
			cout << "SUBCOLLECTION IS NOT CREATED::" << endl;
			Collection object(0);
			object.data = NULL;
			return object;
		}
	}

	 //stream Insertion operator

	 friend ostream& operator<< (ostream& print, const Collection& obj)
	 {

		 for (int i = 0;i < obj.size;i++)
		 {
			 print << "First Element " << i << " :";
			 print << obj.data[i] << endl;
		 }
		 return print;
	 }

	 friend istream& operator>> (istream& inp, const Collection& obj)
	 {

		 for (int i = 0;i < obj.size;i++)
		 {
			 cout << "First Element " << i << " :";
			 inp >> obj.data[i];
		 }
		 return inp;
	 }

	//Addition Operator

	Collection operator+(const Collection& obj)
	{
		
		if (obj.size == size)
		{
			Collection obj1(size);

			for (int i = 0;i < size;i++)
			{

				obj1.data[i] = data[i] + obj.data[i];

			}
			return obj1;
		}
		else
		{
			cout << "SIZE NOT MATCHED::" << endl;
			Collection obj1(0);
			obj1.data = NULL;
			return obj1;
		}
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

			int garbage = 99;
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

			int garbage = 99;
			return  garbage;
		}
	}


	bool operator-()
	{
		int counter = 0;

		for (int i = 0;i < size;i++)
		{
			if (data[i] <= 0)
			{
				counter++;
			}
		}

		if (counter == size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	


	//Make Default Constructor

	~ Collection()
	{
		delete []data;
	}


};

int main()
{
	int ar[10] = { 1,2,3,4,4,5,5,5,6,7 };
	int ar1[9] = { 0,-2,-3,-4,-4,-5,-5,-5,-6 };

	//Testing Constructor
	Collection obj1(ar,10);
	Collection obj2(ar1,9);

	//Testing >> << operator
	
	//cin >> obj1;
	cout << obj1;
	cout << obj2;

	//Testing
	cout<< obj1.countElement(4)<<endl;

	cout<< obj1.getSize()<<endl;
	 
	//Testing + operator
	cout << "Addition" << endl;
	cout << obj1 + obj2;

	//Testing - operator
	cout << "Unary Operator::";
	cout << -obj2<<endl;

	//Testing [] operator

	
	cout << obj1[11] << endl;

	//Set Eleemnt

	 obj1.setElement(1, 8);
	 cout << obj1[8] << endl;
	
	 //Testing getting array of targeted indexing
	 cout << "GET SUBCOLLECTION:" << endl;

	 cout<< obj1.getSubCollection(5, 9);

	

	return 0;
}