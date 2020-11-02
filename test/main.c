#include <stdio.h>
#include "getopt_test.h"
#include"dirent_test.h"
#include<sys/time.h>
#include<sys/times.h>
#include<sys/mman.h>
int main(int argc, char** argv) {
	
	//getopt_test(argc, argv);
	dirent_test();
	return 0;
}