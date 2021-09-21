touch test1
echo 0 > test1

for i in `seq 1 20`;
do
n=`tail -1 test1`
expr $n + 1 >> test1
done
