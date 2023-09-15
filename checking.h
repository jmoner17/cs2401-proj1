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

        /**
         * @fn CheckingAcct
         * @brief A constructor for the checkingAcct class
         * 
         * @param transactionCount the amount of transactions contained in the transactions array
         * @param balance the overall funds on a users account
        */
        CheckingAcct() {transactionCount = 0; balance = 0.0;}
        

        //setters

        /**
         * @fn deposit
         * @brief A setter used to add money to the balance member variable
         * 
         * @param depamount the amount of money to be added to balance
        */
        void deposit(const double depamount);

        /**
         * @fn new_transaction
         * @brief Adds a new transaction to the transaction array, can be done via file import
         *        or through user input.
         * 
         * @param cin either the file input or the user input
        */
        void new_transaction(istream& cin);

        /**
         * @fn remove
         * @brief removes a transaction from the transaction array
         * 
         * @param rmnum the transaction number associated with the transaction to be removed
        */
        void remove(const int rmnum);

        /**
         * @fn load_from_file
         * @brief adds transactions to the transactions array via file import
         * 
         * @param ifs the file contents to be imported
        */
        void load_from_file(ifstream& ifs);

        /**
         * @fn save
         * @brief writes the contents of the transaction array to the user file
         * 
         * @param ofs content to be written to the user file
        */
        void save(ofstream& ofs) const;

        /**
         * @fn number_sort
         * @brief sorts the transactions array by transaction number via selection sort 
        */
        void number_sort();

        /**
         * @fn other_party_sort
         * @brief sorts the transactions array alphabetically by the other party via bubble sort
        */
        void other_party_sort();

        /**
         * @fn date_sort
         * @brief sorts the transactions array chronologically via insertion sort
        */
        void date_sort();


        //getters
        
        /**
         * @fn get_balance
         * @brief returns the balance of this object
         * 
         * @return balance
        */
        double get_balance() const;

        /**
         * @fn show
         * @brief displays all transactions by a specific other party
         * 
         * @param other the other party to be displayed
        */
        void show(const string& other) const;

        /**
         * @fn show_all
         * @brief displays all transactions stored in the transactions array
         * 
         * @param cout the output variable
        */
        void show_all(ostream& cout) const;

        /**
         * @fn average
         * @brief returns the average transaction amount of all transactions in the array
         * 
         * @return average 
        */
        double average() const;

    private:
        Transaction transactions[200];
        size_t transactionCount;
        double balance;
};
#endif