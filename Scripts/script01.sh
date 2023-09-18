#1/bin.bash

for element in $@
do
  gcc ./Source/prog01v1.c -o prog01v1
  ./prog01v1 $element
  done