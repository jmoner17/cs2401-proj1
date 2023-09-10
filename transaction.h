/*************************************************************************
    This is the header file for a transaction class. It holds the
	information for a single transaction, which is the number, the date
	it was entered, who else was involved, and the amount.
	
	There are two ways of inputting into the Transaction:
		* the make_transaction function
		* the >> operator
	There are also two ways of outputting the Transaction:
		* the output function
		* the << operator

	Patricia Lindner	Ohio University EECS	September 2023
*************************************************************************/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include "date.h"

class Transaction{
    public:
		/**
		 * @brief Construct a new Transaction object
		 * 
		 * @param d - the date the transaction was made
		 * @param p - the other party involved
		 * @param num - the transaction number
		 * @param amt - the amount of the transaction
		 */
		Transaction(Date d = Date(1, 1, 1900), std::string p = "VOID", int num = 0, double amt = 0);

		// Input and output functions
		/**
		 * @brief This function is used to input all the data for a transaction
		 * 		  When inputting from the keyboard, the user is prompted for the data.
		 * 		  When inputting from a file:
		 * 			* no prompts are displayed
		 * 			* data is input in the order: num, date, other_party, amount
		 * 
		 * @param ins - the stream to read data from
		 */
		void make_transaction(std::istream& ins);

		/**
		 * @brief This function is used to output all the data for a transaction.
		 * 		  When outputting to the terminal, data is labeled.
		 * 		  When outputting to a file:
		 * 			* no data labels are included
		 * 			* data is output in the order: num, date, other_party, amount
		 * 		
		 * 
		 * @param outs - the stream to output data to
		 */
		void output(std::ostream& outs)const;

		// Accessor functions
		/**
		 * @brief Return the amount 
		 * 
		 * @return double - the amount of the transaction
		 */
		double get_amount()const {return amount;}

		/**
		 * @brief Return the date
		 * 
		 * @return * Date - the date the transaction was made
		 */
        Date get_date()const {return date;}

		/**
		 * @brief Return the other party
		 * 
		 * @return std::string - the other party involved in the transaction
		 */
		std::string get_other_party()const {return other_party;}

		/**
		 * @brief Return the transaction number
		 * 
		 * @return int - the transaction number
		 */
		int get_num()const {return num;}

		// Mutator function
		/**
		 * @brief Set the transaction number
		 * 
		 * @param n - the transaction number
		 */
		void set_num (int n){num = n;}

    private:
		int num;
		Date date;
		std::string other_party;
		double amount;
};

/**
 * @brief An implementation of the << operator that will output all data for a Transaction object
 * 
 * @param outs - the stream to write to
 * @param t - the Transaction object
 * @return std::ostream& - the stream you wrote to
 */
std::ostream& operator << (std::ostream& outs, const Transaction& t);

/**
 * @brief An implementation of the >> operator that will input all data for a Transaction object
 * 
 * @param ins - the stream to read from
 * @param t - the Transaction object
 * @return std::istream& - the stream you read from
 */
std::istream& operator >> (std::istream& ins, Transaction& t);

#endif