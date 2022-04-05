#!/usr/bin/env bash

Files=(`find .  -type f -name "*.sh"`)
Files_number = ${#Files[@]}

for ((i = 0 ; i <= $Files_number ; i++)); do
  echo `${Files[$i]} | awk '{ gsub("./", ""); gsub(/^.*\.(sh)$/, ""); system( "echo "  $0) }'`
done


# awk '{gsub(/\t/, ","); gsub(/,,/, ",-,"); gsub(/,,/, ",-,")
echo "./ex02/find_sh.sh" | awk '{gsub(/[^\/]+/\.\./, ","); gsub(/\./, ""); gsub(/.sh/, ",-,");  system( "echo "  $0) }'

ls  -1 | sed -e 's/\.sh$//'