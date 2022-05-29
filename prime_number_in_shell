#!/bin/bash

array1=()
array2=()

PrimeNumber()
{
        for((i=1;i<=num;i++))
        do
                count=0
                for((j=1;j<=i;j++))
                do
                        k=`expr $i % $j`
                        if [ $k -eq 0 ]
                        then
                                ((count++))
                        fi
                done
                if [ $count -eq 2 ]
                then
                        array1+=($i)
                else
                        array2+=($i)
                fi
        done
        echo "Prime number : ${array1[@]}"
        echo "Non-prime number : ${array2[@]}"
}
echo "enter number>>"
read num
PrimeNumber $num
