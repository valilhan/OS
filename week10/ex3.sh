# Hello World Program in Bash Shell
echo "Valihan" > _ex3.txt
chmod a-x _ex3.txt
ls -li _ex3.txt >> ex3.txt
chmod uo+rwx _ex3.txt
ls -li _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -li _ex3.txt >> ex3.txt

echo "660 110110000- user and group can read and  write but not execute, other can't read,write and execute" >> ex3.txt
echo "775 111111101- user and group can read, write, execute but other can't write" >> ex3.txt
echo "777 111111111- user, group, other can read and write and execute" >> ex3.txt
