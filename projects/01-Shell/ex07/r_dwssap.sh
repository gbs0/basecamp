#! /usr/bin bash

cat /etc/passwd | awk -F':' '{print $5}'

