#pragma once
#include<getopt.h>
//program.exe -b -c -a -p
void getopt_test(int argc, char** argv) {
	int flag_a = 0, flag_b = 0, flag_c = 0;
	int c;
	while ((c = getopt(argc, argv, "abc")) != -1) {
		switch (c) {
			case 'a':flag_a = 1;break;
			case 'b':flag_b = 1;break;
			case 'c':flag_c = 1;break;
			case '?':printf("Unknown flag : %c\n", optopt);break;
		}
	}
	if (flag_a) printf("flag a is ON \n");
	if (flag_b) printf("flag b is ON \n");
	if (flag_c) printf("flag c is ON \n");
}