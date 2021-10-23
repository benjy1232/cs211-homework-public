#include<iostream> //Declares that iostream is library being used
using namespace std; //Uses namespace std as to not write out std::cout, etc...

int main(void) { //Declares function main exists and takes input void
	int x=0, y=1, in,z=0; //Declares variables x, y, in, and z. X has value 0, y has value 1, z has value 0
	cout << "Please enter a number: "; //Outputs "Please enter a number: "
	cin >> in; //Inputs the input from terminal to variable in
	for (int i = 0; i < in; i++) { //Goes through a loop starting with i=0, while i is less than in, and increments i
		cout << x << ", "; //Outputs the value of x followed by a comma then a space
		z = y; //Moves the values of y to z
		y = x; //Moves the value of x to y
		x = z + y; //Value of x is equal to z + y or the two previous numbers in the sequence
	}
	return 0; //exits the program
}