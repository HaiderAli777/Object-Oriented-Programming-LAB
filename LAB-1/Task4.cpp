#include"iostream"
#include"string"
using namespace std;
int main() {
	string str;
	int count = 0, cd = 0, cA = 0, cl = 0;
	do {
		if (count == 0 || cd == 0 || cA == 0 || cl == 0) {
			cout << "Enter The Password : ";
			getline(cin, str);
		}
		for (int i = 0;i < str.length();i++) {
			if (str.length() >= 6 && count < 1) {
				count++;
			}
			if (((str[i] >= 97 && str[i] <= 122) && cl < 1)) {
				cl++;
			}
			if (((str[i] >= 65 && str[i] <= 90) && cA < 1)) {
				cA++;
			}
			if (((str[i] >= 48 && str[i] <= 57) && cd < 1)) {
				cd++;
			}
		}
		if (count == 0) {
			cout << "Your Password Does not Contain 6 letters " << endl;
		}
		if (cl == 0) {
			cout << "Your Password Does not Have LowerCaseLettere " << endl;
		}
		if (cA == 0) {
			cout << "Your Password Does not Contain UpperCaseLetter " << endl;
		}
		if (cd == 0) {
			cout << "Your Password Does not Contain Digit " << endl;
		}
	} while (count == 0 || cA == 0 || cl == 0 || cd == 0);
	cout << "Your Pass Is Correct";
	return 0;
}