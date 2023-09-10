/*************************************************************************
    This is the main for our CheckingAcct project. You will be able to 
	see, by reading the code below, the names and parameters of the 
	functions that you will be creating in your CheckingAcct class
	(12 in total).

    You are NOT to alter this file except to uncomment function calls

	Patricia Lindner	Ohio University EECS	September 2023
*************************************************************************/
/*************************************************************************
    This version has been modified by commenting out all the function
    calls on the CheckingAcct object, allowing you to develop, compile
	and test each function one at a time. After you write a function 
    uncomment the call to that function, compile your project and test
    it with that option.
*************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "transaction.h"
#include "checking.h"
using namespace std;

/*  */
/**
 * @brief This function shows the user the menu, asks them to enter their choice and then returns the integer value of that choice.
 * 
 * @return int - the menu option chosen by the user
 */
int menu();

int main(){
    Transaction tmp;
    ifstream ifs; 			// used to open the input file
    ofstream ofs; 			// used to open the output file
    string user, userfile;
    int choice;  			// user menu choice
    double depamount;  		// amount of a deposit
    int rmnum;      		// Transaction number to be removed from CheckingAcct
    string other; 			// used in listing all transactions involving a certain entity

    cout << "Please enter your user name (No spaces): ";
    cin >> user;

    CheckingAcct myacct; // A default CheckingAcct is constructed
    userfile = user + ".txt";
    ifs.open(userfile.c_str());

	// if no file this is first running for this user
    if(!ifs.fail()){ 
		myacct.load_from_file(ifs);
		ifs.close();
    }

    do{
		choice = menu();
		switch(choice){
			case 1:
				cout << "Please enter amount of the deposit: $";
				cin >> depamount;
				myacct.deposit(depamount);
				break;
			case 2:
				myacct.new_transaction(cin);
				break;
			case 3:
				cout << "Account balance: $" << myacct.get_balance() << endl;
				break;
			case 4:
				//myacct.show_all(cout);
				break;
			case 5:
				cout << "Enter the number of the transaction to be removed: ";
				cin >> rmnum;
				myacct.remove(rmnum);
				break;
			case 6:
				//myacct.number_sort();
				break;
			case 7:
				//myacct.other_party_sort();
				break;
			case 8:
				//myacct.date_sort();
				break;
			case 9:
				while(cin.peek() == '\n' || cin.peek() == '\r'){
					cin.ignore(); // clear out leftover newlines
				}
				getline(cin, other);
				//myacct.show(other);
				break;
			case 10:
				//cout << "Your average transaction amount: $" << myacct.average() << endl;
				break;
			case 0:
				cout << "Thank you for using the CheckingAcct program.\n";
				cout << "All alterations to the CheckingAcct will now be saved.\n";
				break;
			default:
				cout << "Invalid choice. Please choose again.\n";
				break;
		} // bottom of the switch
    } while(choice != 0);

	ofs.open(userfile.c_str());
	if(!ofs.fail()){
		myacct.save(ofs);
	    ofs.close();
	}

	return 0;
}

int menu(){
    int choice;
	
    cout << "Your CheckingAcct. Please choose from the following:\n";
    cout << " 1) Make a deposit.\n";
    cout << " 2) Make a transaction.\n";
    cout << " 3) See the CheckingAcct balance.\n";
    cout << " 4) See a listing of all transactions.\n";
    cout << " 5) Remove a Transaction.\n";
    cout << " 6) Sort by Transaction Number.\n";
    cout << " 7) Sort Alphabetically by other party.\n";
    cout << " 8) Sort by Date.\n";
    cout << " 9) Find all transactions involving the same other party.\n";
    cout << "10) Find the average of all transactions.\n";
    cout << " 0) Quit.\n";

    cin >> choice;

    return choice;
}