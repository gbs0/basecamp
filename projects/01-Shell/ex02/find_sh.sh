#!/usr/bin/env bash

find . -type f -name "*.sh" | cut -d "/"  -f2 | cut -d "." -f1