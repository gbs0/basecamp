#!/usr/bin/env bash

ifconfig -a | grep txqueuelen | grep ether | awk -F' ' '{print $2 "  " $3 " " $4 "  " $5}'