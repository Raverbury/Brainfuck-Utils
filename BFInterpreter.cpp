#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>

using namespace std;

class Stack {
	private:
		struct Node {
			int data;
			Node* next;
			Node(const int& _data) : data(_data), next(NULL) {}
		};
		Node* top;
	public:
		Stack() : top(NULL) {}
		void push(const int& _data) {
			Node* newNode = new Node(_data);
			if(!top) {
				top = newNode;
			}
			else {
				newNode->next = top;
				top = newNode;
			}
		}
		int pop() {
			int tmpData = top->data;
			Node* tmpNode = top;
			top = top->next;
			delete tmpNode;
			return tmpData;			
		}
		int peek() {
			return top->data;
		}
		bool isEmpty() {
			return (!top);
		}
		~Stack() {
			while(top) {
				pop();
			}
		}
};

int runProgram(string src) {
	char memory[30000] = {0};
	char* ptr = memory;
	int ptrPos = 0;
	Stack bracketPos;
	int state = 0;
	for(int i = 0; i < src.length(); i++) {
		// cout << "Parsing " << src[i] << "\n";
		switch(src[i]) {
			case '<': {
				ptr--;
				ptrPos--;
				if(ptrPos < 0) state = -1;
				break;
			}
			case '>': {
				ptr++;
				ptrPos++;
				if(ptrPos >= 30000) state = -1;
				break;
			}
			case '+': {
				++*ptr;
				break;
			}
			case '-': {
				--*ptr;
				break;
			}
			case '.': {
				cout << *ptr;
				break;
			}
			case ',': {
				string tmp;
				cout << "Waiting for an input: ";
				getline(cin, tmp);
				*ptr = static_cast<int>(tmp[0]);
				break;
			}
			case '[': {
				bracketPos.push(i);
				break;
			}
			case ']': {
				if(bracketPos.isEmpty()) state = -2;
				else {
					if(*ptr == 0) {
						bracketPos.pop();
					}
					else {
						i = bracketPos.peek();
					}
				}
				break;
			}
			default: {
				cout << "Unrecognized operator " << src[i] << ", skipping...\n";
				break;
			}
		}
		if(state < 0) {
			switch(state) {
				case -1: {
					cout << "Pointer out of range.\n";
					break;
				}
				case -2: {
					cout << "No opening bracket.\n";
					break;
				}
				default: {
					cout << "Error not documented.\n";
					break;
				}
			}
			return -1;
		}
	}
	return 1;
}

int main() {
	cout << "This program will attempt to process a brainfuck program. (Yes it's a real language)\n";
	string src = "";
	cout << "Do you wish to read the code from a file? (File must be named \"output.bf\")\n[y = yes/other keys = no] ";
	getline(cin, src);
	if(src[0] == 'y') {
		ifstream file("output.bf");
		file >> src;
	}
	else {
		cout << "Please provide a code snippet:\n";
		getline(cin, src);
	}

	cout << "\nConsole:\n\n";
	if(runProgram(src) >= 0) {
		cout << "\n\nProgram has finished running.\n";
	}
	else {
		cout << "\n\nProgram has returned with an error.\n\n";
	}
	cout << "Press any button to continue...\n";
	getch();
	return 0;
}
