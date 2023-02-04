
#include "iostream"
using namespace std;
#include "string"
void Pass(char *ptr){
	//we can acces the other one also
	int counter = 0,k=0;
	int len = strlen(ptr);
	char ar[50];
	if (ptr!=NULL) {
		for (int i = 0;i < len;i++) {
			ar[k++] = ptr[i];
			counter++;
			if (ptr[i] == ' ' || ptr[i] == NULL) {
				ar[k] = NULL;
				cout << ar << " = " << counter - 1 << endl;
				k = counter = 0;
			}
		}
	}
	else
	{
		cout << "The String is empty";
	}

}
int main()
{
	string str;
	cout << "Enter The line :";
	getline(cin,str);
	Pass(&str[0]);//here we cannot pass the string like it we just pass the starting character of string 
	return 0;
	//and there is one more differnece between them is that in character array we have to put NULL IN THE end and in string we already have null in the null 
	//string and character arrray terminated at null
}