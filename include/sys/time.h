/*
*  sys/time.h
*  l2w4c
*
*  Created by kimbomm on 2019. 4. 3...
*  Copyright 2019 kimbomm. All rights reserved.
*
*/
#if !defined(L2W4C_7E3_4_3_SYS_TIME_H_INCLUDED)
#define L2W4C_7E3_4_3_SYS_TIME_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/timeb.h>
#include <sys/types.h>
#include<Windows.h>
#ifdef __cplusplus
extern "C" {
#endif
inline int gettimeofday(struct timeval* tv, void* timezone) {
	struct _timeb timebuffer;
	_ftime64_s(&timebuffer);
	tv->tv_sec = (long)timebuffer.time;
	tv->tv_usec = 1000 * timebuffer.millitm;
	return 0;
}
__declspec(deprecated("** this function is empty **")) inline int settimeofday(const struct timeval* tv, const struct timezone* tz) {
	return 0;
}
#ifdef __cplusplus
};
#endif
#endif  //L2W4C_7E3_4_3_SYS_TIME_H_INCLUDED