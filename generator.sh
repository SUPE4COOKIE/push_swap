#!/bin/bash

# Run the Python script and save the output
numbers=$(python generator.py)

# Convert the output into an array
numbers_array=($numbers)

# echo the array
echo ${numbers_array[@]}

# Pass the array to the C program
./a.out "${numbers_array[@]}"