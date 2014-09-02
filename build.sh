#!/bin/bash

make $1
echo "Press ENTER to Continue"
read
clear
./$1
rm -f $1
