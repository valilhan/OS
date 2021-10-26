include <stdio.h>
#include <dirent.h>

int main(){
	DIR * dirp;
	dirp = opendir(".");
	if (dirp == NULL){
		printf("Not FOUND"); 
    return -1;
   }

	int n = 0;
	struct dirent *arr[1001];
	struct dirent * dp = readdir(dirp);
	while((dp = readdir(dirp)) != NULL){
		arr[++n] = dp;
	}
	(void)closedir(dirp);
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(arr[i]->d_ino > arr[j]->d_ino){
				struct dirent * tmp;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		if(i > 1 && arr[i]->d_ino == arr[i-1]->d_ino){
			printf("%s %s\n", arr[i]->d_name, arr[i-1]->d_name);
		}
	}

}
