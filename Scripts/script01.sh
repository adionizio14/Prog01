#1/bin.bash

#Build the program in the root folder
gcc ./Source/prog01v1.c -o prog01v1

#Loop through each argument and print the list of divisors
for element in $@
do
  ./prog01v1 $element
  done