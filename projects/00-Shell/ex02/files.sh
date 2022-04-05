#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    files.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 22:27:42 by gschiavo          #+#    #+#              #
#    Updated: 2022/04/04 22:55:05 by gschiavo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Creating all files once

for i in $(seq 0 6)
do
  `rm -rf test${i}`
  if [ `touch -m -t 202106010730.00 test${i}` ]; then
  	echo "Error: Cannot create Files"
  else
	echo "File $i was succesfully created"
  fi
done

# Edit File 0 Format/Acess -> -rwx--xr-x
FILE_ZERO=./test0
RMV_FILE_ZERO=`rm ./test0`
CRT_DIR_ZERO=`mkdir test0`
CHN_PERMISSION_ZERO=`chmod 715 ./test0`
CHN_TIMESTAMP_ZERO=`touch -h -t 202106010730.00 test0`
if [ -d "$FILE_ZERO" ]; then
	echo "-> Removing file in ${FILE_ZERO}..."
	$RMV_FILE_ZERO
	$CRT_DIR_ZERO
	echo "-> Ok, Changing Permission..."
	$CHN_PERMISSION_ZERO
	$CHN_TIMESTAMP_ZERO
	echo "Success in $FILE_ZERO"
fi

# Edit File 1 Execution Permission -> -rwx--xr--
FILE_ONE=./test1
ADD_CHAR_ONE=`echo "042" >> ./test1`
CHN_PERMISSION_ONE=`chmod 714 $FILE_ONE`
CHN_TIMESTAMP_ONE=`touch -t 202106010730.00 $FILE_ONE`
if [ -f "$FILE_ONE" ]; then
	echo "-> Working in $FILE_ONE"
	echo "-> Changing Permission..."
	$CHN_PERMISSION_ONE
	echo "Success in $FILE_ONE"
fi

# Edit File 2 Format/Access -> -r-x---r--
FILE_TWO=./test2
RMV_FILE_TWO=`rm ./test2`
CRT_DIR_TWO=`mkdir test2`
CHN_PERMISSION_TWO=`chmod 504 $FILE_TWO`
CHN_TIMESTAMP_TWO=`touch -t 202106010730.00 test2`
if [ -d "$FILE_TWO" ]; then
	echo "-> Removing file in ${FILE_TWO}..."
	$RMV_FILE_TWO
	$CRT_DIR_TWO
	echo "-> Ok, Changing Permission..."
	$CHN_PERMISSION_TWO
	$CHN_TIMESTAMP_TWO
	echo "Success in $FILE_TWO"
fi

# Edit File 5 Read Only Permission -> -r-----r--
FILE_FIVE=./test5
RMV_FILE_FIVE=`rm ./test5`
CHN_PERMISSION_FIVE=`chmod 404 $FILE_FIVE`
if [ -f "$FILE_FIVE" ]; then
	echo "-> Removing $FILE_FIVE"
	$RMV_FILE_FIVE
	# echo "-> Ok, Changing ${FILE_FIVE} Permissions..."
	# $CHN_PERMISSION_FIVE
	# echo "Success in $FILE_FIVE"
fi

# Edit File 3 Only for Read -> -r-----r--
FILE_THREE=./test3
ADD_CHAR_THREE=`echo "" >> $FILE_THREE`
CHN_PERMISSION_THREE=`chmod 404 $FILE_THREE`
CRT_HARDLINK_THREE=`ln ./test3 ./test5`
CHN_TIMESTAMP_THREE=`touch -h -t 202106010730.00 $FILE_THREE`
if [ -f "$FILE_THREE" ]; then
	echo "-> Working in $FILE_THREE"
	echo "-> Add Chars to $FILE_THREE..."
	$ADD_CHAR_THREE
	echo "-> Ok, Changing ${FILE_THREE} Permission..."
	$CHN_PERMISSION_THREE
	echo "-> Ok, Creating Hardlink..."
	$CRT_HARDLINK_THREE
	echo "Success in $FILE_THREE"
fi

# Edit File 4 Execute only for X Group Permission -> -rw-r----x
FILE_FOUR=./test4
ADD_CHAR_FOUR=`echo "a" >> $FILE_FOUR`
CHN_PERMISSION_FOUR=`chmod 641 $FILE_FOUR`
CHN_TIMESTAMP_FOUR=`touch -t 202106010730.00 $FILE_FOUR`
if [ -f "$FILE_FOUR" ]; then
	echo "-> Working in $FILE_FOUR"
	echo "-> Add Chars to $FILE_FOUR..."
	$ADD_CHAR_FOUR
	echo "-> Ok, Changing ${FILE_FOUR} Permissions..."
	$CHN_PERMISSION_FOUR
	echo "-> Ok, Changing ${FILE_FOUR} Timestamp..."
	$CHN_TIMESTAMP_FOUR
	echo "Success in $FILE_FOUR"
fi



# Recursive Synmlink File 6 | test6 -> test0
FILE_SIX=./test6
RMV_FILE_SIX=`rm ./test6`
SYM_FILE_SIX=`ln -sf test0 ./test6`
CHN_TIMESTAMP_SIX=`touch -h -t 202106010730.00 test6`
if [ -d "$FILE_SIX" ]; then
	echo "-> Removing file in ${FILE_SIX}..."
	$RMV_FILE_SIX
	echo "-> Symlink test0 directory in -> ./test6/"
	$SYM_FILE_SIX
	echo "-> Redo Symlink Timestamp..."
	$CHN_TIMESTAMP_SIX
	echo "Success in $FILE_SIX"
fi

# Creating remaining Hardlinks
# FILE_FIVE=./test5
# RMV_FILE=`rm test5`
# CRT_HARDLINK_THREE=`ln ./test3 ./test5`
# CHN_PERMISSION_FIVE=`chmod 404 ./test5`
# if [ -f "$FILE_FIVE" ]; then
# 	echo "-> Removing file in ${FILE_FIVE}..."
# 	$RMV_FILE
# 	echo "-> Creating Hardlink test3 -> test5"
# 	$CRT_HARDLINK_THREE
# 	echo "-> Ok, Changing ${FILE_FIVE} Permissions..."
# 	$CHN_PERMISSION_FIVE
# 	echo "Success in $FILE_FIVE"
# fi

# Execute final shell operation
echo "$(ls -l)"

echo "$(tar -cf exo2.tar test0 test1 test2 test3 test4 test5 test6)"
echo "File exo2.tar created!"