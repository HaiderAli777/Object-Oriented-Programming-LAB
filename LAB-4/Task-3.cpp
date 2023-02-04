#include "iostream"
using namespace std;
char * ReverseCase(char *ptr) {
	int lenght = 0;
	for (int j = 0;ptr[j] != NULL;j++)
	{
		lenght++;
	}
	//cout << lenght;
	char * S = new char [lenght];
	int k = 0;
	if (ptr[0] != NULL) {
		for (int i = lenght - 1;i >= 0;i--)
		{
			if (ptr[i] >= 65 && ptr[i] <= 90)
			{
				S[k] = ptr[i] + 32;
				k++;
			}
			else if (ptr[i] >= 97 && ptr[i] <= 122)
			{
				S[k] = ptr[i] - 32;
				k++;
			}
			else
			{
				S[k] = ptr[i];
				k++;
			}
		}
		S[k] = NULL;

		//cout << S;
		return S;
	}
	else {
		return NULL;
	}
}
int main()
{
	char str[50] = "Hello I am Haider";
	char* p = ReverseCase(str);
	if (p != NULL) {
		cout << p;
	}
	else {
		cout << "The string is null";
	}
	
	return 0;
}