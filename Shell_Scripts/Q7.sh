#!/bin/bash
echo "Program to print first 10 fibonacci numbers"
count=0;
a=0 
b=1
while [ $count -lt 10 ];do
    echo $a 
    sum=$((a + b))
    a=$b
    b=$sum
    count=$((count + 1))
done
