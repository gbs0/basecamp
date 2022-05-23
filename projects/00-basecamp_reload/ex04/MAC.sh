#!/usr/bin/env bash

ifconfig -a | grep ether | awk '{print $2}'