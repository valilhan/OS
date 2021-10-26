#!/bin/bash
cd ./Desktop
mkdir week01
cd ./week01
echo "Some content" > file.txt
cd ..
mkdir week10
cd ./week10
cd ..
ln ./week01/file.txt ./week10/_ex2.txt
inum=`ls -i ./week01/file.txt | awk '{print $1}'`
find . -inum $inum > ex2.txt
find . -inum $inum -exec rm {} \; >> ex2.txt
