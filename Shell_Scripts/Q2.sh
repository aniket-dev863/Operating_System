#!/bin/bash
#compare two numbers
echo "Enter the first Number"
read num1
echo "Enter the Second Number"
read num2
if [ $num1 -eq $num2 ]; then
    echo "$num1 is equal to $num2"
elif [ $num1 -gt $num2 ]; then
    echo "$num1 is Greater than $num2"
else
    echo "$num2 is greater than $num1"
fi 