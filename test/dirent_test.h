#pragma once
#include<dirent.h>
void dirent_test() {
	DIR *dirp;
	struct dirent *dp;
	if ((dirp = opendir(".")) == NULL) {      
		perror("couldn't open '.' \n ");        
		return;
	}
	do {
		if ((dp = readdir(dirp)) != NULL) {                              
			printf("%s\n", dp->d_name);
		}
	} while (dp != NULL);
	closedir(dirp);
}