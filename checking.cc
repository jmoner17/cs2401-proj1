#include "checking.h"


using namespace std;

void CheckingAcct::deposit(const double depamount) {
    balance += depamount;
}


// * Assuming that Data is input in the order: num, date, other_party, amount
void CheckingAcct::new_transaction(istream& cin) {
    
    if(transactionCount < 200) {
        transactions[transactionCount].make_transaction(cin);
        balance += transactions[transactionCount].get_amount();
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
    double depamount;
    ifs >>  depamount;
    deposit(depamount);

    string dump;
    getline(ifs, dump);
    cout << dump << endl;

    while(!ifs.eof()) {

        if(transactionCount < 200) {
            transactions[transactionCount].make_transaction(ifs);
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

    ofs << get_balance() << endl;
    
    for(int i = 0; i < transactionCount; i++) {
        ofs << transactions[i].get_num() << endl
            << transactions[i].get_date() << endl
            << transactions[i].get_other_party() << endl
            << transactions[i].get_amount();
        
        if(i < transactionCount - 1) {
            ofs << endl;
        }
    }
}

void CheckingAcct::number_sort() {
    Transaction temp; 

    for(int i = 0; i < transactionCount - 1; i++) {
        for(int j = 0; j < transactionCount - i - 1; j++) {
            if(transactions[j].get_num() > transactions[j + 1].get_num()) {
                temp = transactions[j + 1];
                transactions[j + 1] = transactions[j];
                transactions[j] = temp;
            }
        }
    }
}

void CheckingAcct::other_party_sort() {
    Transaction temp;

    for(int i = 0; i < transactionCount - 1; i++) {
        for(int j = 0; j < transactionCount - i - 1; j++) {
            if(transactions[j].get_other_party() > transactions[j + 1].get_other_party()) {
                temp = transactions[j + 1];
                transactions[j + 1] = transactions[j];
                transactions[j] = temp;
            }
        }
    }
}

void CheckingAcct::date_sort() {
    Transaction temp;

    for(int i = 0; i < transactionCount - 1; i++) {
        for(int j = 0; j < transactionCount - i - 1; j++) {
            if(transactions[j].get_date() > transactions[j + 1].get_date()) {
                temp = transactions[j + 1];
                transactions[j + 1] = transactions[j];
                transactions[j] = temp;
            }
        }
    }
}

void CheckingAcct::show(const string& other) const{
    for(int i = 0; i < transactionCount; i++) {
        if(transactions[i].get_other_party() == other) {
            transactions[i].output(cout);
        }
    }
}

double CheckingAcct::average() const {
    double total = 0.0;

    for(int i = 0; i < transactionCount; i++) {
        total += transactions[i].get_amount();
    }
    return total / transactionCount;
}