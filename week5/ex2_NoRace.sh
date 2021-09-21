if test ! -f test2
then 
	touch test2
	echo 0 > test2
fi

if ln test2 test2.lock
	then
	for i in `seq 1 20`;
	do
		n=`tail -1 test2`
		expr $n + 1 >> test2
	done
	rm test2.lock
fi
