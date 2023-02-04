#include "iostream"
using namespace std;
  int *   Pass(const int arr[], int arSize,int &newAr) 
  {

	  int odd = 0,news,*dyna,j=0;


	  if (arr[0] == NULL)
	  {
		  return NULL;
	  }

	  else
	  {


	  if (arSize % 2 == 0) 
	  {
		  news = arSize / 2;
		  newAr = news;
		   dyna = new int[news];
	  }


	  else
	  {
		   odd = 1;
		   news = arSize / 2;
		   newAr = news+1;
		   dyna = new int[newAr];
	  }


	  for (int i = 0;i <arSize;i++)
	  {
		  if (j < news) {
			  *(dyna + j) = arr[i] + arr[i + 1];
			  i++;
			  j++;
		  }
		
	  }


	  if (odd == 1)
	  {
		  *(dyna + j) = arr[arSize-1];
	  }


	return dyna;
	}


	}

int main()
{
	int newAsize=0;

	int arr[3] = {1,2,4};

	int *p=Pass(arr, 3, newAsize);

	if (p != NULL)
	{
		for (int i = 0;i < newAsize;i++)
		{
			cout << *(p + i) << endl;
		}
	}
	else
	{
		cout << "There is No Value In Aray";
	}


	return 0;

}