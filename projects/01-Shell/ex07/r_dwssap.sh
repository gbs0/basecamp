#! /usr/bin bash

cat /etc/passwd | awk -F':' '{print $2 " " $3 " " $4 " " $5}'
