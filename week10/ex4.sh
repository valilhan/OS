mkdir tmp
cd tmp
touch file1 
touch file2
ln file1 link1
cd ..
gcc ex4.c -o ex4
./ex4
