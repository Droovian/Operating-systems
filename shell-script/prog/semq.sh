
while [ true ]
do

echo "1.Display Processor Information"
echo "2.Display real time main memory status"
echo "3.Display real time process status"
echo "4.Exit"

echo "What's your choice?"
read choice

case $choice in

"1")
    lscpu
    ;;
"2")
    top
    ;;
"3")
    htop
    ;;
"4")
    exit
    ;;

esac
done