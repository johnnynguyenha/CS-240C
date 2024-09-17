#!/bin/bash

# Johnny Nguyen
# johnnynguyenha@csu.fullerton.edu
# Today's Date: May 14, 2024

#Program name: Manage Students


echo "Remove old un-needed files, if any."
rm *.o
rm *.out

echo "Compile the C main function search.c according to C standard 2017"
gcc -c -Wall -m64 -no-pie final.c student.h -std=c17 -lm

echo "Link object files"
gcc -m64 -no-pie -o final.output final.o -lm

echo "Run the program \"Manage Students\""
./final.output

echo "The bash file has terminated."
