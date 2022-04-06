#!/usr/bin/env bash

# Files=(`find .  -type f -name "*.sh"`)

# for ((i = 0 ; i <= ${#Files[@]} ; i++)); do
#   #echo `${Files[$i]} | awk '{ gsub("./", ""); gsub(/^.*\.(sh)$/, ""); system( "echo "  $0) }'`
#   echo `${Files[$i]} | sed -e 's/\.sh$//' | awk '{ gsub("./", ""); system( "echo "  $0) }'`
# done

# awk '{gsub(/\t/, ","); gsub(/,,/, ",-,"); gsub(/,,/, ",-,")
# echo "./ex02/find_sh.sh" | awk '{gsub(/[^\/]+/\.\./, ","); gsub(/\./, ""); gsub(/.sh/, ",-,");  system( "echo "  $0) }'

find .  -type f -name "*.sh" | sed -e 's/\.sh$//'  | awk '{ gsub("./", ""); system( "echo "  $0) }'