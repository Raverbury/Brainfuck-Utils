#include<iostream>
#include<sstream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<conio.h>

using namespace std;

string intToPlus(int i) {
	string str = "";
	while(i > 0) {
		str.append("+");
		i--;
	}
	return str;
}

string charToBF(char c) {
	int value = static_cast<int>(c);
	int divisor = rand() % 7 + 6; // range: 6 to 12
	int quotient = static_cast<int>(value / divisor);
	int remainder = value % divisor;
	string strDivisor = intToPlus(divisor);
	string strQuotient = intToPlus(quotient);
	string strRemainder = intToPlus(remainder);
	stringstream ss;
	ss << ">" << strDivisor << "[<" << strQuotient << ">-]<" << strRemainder << ".>";
	return ss.str();
}

string stringToBF(string s) {
	stringstream ss;
	for(int i = 0; i < s.length(); i++) {
		// cout << "Parsing " << s[i] << "...\n";
		ss << charToBF(s[i]);
	}
	string result = ss.str();
	result.pop_back();
	return result;
}

int main() {
	cout << "This program will convert any string into a brainfuck script. (Yes it's a real language)\n";
	srand(time(NULL));
	string input;
	cout << "Please provide a string:\n";
	getline(cin, input);
	string result = stringToBF(input);
	cout << "Result:\n\n" << result << "\n\n";
	
	cout << "Do you wish to write result to a file? (Recommended for long output)\n[y = yes/other keys = no] ";
	getline(cin, input);
	if(input[0] == 'y') {
		ofstream file("output.bf");
		file << result;
		file.close();
		cout << "Result has been written to a file named \"output.bf\"\n";
	}
	cout << "Press any button to continue...\n";
	getch();
	return 0;
}
