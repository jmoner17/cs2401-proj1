/*************************************************************************
    This is the implementation file for the Transaction class. For more 
		information about the class see Transaction.h.
    Students are expected to implement some of the functions shown 
		below.
	Patricia Lindner	Ohio University EECS	September 2023
*************************************************************************/
#include "transaction.h"
using namespace std;

Transaction::Transaction(Date d, string p, int num, double amt){
	num = num;
	date = d;
	other_party = p;
	amount = amt;
}

// * Data is input in the order: num, date, other_party, amount
// * Functions not of the object type do not utilize the getline function as it is too much work :(
void Transaction::make_transaction(std::istream& ins){

	/** Creating a temporary variable to get rid of the '\n' character as 
		the previous value being written to is of the integer class in which 
		disregards the newline character */
	string dump;

	/** this compares to see if ins has the same memory address 
	   	as cin. if they do we activate the UI to assist in entering
	 	parameters */
	if(&ins == &cin) {
		cout << "Enter a transaction number: ";
		ins >> num;

		getline(ins, dump);
		
		cout << "Enter a date (MM/DD/YYYY): ";
		ins >> date;

		getline(ins, dump);

		cout << "Enter the other party's name: ";
		getline(ins, other_party);

		cout << "Enter the amount you would like to transfer: ";
		ins >> amount;

		getline(ins, dump);
	}
	else {
		ins >> num;

		getline(ins, dump);
		
		ins >> date;

		getline(ins, dump);

		getline(ins, other_party);

		ins >> amount;

		getline(ins, dump);
	}
}



// * Data is output in the order: num, date, other_party, amount
// * am assuming that each piece of data should be written on a new line
void Transaction::output(std::ostream& outs) const{

	outs << num << endl;
	outs << date << endl;
	outs << other_party << endl;
	outs << amount << endl;
}

ostream& operator << (ostream& outs, const Transaction& c){
	c.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Transaction& c){
	c.make_transaction(ins);
	return ins;
}