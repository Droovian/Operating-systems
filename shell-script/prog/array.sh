
echo "Enter the no of elements in the array:"
read n

my_array=()

for((i=0; i<n; i++))
do  
    echo "Enter element $(($i+1)):"
    read element
    my_array[$i]=$element
done

echo "${my_array[@]}"

while [ true ]
do

echo "1. Sort the array"
echo "2. Find largest number"
echo "3. Reverse the array"
echo "4. Exit"
echo "Enter your choice:"
read choice

case $choice in

"1")
    for((i=0; i<n; i++))
    do
        for((j=0; j<n-i-1; j++))
        do
            if [ "${my_array[$j]}" -gt "${my_array[$((j+1))]}" ]
            then
                temp="${my_array[$j]}"
                my_array[$j]=${my_array[$((j+1))]}
                my_array[$((j+1))]=$temp
            fi
        done
    done
    
    echo "Sorted array: ${my_array[@]}"
    ;;
"2")
    largest_num=${my_array[1]}

    for((i=0; i<n; i++))
    do  
        if [ "${my_array[$i]}" -gt "$largest_num" ]
        then
        largest_num=${my_array[$i]}
        fi
    done
    echo "Largest number in the array is $largest_num"
    ;;
"3")
    
    i=0
    j=$(($n-1))

    while [ $i -le $j ]
    do
        temp="${my_array[$i]}"
        my_array[$i]="${my_array[$j]}"
        my_array[$j]="$temp"
        i=$(($i+1))
        j=$(($j-1))

    done

    echo "Array after reversal is: ${my_array[@]}"
    ;;
"4")
    exit
    
    ;;
*)
    echo "Invalid input!"
    ;;
esac
done