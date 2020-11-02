/*
*  sys/times.h
*  l2w4c
*
*  Created by kimbomm on 2019. 4. 3...
*  Copyright 2019 kimbomm. All rights reserved.
*
*/
#if !defined(L2W4C_7E3_4_3_SYS_TIMES_H_INCLUDED)
#define L2W4C_7E3_4_3_SYS_TIMES_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/timeb.h>
#include <sys/types.h>
#define __need_clock_t
#include <time.h>
#ifdef __cplusplus
extern "C" {
#endif
struct tms{
    clock_t tms_utime; 
    clock_t tms_stime; 
    clock_t tms_cutime; 
    clock_t tms_cstime; 
 };
inline clock_t times(struct tms *__buffer) {
	__buffer->tms_utime = clock();
	__buffer->tms_stime = 0;
	__buffer->tms_cstime = 0;
	__buffer->tms_cutime = 0;
	return __buffer->tms_utime;
}
typedef long long suseconds_t ;
#define CLOCK_REALTIME 0
#define BILLION  (1E9)

inline int clock_gettime(int dummy, struct timespec *ct){
	static BOOL g_first_time = 1;
	static LARGE_INTEGER g_counts_per_sec;
    LARGE_INTEGER count;
    if (g_first_time){
        g_first_time = 0;
        if (!QueryPerformanceFrequency(&g_counts_per_sec)){
            g_counts_per_sec.QuadPart = 0;
        }
    }
    if (!ct || (g_counts_per_sec.QuadPart <= 0) || !QueryPerformanceCounter(&count)){
        return -1;
    }
    ct->tv_sec = count.QuadPart / g_counts_per_sec.QuadPart;
	ct->tv_nsec = (long)(((count.QuadPart % g_counts_per_sec.QuadPart) * BILLION) / g_counts_per_sec.QuadPart);
    return 0;
}
#ifdef __cplusplus
};
#endif
#endif  //L2W4C_7E3_4_3_SYS_TIMES_H_INCLUDED