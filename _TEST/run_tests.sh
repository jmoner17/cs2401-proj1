#!/bin/bash

# Define colors
RED='[0;31m'
GREEN='[0;32m'
YELLOW='[0;33m'
NC='[0m' # No Color

# Clear the terminal
clear

# Display the header
echo -e "${YELLOW}============================================${NC}"
echo -e "${YELLOW}   Running Tests for CheckingAcct Project   ${NC}"
echo -e "${YELLOW}============================================${NC}"
echo ""  # Newline for better readability

# Run the tests for CheckingAcct, Transaction, and Date classes
echo -e "${GREEN}Starting tests...${NC}"
echo -e "${YELLOW}--------------------------------------------${NC}"
./test_executable
echo -e "${YELLOW}--------------------------------------------${NC}"
echo -e "${GREEN}Tests completed.${NC}"

# Display the footer
echo ""
echo -e "${YELLOW}============================================${NC}"
echo -e "${YELLOW}   Tests Execution Finished!                ${NC}"
echo -e "${YELLOW}============================================${NC}"
