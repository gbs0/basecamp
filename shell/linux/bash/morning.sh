#!/usr/bin/env bash

ME=`whoami`
echo "Good morning, $ME!"
echo "Today is $(date)."
echo "You currently have $((`free -m | grep Mem | awk '{print $2}')`/1024) GB of RAM."
echo "You currently have $(`df -h | grep /dev/sda1 | awk '{print $4}'`) available in disk space."
echo "Your current directory is $(pwd)."

