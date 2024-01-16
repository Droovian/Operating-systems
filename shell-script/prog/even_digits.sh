echo "Enter a number:"
read n

rem=0
sum=0
num=$n

while [ $n -gt 0 ]
do
rem=$(($n%10))
b=$(($rem%2))

if [ $b -eq 0 ]
then
sum=$(($sum + $rem))
fi

n=$(($n/10))
done

echo "Sum of even digits of number $num is $sum"