#!/bin/bash
#check if number is prime or not 
echo "Enter a number"
read num1
if [ $num1 -le 0 ]; then 
    echo "Not a Prime number"
    exit 0
fi 
is_prime=true;
for(( i=2; i<=num1/2; i++ ));do
    rem=$((num%i))
    if [ $rem -eq 0 ];then
        is_prime=false;
        break
    fi
done

if [ "$is_prime" = true ];then
    echo "Its a Prime number"
else 
    echo "Its a Composite number"
fi