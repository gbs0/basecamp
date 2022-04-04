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
  if [ `touch -m -t 201906020730.00 test${i}` ]; then
  	echo "Error: Cannot create Files"
  else
	echo "File $i was succesfully created"
  fi
done

# Edit File 0 Format/Acess
FILE_ZERO=./test0
RMV_FILE_ZERO=`rm ./test0`
CRT_DIR_ZERO=`mkdir test0`
CHN_TIMESTAMP_ZERO=`touch -h -t 201906020730.00 test0`
if [ -f "$FILE_ZERO" ]; then
    echo "------- $FILE_ZERO exists! -------"
	echo "-> Removing file..."
	$RMV_FILE_ZERO
	echo "-> Creating directory..."
	$CRT_DIR_ZERO
	echo "-> Ok, Changing Timestamp"
	$CHN_TIMESTAMP_ZERO
	echo "Success in $FILE_ZERO"
fi

# Edit File 2 Format/Acess
FILE_TWO=./test2
RMV_FILE_TWO=`rm ./test2`
CRT_DIR_TWO=`mkdir test2`
CHN_PERMISSION_TWO=`chmod 504 ./test2`
CHN_TIMESTAMP_TWO=`touch -h -t 201906020730.00 test2`
if [ -f "$FILE_TWO" ] ; then
    echo "------- $FILE_TWO exists! -------"
	echo "-> Removing file..."
	$RMV_FILE_TWO
	echo "-> Creating directory..."
	$CRT_DIR_TWO
	echo "-> Changing N Permission..."
	$CHN_PERMISSION_TWO
	echo "-> Ok, Changing Timestamp"
	$CHN_TIMESTAMP_TWO
fi

# Edit File 2 Format/Acess
FILE_SIX=./test6
RMV_FILE_SIX=`rm ./test6`
SYM_FILE_SIX=`ln -sf test0 ./test6`
CHN_TIMESTAMP_SIX=`touch -h -t 201906020730.00 test6`

if [ -f "$FILE_SIX" ]; then
    echo "------- $FILE_SIX exists! -------"
	echo "-> Removing file..."
	$RMV_FILE_SIX
	echo "-> Symlink test0 directory in -> ./test6/"
	$SYM_FILE_SIX
	echo "-> Redo Symlink Timestamp..."
	$CHN_TIMESTAMP_SIX
	echo "Success in $FILE_SIX"
fi

