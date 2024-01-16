echo "enter: "
read n
rev=0
a=0
no=$n
while [ $n -gt 0 ]
do
a=$(( $n % 10 ))
rev=$((($rev*10)+$a ))
n=$(( $n / 10 ))
done

if [ $rev -eq $no ]
then
echo "Its a palindrome!"
else
echo "It's not a palindrome!"
fi

echo "reversed number: $rev"