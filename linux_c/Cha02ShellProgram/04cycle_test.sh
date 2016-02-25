#!/bin/sh
#创建，删除文件，退出循环
cd /tmp
while true
do
	echo -e "Select the operate:\n1     Create one file;\n2     Remove one file;\nother:Exit."
	read select
	if [ $select = 1 ]
	then
		echo "Enter a file to create:"
		read file
		if [ -e $file ]
		then
			echo "file is exist"
			continue;
		else
			touch $file
			echo "$file file is created successfully."
		fi
	elif [ $select = 2 ]
	then
		echo "Enter a file to remove:"
		for filename in *
		do
			ls -l $filename
		done
		read file
		if [ -e $file -a -f $file ]
		then 
			rm -rf $file
			echo "$file is removed successfully."
		else
			echo "file is not exist"
			continue;
		fi
	else
		echo "Progress will be exited,Yes or No ?"
		read answer
		if [ $answer = "Yes" ]
		then
			break;
		else
			continue;
		fi
	fi
done
exit
