echo "Enter n:"
read n

a=0
b=1

if [ $n -eq 1 ]; then
    echo "Fibonacci series is: $a" 
else
    echo "Fibonacci series: $a $b"
    while [ $n -gt 2 ]; do
        c=$(($a + $b))
        echo -n "$c "
        a=$b
        b=$c
        n=$(($n - 1))
    done
fi
