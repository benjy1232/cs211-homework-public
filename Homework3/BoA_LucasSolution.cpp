#include <iostream>
#include <iomanip>		//used for setw which is used for formatting cout output
using namespace std;

bool startsWith(char name[], int nameIdx, char search[], int searchIdx){
    if(name[nameIdx] == '\0' || search[searchIdx] =='\0'){ //~(A.B)=~A v ~B ~(AvB) = ~A.~B
        if(search[searchIdx]=='\0'){
            return true;
        }
        return false;
    }
    if(name[nameIdx]==search[searchIdx]){
        return startsWith(name, nameIdx+1, search, searchIdx+1);
    }
    return false;
}

bool searchHelper(char name[], int idx, char search_str[]){
    if(name[idx]=='\0'){
		return false;
	}
	if(startsWith(name, idx, search_str, 0)){
        return true;
    }
    return searchHelper(name, idx+1, search_str);
}

bool IsSubString(char name[], char search_str[]){
    return searchHelper(name,0, search_str);
}
// bool IsSubString(char name[], char search_str[],  int start = 0, int searchStart=0, bool yes = 0)
// {
// 	/*
// 	Searches the character array for the first occurrence of the sequence specified by its arguments.
// 	*/
// 	// int i = 0;
// 	// int found_flag = 0;
// 	// int idx = 0;
// 	// while (name[i] != '\0' && search_str[idx] != '\0')
// 	// {
// 	// 	if (search_str[idx] == name[i])
// 	// 	{
// 	// 		if (idx == 0)
// 	// 		{
// 	// 			found_flag = 1;
// 	// 		}
// 	// 		else
// 	// 		{
// 	// 			found_flag = found_flag * 1;
// 	// 		}
// 	// 		idx++;
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		found_flag = 0;
// 	// 		idx = 0;
// 	// 	}

// 	// 	i++;
// 	// }
// 	// if (search_str[idx] == '\0')
// 	// 	return found_flag;
// 	// else
// 	// 	return false;
// }

int select_user(char cust_names[][100], int num_cust)
{
	/*
	Selects a user by searching for part of their name
	*/
	char search_user[100];
	int cust_idx = 0;
	int count = 0;
	int selected_user_id;

	while (count != 1)
	{
		cout << "Search user by part of name: ";
		cin.ignore();
		cin.getline(search_user, 100);
		cust_idx = 0;
		count = 0;
		selected_user_id = -1;
		for (cust_idx = 0; cust_idx < num_cust; cust_idx++)
		{
			if (IsSubString(cust_names[cust_idx], search_user))
			{
				selected_user_id = cust_idx;
				cout << "User match: " << cust_names[cust_idx] << endl;
				count++;
			}
		}
		if (count > 1)
		{
			cout << endl << "More than one user found with that substring. Please search again with more characters ************************* " << endl;
		}
		else if (count == 0)
		{
			cout << endl << "No user found with that substring. Please search again *************************" << endl;
		}
	}
	return selected_user_id;
}

void withdraw_from_account(double acct_bal[], double loan_bal[], int account_id, double withdraw_amount)
{
	//withdraw the amount if account has enough balance
	//otherwise, if withdraw amount is more than account balance, charge an overdraft fee and add extra withdrawn amount to loan dues
	double overdraft_fee = 35;
	if (withdraw_amount < 0)
	{
		cout << "Error: Cannot withdraw a negative amount *************************" << endl << endl;
		return;
	}

	acct_bal[account_id] = acct_bal[account_id] - withdraw_amount;

	if (acct_bal[account_id] < 0)
	{
		cout << "Withdrawing amount larger than current account balance. Additional overdraft fee of $35 shall be charged. *************************" << endl << endl;
		loan_bal[account_id] = -acct_bal[account_id] + overdraft_fee;
		acct_bal[account_id] = 0;
	}
}

void deposit_to_account(double acct_bal[], double loan_bal[], int account_id, double deposit_amount)
{
	//deposit the amount if account has no loans
	//otherwise, if deposit amount is more than outstanding loan, add extra amount to account balance
	if (deposit_amount < 0)
	{
		cout << "Error: Cannot deposit a negative amount *************************" << endl << endl;
		return;
	}
	if (loan_bal[account_id] == 0.0)
	{
		acct_bal[account_id] += deposit_amount;
	}
	else
	{
		loan_bal[account_id] -= deposit_amount;
		if (loan_bal[account_id] < 0)
		{
			acct_bal[account_id] = -loan_bal[account_id];
			loan_bal[account_id] = 0;
		}
	}
}

void print_account_details(char cust_names[][100], double acct_bal[], double loan_bal[], int num_cust)
{
	/*
	Prints account statements for all users
	*/
	if (num_cust == 0)
	{
		//print header
		cout << "--------------------------------------------------------------------" << endl;
		cout << "\t\t\t ACCOUNT DETAILS " << endl;
		cout << "--------------------------------------------------------------------" << endl;
		cout << "CUSTOMER NAME -> ACCOUNT BALANCE -> LOAN DUE" << endl;
		cout << "--------------------------------------------------------------------" << endl;
		return;
	}

	print_account_details(cust_names, acct_bal, loan_bal, num_cust - 1);
	int print_idx = num_cust - 1;
	cout << std::left << setw(40) << cust_names[print_idx] << " $" << setw(20) << acct_bal[print_idx] << "$" << setw(20) << loan_bal[print_idx] << endl;
}


int print_menu()
{
	/*
	Prints the menu
	*/
	int menu_select = -1;

	while (menu_select < 0 || menu_select > 3)
	{
		cout << "--------------------------------------------------------------------" << endl;
		cout << "\t\t MENU" << endl;
		cout << "--------------------------------------------------------------------" << endl;
		cout << "1: Show Account Details" << endl;
		cout << "2: Deposit amount to account" << endl;
		cout << "3: Withdraw amount from account" << endl;
		cout << "0: Exit" << endl;
		cout << "--------------------------------------------------------------------" << endl;
		cout << "Select menu option [1, 2, 3, 0] : ";
		cin >> menu_select;
		cout << "--------------------------------------------------------------------" << endl;
		if (menu_select < 0 || menu_select > 3)
			cout << "Error: Incorrect menu item selected. Please select again *************************" << endl << endl;
	}

	return menu_select;
}



int main()
{
	const int num_customers = 5;
	char customer_names[num_customers][100] = {
		"john fitzgerald kennedy",
		"william shakespeare",
		"salvador felipe jacinto dali domenech",
		"elvis aaron presley",
		"elizabeth alexandra mary windsor" };


	double customer_account_balances[num_customers] = { 100.5, 120.75, 50.2, 150.15, 200.99 };
	double customer_loan_dues[num_customers] = { 0.0, 0.0, 0.0, 0.0, 0.0 };


	cout << "************************* Welcome to BANK OF ANTARCTICA *************************" << endl << endl << endl;



	print_account_details(customer_names, customer_account_balances, customer_loan_dues, num_customers);
	cout << endl << endl << endl;
	double amount;
	int acct_id;
	int menu_select = -1;
	while (menu_select != 0)
	{
		menu_select = print_menu();
		switch (menu_select)
		{
		case 1:		// Show Account Details
			print_account_details(customer_names, customer_account_balances, customer_loan_dues, num_customers);
			cout << endl << endl << endl;
			break;
		case 2:		// Deposit amount to account
			acct_id = select_user(customer_names, num_customers);
			cout << "Please enter amount to DEPOSIT into the account of: " << customer_names[acct_id] << " :: $";

			cin >> amount;
			deposit_to_account(customer_account_balances, customer_loan_dues, acct_id, amount);
			print_account_details(customer_names, customer_account_balances, customer_loan_dues, num_customers);
			cout << endl << endl << endl;
			break;
		case 3:		// Withdraw amount from account
			acct_id = select_user(customer_names, num_customers);
			cout << "Please enter amount to WITHDRAW from the account of: " << customer_names[acct_id] << " :: $";

			cin >> amount;
			withdraw_from_account(customer_account_balances, customer_loan_dues, acct_id, amount);
			print_account_details(customer_names, customer_account_balances, customer_loan_dues, num_customers);
			cout << endl << endl << endl;
			break;
		}
	}


	cout << endl << endl << "Final Details:" << endl;
	print_account_details(customer_names, customer_account_balances, customer_loan_dues, num_customers);
	cout << endl << endl << endl;

	cout << "THANK YOU!!! for using BANK OF ANTARCTICA services" << endl;

	return 0;
}