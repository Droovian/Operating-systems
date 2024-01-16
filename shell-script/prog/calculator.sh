ch=1
while [ $ch -eq 1 ]
do
echo "Enter a and b"
read a
read b
echo "Menu"
echo "1)Addition
2)Subtraction
3)Multiple
4)Divide
5)Remainder"

echo "Enter you choice: "
read choice
case $choice in
1)sum=$(($a + $b))
echo "output : $sum"
;;
2)diff=$(($a - $b))
echo "output : $diff"
;;
3)multi=$(($a * $b))
echo "output : $multi"
;;
4)divide=$(($a / $b))
echo "output : $divide"
;;
5)rem=$(($a % $b))
echo "output : $rem"
;;
*)echo "Invaild Choice"
esac
echo "Do you want to continue(0 or 1)"
read ch
done