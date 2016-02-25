#!/bin/sh
#inner function 
morning(){
	echo "Good morning!"
}
afternoon(){
	echo "Good afternoon!"
}
evening(){
	echo "Good evening!"
}
greeting(){
	hour=`date +%H`
	if [ $hour -gt 0 -a $hour -lt 11 ]
	then 
		morning
	elif [ $hour -gt 12 -a $hour -lt 17 ]
	then
		afternoon
	else
		evening
	fi
	echo "greeting end"
}
echo "this time is `date`"
greeting
echo "byebye"
