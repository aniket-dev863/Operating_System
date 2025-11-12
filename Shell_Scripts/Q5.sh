#!/bin/bash
#Largest of Three Numbers
echo "Enter First number:"
read num1 
echo "2nd number"
read num2
echo "3rd number"
read num3
if [ $num1 -gt $num2 -a $num1 -gt $num2 ]; then
    echo "$num1 is the Greatest number "
fi