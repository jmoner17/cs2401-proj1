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
        void number_sort();

        void other_party_sort();

        void date_sort();
        //getters

        double get_balance() const;

        void show(const string& other)const;

        void show_all(ostream& cout) const;

        //member functions
        double average() const;

 
    private:
        Transaction transactions[200];
        size_t transactionCount;
        double balance;
};
#endif