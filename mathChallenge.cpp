#include <iostream>
#include <string>
using namespace std;

void createXYZ(string& str, string& X, string& Y, string& Z, char& operation, bool& isXInX, bool& isXInY) {

	bool isOper = false, isEqual = false;
	int i = 0, strLen = str.length();

	while (i < strLen) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			operation = str[i];
			isOper = true;
		}
		if (str[i] == '=')
			isEqual = true;

		if (!isOper && str[i] >= '0' && str[i] <= '9' || str[i] == 'x' && !isOper) {
			X += str[i];
			if (str[i] == 'x') isXInX = true;
		}
		else if (isOper && str[i] >= '0' && str[i] <= '9' && !isEqual || str[i] == 'x' && isOper) {
			Y += str[i];
			if (str[i] == 'x') isXInY = true;
		}

		if (isEqual) {
			while (i < strLen) {
				if (str[i] != ' ' && str[i] != '=') Z += str[i];
				i++;
			}
		}
		i++;
	}
}

int returnMissingNumber(string& X, string& Y, string& Z, char& operation, bool& isXInX, bool& isXInY) {

	int result, resX, resY;
	if (isXInX) {

		result = stoi(Z);

		switch (operation) {
		case '+': resX = result - stoi(Y); break;
		case '-': resX = result + stoi(Y); break;
		case '*': resX = result / stoi(Y); break;
		case '/': resX = result * stoi(Y); break;
		}

		if (X.size() > 1)
		{
			string res = to_string(resX);
			int j = 0;
			while (X[j] == res[j])
				j++;

			return (int)res[j] - 48;
		}
		else
			return resX;
	}

	else if (isXInY) {

		result = stoi(Z);

		switch (operation) {
		case '+': resY = result - stoi(X); break;
		case '-': resY = result + stoi(X); break;
		case '*': resY = result / stoi(X); break;
		case '/': resY = result * stoi(X); break;
		}

		if (Y.size() > 1)
		{
			string res = to_string(resY);
			int j = 0;
			while (Y[j] == res[j])
				j++;

			return (int)res[j] - 48;
		}
		else
			return resY;
	}
	else {
		switch (operation) {
		case '+': result = stoi(X) + stoi(Y); break;
		case '-': result = stoi(X) - stoi(Y); break;
		case '*': result = stoi(X) * stoi(Y); break;
		case '/': result = stoi(X) / stoi(Y); break;
		}

		if (Z.size() > 1)
		{
			string res = to_string(result);
			int j = 0;
			while (Z[j] == res[j])
				j++;

			return (int)res[j] - 48;
		}
		else
			return result;
	}
}

int MathChallenge(string str) {

	string X, Y, Z;
	char operation = ' ';
	bool isXInX = false, isXInY = false;

	createXYZ(str, X, Y, Z, operation, isXInX, isXInY);
	cout << "X = " << X << " Y = " << Y << " Z = " << Z << endl;

	return returnMissingNumber(X, Y, Z, operation, isXInX, isXInY);
	
}

int main(void) {

	cout << "x = " << MathChallenge("12x4 + 100 = 1394") << endl << endl;
	cout << "x = " << MathChallenge("1294 + 1x0 = 1394") << endl << endl;
	cout << "x = " << MathChallenge("1294 + 100 = 1x94") << endl << endl;

	return 0;
}