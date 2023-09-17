#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "checking.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Testing CheckingAcct Class
TEST_CASE("Testing CheckingAcct Class") {
    CheckingAcct acct;

    SECTION("Testing deposit function") {
        acct.deposit(100);
        REQUIRE(acct.get_balance() == 100);
    }

    SECTION("Testing new_transaction function") {
        std::istringstream ss("1 | 10/10/2023 | Sample Transaction | -50.0");
        acct.new_transaction(ss);
        REQUIRE(acct.get_balance() == 50);
    }

    SECTION("Testing remove function") {
        std::istringstream ss("1 | 10/10/2023 | Sample Transaction | -50.0");
        acct.new_transaction(ss);
        acct.remove(1);
        REQUIRE(acct.get_balance() == 100);  // Balance should revert to the original after removal
    }

    SECTION("Testing load_from_file and save functions") {
        std::ifstream ifs("sample-transactions.txt");
        acct.load_from_file(ifs);
        std::ofstream ofs("saved-transactions.txt");
        acct.save(ofs);
        // Add assertions to verify the loaded and saved transactions...
        REQUIRE(acct.get_balance() > 0); // Just a sample, more detailed checks needed
    }

    SECTION("Testing sorting functions") {
        // Add transactions in random order
        std::istringstream ss1("2 | 12/12/2023 | B | -30.0");
        std::istringstream ss2("1 | 11/11/2023 | A | -20.0");
        acct.new_transaction(ss1);
        acct.new_transaction(ss2);
        
        acct.number_sort();
        // Assertions to check if sorted by transaction number
        { std::ostringstream captured_output; std::streambuf* original_cout = std::cout.rdbuf(captured_output.rdbuf()); acct.show_all(captured_output); std::cout.rdbuf(original_cout); std::string result = captured_output.str().substr(0, 1); REQUIRE(result == "1"); }
        
        acct.date_sort();
        // Assertions to check if sorted by date
        std::ostringstream captured_output; std::streambuf* original_cout = std::cout.rdbuf(captured_output.rdbuf()); acct.show_all(captured_output); std::cout.rdbuf(original_cout); std::string result = captured_output.str().substr(0, 1); REQUIRE(result == "1");
        
        acct.other_party_sort();
        // Assertions to check if sorted by other party
        std::ostringstream captured_output_party; std::streambuf* original_cout_party = std::cout.rdbuf(captured_output_party.rdbuf()); acct.show_all(captured_output); std::cout.rdbuf(original_cout_party); std::string result_party = captured_output_party.str().substr(0, 1); REQUIRE(result_party == "A");
    }
}

// Testing Transaction Class
TEST_CASE("Testing Transaction Class") {
    Transaction trans;

    SECTION("Testing input and output functions") {
        std::istringstream iss("1 | 10/10/2023 | Sample Transaction | -50.0");
        trans.make_transaction(iss);
        std::ostringstream oss;
        oss << trans;
        REQUIRE(oss.str() == "1 | 10/10/2023 | Sample Transaction | -50.0");
    }
}

// Testing Date Class
TEST_CASE("Testing Date Class") {
    Date d1(10, 10, 2023), d2(12, 12, 2023);

    SECTION("Testing IO operations") {
        std::istringstream iss("10/10/2023");
        iss >> d1;
        std::ostringstream oss;
        oss << d1;
        REQUIRE(oss.str() == "10/10/2023");
    }

    SECTION("Testing comparison operators") {
        REQUIRE(d1 < d2);
        REQUIRE(d1 <= d2);
        REQUIRE(d2 > d1);
        REQUIRE(d2 >= d1);
        REQUIRE(d1 != d2);
        REQUIRE(d1 == d1);
    }

    SECTION("Testing invalid dates") {
        REQUIRE_THROWS_AS(Date(30, 2, 2023), bad_day);
        REQUIRE_THROWS_AS(Date(13, 10, 2023), bad_month);
    }
}
