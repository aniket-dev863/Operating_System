#!/bin/bash
#String operations
echo "Enter a String"
read string
len=${#string}
echo "Length of string is $len"
substr=${string:1:4}
echo "Substring of length 4 is $substr"
echo "Enter a character"
read char
position=`expr index "$my_string" "$char"`
echo "First position of character '$char'is :$position"