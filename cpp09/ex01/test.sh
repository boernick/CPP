#!/bin/bash

echo "--- valid expressions ---"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"   # 42
./RPN "7 7 * 7 -"                     # 42
./RPN "1 2 * 2 / 2 * 2 4 - +"        # 0
./RPN "1 2 +"                         # 3
./RPN "9 9 +"                         # 18
./RPN "9 9 * 9 9 * +"                 # 162
./RPN "5 1 2 + 4 * + 3 -"            # 14
./RPN "2 3 * 4 +"                     # 10
./RPN "9 1 -"                         # 8
./RPN "6 2 /"                         # 3
./RPN "3 3 * 3 3 * +"                 # 18
./RPN "9 9 * 9 - 9 - 9 - 9 - 9 - 9 - 9 - 9 - 9 -"  # 0
./RPN "2 2 + 2 2 + *"                 # 16
./RPN "9 0 +"                         # 9

echo "--- error cases ---"
./RPN "(1 + 1)"      # invalid token
./RPN "1 2"          # no operator
./RPN "+ 1 2"        # operator before operands
./RPN "1"            # too short
./RPN "1 0 /"        # division by zero
./RPN "abc"          # invalid tokens
./RPN ""             # empty
./RPN "1 2 + +"      # not enough operands for second +
./RPN "1 2 3 +"      # too many operands
./RPN "* 2 3"        # operator first
./RPN "1 2 + 3"      # leftover operand on stack