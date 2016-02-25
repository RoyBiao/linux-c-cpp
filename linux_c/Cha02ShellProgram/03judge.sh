#!/bin/sh
#判断输入字符的类型
if [ $# -ne 1 ]
then 
	echo "输入参数个数错误，格式应为：'./judge.sh 参数'"
	exit
else
	case $1 in
		[0-9]) echo 数字;;
		[a-z]) echo 小写字母;;
		[A-Z]) echo 大写字母;;
		*)     echo 其它字符;;
	esac
fi
