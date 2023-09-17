#!/bin/bash

# Clear the terminal
clear

# Display the header
echo '============================================'
echo '   Running Tests for CheckingAcct Project   '
echo '============================================'
echo ''  # Newline for better readability

# Run the tests for CheckingAcct, Transaction, and Date classes
echo 'Starting tests...'
echo '--------------------------------------------'
./test_executable
echo '--------------------------------------------'
echo 'Tests completed.'

# Display the footer
echo ''
echo '============================================'
echo '   Tests Execution Finished!                '
echo '============================================'
