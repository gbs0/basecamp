#!/usr/bin/env bash

ME=`whoami`
MEMORY_FREE=`free -m | grep Mem | awk '{print $4}'`
DISK_SPACE=`df -h | grep 10.51.1.1:/mnt/storage/k8s/student-workspace-gschiavo-workspace-pvc-c4b11092-3a23-4f05-8452-6a233fd9ca7f | awk '{print $4}'`
echo "Good morning, $ME!"
echo "Today is $(date)."
echo "Available RAM | $MEMORY_FREE MB"
echo "   | $DISK_SPACE available in disk space."
echo "Directory is $(pwd)."

