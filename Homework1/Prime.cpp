#include<iostream> //Declares library iostream is being used
using namespace std; //Using namespace std as to not write out std::cout << or otherwise

int main(void) { //Declaration of main function with no input
	int in,x,y=0; //Declaration of variables in, x, and y that is initialized
	cout << "Please enter a number: "; //Outputs "Please enter a number: "
	cin >> in; //Takes the input and puts it in the variable in
	cout << "Prime ?: "; //Outputs "Prime ?:"
	for (int i = 2; i < in; i++) { //Goes through a loop starting at i=2 going all the way til number in
		x = in % i; //x is equal to input divided by whatever number the loop is on
		if (x == 0) { //if x==0 then then it is known that the number is composite
			y = 1; //Changes flag from 0 to 1
			cout << "False"; //Outputs "False"
			break; //Exits the loop
		}
	}
	if (y == 0) { //If is equal to 0 do this
		cout << "True"; //Outputs "True"
	}
	return 0; //Exits the program
}