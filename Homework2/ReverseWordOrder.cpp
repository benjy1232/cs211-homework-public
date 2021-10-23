#include<iostream> //Declaration of library iostream
using namespace std;//Use of namespace std

void swap(char string[], int start_loc, int end_loc); //Declaration of function swap

int main(void) {//Declaration of function main with input void
    const int SIZE = 1000; //Declaration of constant SIZE of size 1000
    char string[SIZE] = {}; //Declaration of character array "string" of size SIZE
    char newString[SIZE] = {}; //Declaration of character array "newString" of size SIZE
    char temp = 1; //Declaration of character temp to be used on later
    int end_loc; //Declaration of int end_loc for end_location
    int start_loc = 0; //Declaration of in start_loc for start_location
    int x = 0; //Declaration of int x with value 0
    int i = 0;//Declaration of int i with value 0
    int mid_loc = 0; //Declaration of int mid_loc for mid_location with value 0
    bool flag = 0; //Declaration of bool flag with value 0
    bool lastFirst = 0; //Declaration of bool lastFirst with value 0 for last letter of first word

    cin.getline(string, SIZE); //Takes user input and stores it in character array "string"
    for (i = 0; i < SIZE; i++) {//For loop going through the program SIZE-1 times
        if (string[i] == ' ') {//If the value of element i in string is equal to a space, then do the following
            end_loc = i - 1;//Set end_location to be i-1
            if (lastFirst == 0) {//If we have not gotten past the first word, do this, otherwise skip
                temp = string[end_loc];//set char temp to be equal to the last letter of the first word; Has to do with 
                lastFirst = 1; //Sets flag lastFirst to be 1
            }
            mid_loc = (start_loc + end_loc) / 2;//Set mid_loc to be the middle point of start_loc and end_loc
            for (int j = start_loc; j <= mid_loc; j++) { //For loop going through the program mid_loc amount of times
                swap(string, start_loc + x, end_loc - x); //Go to function swap and input the following parameters: string, start_location+x, end_location-x
                x++;//Increment x by 1
            }
            x = 0; //Set x equal to 0
            start_loc = i + 1;//Set start location to be the next element in the array
        }
    }

    for (int j = 1; j < SIZE; j++) {//For loop that repeats SIZE amount of times
        newString[j - 1] = string[SIZE - j];//Sets newString element j equal to string element SIZE-j
    }

    //This for loop reverses the first word of newString because it is not reversed the first time
    for (int k = 0; k < SIZE; k++) {//For loop that repeats SIZE amount of times
        if (newString[k] == ' ' && flag == 0) {//If flag is set to 0 and element k of new string is a " " then do the following
            flag = 1; //Set flag equal to 1
            end_loc = k - 1; //Set end_loc equal to k-1
            start_loc = 0; //Set start_loc equal to 0
            mid_loc = (start_loc + end_loc) / 2; //Set mid_loc equal to half poitn of end_loc and start_loc
            for (int l = start_loc; l <= mid_loc; l++) { //For loop that repeats mid_loc+1 times
                swap(newString, start_loc + x, end_loc - x);//Go to function swap and input the following parameters: string, start_location+x, end_location-x
                x++; //Increments x by 1
            }
        }
    }
    //Outputs newString
    for (int m = 0; m < SIZE; m++) {//For loop that repeats SIZE amount of times
        cout << newString[m];//Outputs element m of newString
    }
    cout << temp;//Outputs the last letter of the first word in original string because it got lost somehow during the swap
    return 0;//Exits code with output 0
}

void swap(char string[], int start_loc, int end_loc) { //Definition of function swap
    if (string[start_loc] == string[end_loc]) { //if start location is same as finish location, then don't swap any characters
        return;
    }
    char temp = string[start_loc]; //Definition of char temp and sets it equal to string[start_loc]
    string[start_loc] = string[end_loc]; //Sets string[start_loc] equal to string[end_loc]
    string[end_loc] = temp; //Sets string[end_loc] equal to temp
    return;//Exits function void with no output
}