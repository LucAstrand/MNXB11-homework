#!/bin/bash

# Start by checking if we have given the correct number of arguements
# $# is the number of passed arguements, -ne is not equal to
# We check if we have not passed 2 arguements, in which case we exit.in
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 input.csv output.csv"
    exit 1
fi

# Initialise the variables for the two files (input and output)
INPUT_FILE=$1
OUTPUT_FILE=$2

# Use awk to remove empty columns
# -F tells awk that the columns are delimited by a comma (with the ','), then we perform a loop to go through
# all the columns. Starting at 1 and ending at NF (which is a built in awk variable, basically the total number
#of columns. i++ adds 1 to i for every iteration.

# We then check if i is not empty, and if so we print it with printf and add a comma. If i is the last column
# then we go to a new line 

#Everything is then  saved in a new file. 
awk -F',' '{
    for (i=1; i<=NF; i++) {
        if ($i != "") {
            printf $i (i<NF ? "," : "\n")
        }
    }
}' "$INPUT_FILE" > "$OUTPUT_FILE"

# Tell the user that we are done and what the output file name is. 
echo "Empty columns removed. Output saved to $OUTPUT_FILE"
