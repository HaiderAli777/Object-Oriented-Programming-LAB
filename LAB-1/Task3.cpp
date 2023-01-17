#include "iostream"
#include"string"
using namespace std;
int getAtring(string s) {
	int w = 0;
	for (int i = 0;i < s.length();i++) {
		if (s[i] == ' ') {
			 w++;
		}
	}
	return w + 1;
}
int main() {
	string str;
	cout << "Enter The String :";
	getline(cin, str);
	int w=getAtring(str);
	cout << "The Number Of Word In String is : "<<w;
	return 0;
}