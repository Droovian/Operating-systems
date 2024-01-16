echo "Menu driven Program"
echo "1.Display present working directory
2. Display Users of the System
3. Display Calendar
4. Exit
Enter the choice: "

while [ true ]
do

read choice

case $choice in
"1")
    pwd
    ;;
"2")
    who
    ;;
"3")
    read -p 'Enter the year: ' year
    read -p 'Enter the month(1-12):' month
    cal $month $year
    ;;
"4")
    exit
    ;;
*)
    echo "Invalid choice!"
    ;;
esac
done

