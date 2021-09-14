#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 

int main(){
	for(int i = 1; i <= 5; i++){
		fork();
	}
	sleep(5);
}

/*
 For 3 forks, 8 process in total
 |   \-+= 08683 valihan -zsh
 |     |-+= 08702 valihan ./ex2
 |     | |-+- 08703 valihan ./ex2
 |     | | |-+- 08706 valihan ./ex2
 |     | | | \--- 08709 valihan ./ex2
 |     | | \--- 08708 valihan ./ex2
 |     | |-+- 08704 valihan ./ex2
 |     | | \--- 08707 valihan ./ex2
 |     | \--- 08705 valihan ./ex2
 |     \-+= 08710 valihan pstree
	My explnation:
 	Root process starts new child process recursively while fork() functions exist. 
	And same think child process made, child of child process made. And so on recursively 
 	So in total we will have 2^n, where n is a number of forks we call.
 For 5 forks, 32 process in total
 
 |   \-+= 08683 valihan -zsh
 |     |-+= 08727 valihan ./ex2
 |     | |-+- 08728 valihan ./ex2
 |     | | |-+- 08732 valihan ./ex2
 |     | | | |-+- 08738 valihan ./ex2
 |     | | | | |-+- 08749 valihan ./ex2
 |     | | | | | \--- 08758 valihan ./ex2
 |     | | | | \--- 08756 valihan ./ex2
 |     | | | |-+- 08746 valihan ./ex2
 |     | | | | \--- 08757 valihan ./ex2
 |     | | | \--- 08754 valihan ./ex2
 |     | | |-+- 08735 valihan ./ex2
 |     | | | |-+- 08744 valihan ./ex2
 |     | | | | \--- 08755 valihan ./ex2
 |     | | | \--- 08753 valihan ./ex2
 |     | | |-+- 08741 valihan ./ex2
 |     | | | \--- 08752 valihan ./ex2
 |     | | \--- 08750 valihan ./ex2
 |     | |-+- 08729 valihan ./ex2
 |     | | |-+- 08733 valihan ./ex2
 |     | | | |-+- 08739 valihan ./ex2
 |     | | | | \--- 08751 valihan ./ex2
 |     | | | \--- 08747 valihan ./ex2
 |     | | |-+- 08736 valihan ./ex2
 |     | | | \--- 08745 valihan ./ex2
 |     | | \--- 08742 valihan ./ex2
 |     | |-+- 08730 valihan ./ex2
 |     | | |-+- 08737 valihan ./ex2
 |     | | | \--- 08748 valihan ./ex2
 |     | | \--- 08743 valihan ./ex2
 |     | |-+- 08731 valihan ./ex2
 |     | | \--- 08740 valihan ./ex2
 |     | \--- 08734 valihan ./ex2
 |     \-+= 08759 valihan pstree
*/
