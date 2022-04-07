#!/usr/bin/env bash

find .  -type f -name "*.sh" | sed -e 's/\.sh$//'  | awk '{ gsub("./", ""); system( "echo "  $0) }'