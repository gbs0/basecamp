#!/usr/bin/env bash


Users=(`ls -pmu | groups $FT_USER | tr ' ' ','`)
for ((i = 0 ; i <= ${#Users[@]} ; i++)); do
  printf "${Users[$i]}"
done