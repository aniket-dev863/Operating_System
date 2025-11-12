#!/bin/bash
#to check weather number is positive or negetive
echo "Enter a number"
read num1
if [ $num1 -gt 0 ]; then
    echo "Number is positive"
elif [ $num1 -lt 0 ]; then 
    echo "Number is less than 0 "
else
    echo "Number is Equal to 0"
fi 