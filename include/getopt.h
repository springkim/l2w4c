/*
*  getopt.h
*  l2wfc
*
*  Created by kimbomm on 2019. 4. 3...
*  Copyright 2019 kimbomm. All rights reserved.
*
*/
#if !defined(L2WFC_7E3_4_3_GETOPT_H_INCLUDED)
#define L2WFC_7E3_4_3_GETOPT_H_INCLUDED
#include<stdio.h>
#include<string.h>
#ifdef __cplusplus
extern "C" {
#endif
__declspec(selectany) int optind = 0;
__declspec(selectany) int opterr = 0;
__declspec(selectany) char *optarg = 0;
__declspec(selectany) char optopt = 0;
inline int getopt(int argc, char *argv[], char *optstring) {
	static char *next = NULL;
	if (optind == 0)next = NULL;
	optarg = NULL;
	if (next == NULL || *next == '\0') {
		if (optind == 0)optind++;
		if (optind >= argc || argv[optind][0] != '-' || argv[optind][1] == '\0') {
			optarg = NULL;
			if (optind < argc)optarg = argv[optind];
			return EOF;
		}
		if (strcmp(argv[optind], "--") == 0) {
			++optind;
			optarg = NULL;
			if (optind < argc)optarg = argv[optind];
			return EOF;
		}
		next = argv[optind];
		++next;
		optind++;
	}
	char c = *next++;
	const char *cp = strchr(optstring, c);
	if (cp == NULL || c == ':') {
		optopt = c;
		return '?';
	}
	++cp;
	if (*cp == ':') {
		if (*next != '\0') {
			optarg = next;
			next = NULL;
		} else if (optind < argc) {
			optarg = argv[optind];
			optind++;
		} else {
			return '?';
		}
	}
	return c;
}
#ifdef __cplusplus
}
#endif
#endif  //L2WFC_7E3_4_3_GETOPT_H_INCLUDED