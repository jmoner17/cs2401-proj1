#include "checking.h"

using namespace std;

void CheckingAcct::deposit(const double depamount) {
    balance += depamount;
}


// * Assuming that Data is input in the order: num, date, other_party, amount
void CheckingAcct::new_transaction(istream& cin) {
    
    if(transactionCount < 200) {

        transactions[transactionCount].make_transaction(cin);
        transactionCount++; 
    }
    else {

        cout << "Transaction limit reached" << endl;
    }
}


double CheckingAcct::get_balance() const{
    return balance;
}


void CheckingAcct::show_all(ostream& cout) const{
    
    for(int i = 0; i < transactionCount; i++) {
        transactions[i].output(cout);
    }
}


void CheckingAcct::remove(const int rmnum) {
    Transaction tmp;
    int i = 0;

    while(i < transactionCount) {
        if(transactions[i].get_num() == rmnum) {
            break;
        }
        i++;
    }

    while(i < transactionCount - 1) {
        transactions[i] = transactions[i + 1];
        i++;
    }

    transactions[i] = tmp;
    transactionCount--;
}


void CheckingAcct::load_from_file(ifstream& ifs) {
    while(!ifs.eof()) {

        if(transactionCount < 200) {
            transactions[transactionCount].make_transaction(ifs);
            balance += transactions[transactionCount].get_amount();
            transactionCount++;
        }
        else {
            cout << "Your input file contains too many transactions" << endl;
            break;
        }
    }
}


// * Assuming that Data is input in the order: num, date, other_party, amount
void CheckingAcct::save(ofstream& ofs) const{
    
    for(int i = 0; i < transactionCount; i++) {
        ofs << transactions[i].get_num() << endl
            << transactions[i].get_date() << endl
            << transactions[i].get_other_party() << endl
            << transactions[i].get_amount() << endl;
    }
}