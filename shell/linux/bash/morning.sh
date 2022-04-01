#!/usr/bin/env bash

ME=`whoami`
echo "Good morning, $ME!"
echo "Today is $(date)."
echo "You currently have $((`free -m | grep Mem | awk '{print $2}')/1024`)) GB of RAM."
echo "You currently have $(`df -h | grep 10.51.1.1:/mnt/storage/k8s/student-workspace-gschiavo-workspace-pvc-c4b11092-3a23-4f05-8452-6a233fd9ca7f | awk '{print $4}'`) available in disk space."
echo "Your current directory is $(pwd)."

