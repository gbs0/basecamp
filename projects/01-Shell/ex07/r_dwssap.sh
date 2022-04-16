#! /usr/bin bash

cat /etc/passwd | grep -v "#" | sed -n '0~2p' | sort | cut -d : -f1 | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | tr "\n" "," | sed 's/,/, /g' | sed 's/, $/./'