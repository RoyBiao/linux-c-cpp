#!/bin/sh
#This is sample about shell program.
cd /tmp
echo "This is a sample"
echo $PATH
touch message 
echo before redirect 
cat message
ls -l > message
echo after redirect
cat message
pwd
