#include<iostream> //Declares library iostream being used
using namespace std; //Declares namespace being used is std as to not need to write std::cout

int main(void) { //Declares main function with input void
	int x, y, z; //Declares variables x,y, and z
	cout << "Please enter first number: "; //Outputs "PLease enter first number"
	cin >> x; //inputs first variable as x
	cout << "Please enter second number: "; //Outputs "Please enter second number"
	cin >> y; //Inputs second variable as y
	cout << "Please enter third number: "; //Outputs "Please enter third number"
	cin >> z; //Inputs third variable as z

	/*POSSIBLE PERMUTATIONS
	XYZ
	XZY
	YXZ
	YZX
	ZXY
	ZYX*/

	//This large if-else statement checks for all possible permutations
	
	if (x > y && x > z) { //checks for x being largest number
		if (y > z) { //checks for y being bigger than z
			cout << "The largest number is: " << x << endl; //Prints out "The largest number is: " then whatever x is with a new line at the end
			cout << "The next largest number is: " << y << endl; //Prints out "The next largest number is: " then whatever y is with a new line at the end
			cout << "The smallest number is: " << z << endl;//Prints out "The smallest number is: " with whatever z is with a new line at the end
		}
		else { //if y is not greater than z, then it will print z is greater than y
			cout << "The largest number is: " << x << endl; // Prints out "The largest number is: " then whatever x is with a new line at the end
			cout << "The next largest number is: " << z << endl; // Prints out "The next largest number is: " then whatever z is with a new line at the end 
			cout << "The smallest number is: " << y << endl; // Prints out "The smallest number is: " then whatever y is with a  new line at the end
		}
	}
	else if (y > x && y > z) { //Checks for y being the largest number
		if (x > z) { // Checks for x being greater than z
			cout << "The largest number is: " << y << endl; //Prints out "The largest number is: " then whatever y is with a new line at the end
			cout << "The next largest number is: " << x << endl; //Prints out "The next largest number is: " then whatever x is with a new line at the end
			cout << "The smallest number is: " << z << endl; //Prints out "The smallest number is: " then whatever z is with a new line at the end
		}
		else {//Checks for z being greater than y
			cout << "The largest number is: " << y << endl; //Prints out "The largest number is: " Then whatever y is with a new line at the end
			cout << "The next largest number is: " << z << endl; //Prints out "The next largest nujmber is: " then whatever z is with a new line at the end
			cout << "The smallest number is: " << x << endl; //Prints out "The smallest number is: " then whatever x is with a new line at the end
		}
	}
	else { //IF x and y are not the greatest number, then z must be the greatest number
		if (x > y) {//Checks for x being greater than y
			cout << "The largest number is: " << z << endl; //Prints out "The largest number is: " with whatever z is with a new line at the end
			cout << "The next largest number is: " << x << endl; //Prints out "The next largest number is: " with whatever x is with a new line at the end
			cout << "The smallest number is: " << y << endl; // Prints out "The smallest number is: " with whatever y is with a new line at the end
		}
		else {
			cout << "The largest number is: " << z << endl; //Prints out "The largest number is: " with whatever z is with a new line at the end
			cout << "The next largest number is: " << y << endl; //Prints out "The next largest number is: " with whatever y is with a new line at the end
			cout << "The smallest number is : " << x << endl; //Prints out "The smallest number is: " with whatever z is with a new line at the end
		}
	}
	return 0; //exits the program
}