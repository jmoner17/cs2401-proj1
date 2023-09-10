#ifndef CHECKING_H
#define CHECKING_H

#include <iostream>
#include <string>
#include <fstream>
#include "transaction.h"

using namespace std;

class CheckingAcct {
    public:
        //constructors
        CheckingAcct() {transactionCount = 0; balance = 0.0;}

        //setters
        void deposit(const double depamount);

        void new_transaction(istream& cin);

        void remove(const int rmnum);

        void load_from_file(ifstream& ifs);

        void save(ofstream& ofs) const;

        //Sorting functions
        //number_sort();

        //other_party_sort();

        //date_sort();
        //getters

        double get_balance() const;

        //show(string& other);

        void show_all(ostream& cout) const;

        //member functions
        //average();
 
    private:
        Transaction transactions[200];
        size_t transactionCount;
        double balance;

};
#endif