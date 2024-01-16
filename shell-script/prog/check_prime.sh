echo "Enter a number:"
read number

is_prime=true
for((i=2; i*i<=number; i++))
do
if [ $(($number % $i)) -eq 0 ]
then
is_prime=false
echo "$number is not prime"
break
fi
done

if [ "$is_prime" = true ]
then
echo "$number is prime"
fi



