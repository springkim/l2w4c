
/*
*  unistd.h
*  l2w4c
*
*  Created by kimbomm on 2019. 4. 3...
*  Copyright 2019 kimbomm. All rights reserved.
*
*/
#if !defined(L2W4C_7E3_4_3_UNISTD_H_INCLUDED)
#define L2W4C_7E3_4_3_UNISTD_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
#include<process.h>
#include<direct.h>
#include<getopt.h>
#define srandom srand
#define random rand
#define R_OK    4
#define W_OK    2
#define X_OK    R_OK 
#define F_OK    0
#define access _access
#define dup2 _dup2
#define execve _execve
#define ftruncate _chsize
#define unlink _unlink
#define fileno _fileno
#define getcwd _getcwd
#define chdir _chdir
#define isatty _isatty
#define lseek _lseek
#define ssize_t int
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
typedef __int8            int8_t;
typedef __int16           int16_t; 
typedef __int32           int32_t;
typedef __int64           int64_t;
typedef unsigned __int8   uint8_t;
typedef unsigned __int16  uint16_t;
typedef unsigned __int32  uint32_t;
typedef unsigned __int64  uint64_t;
#endif  //L2W4C_7E3_4_3_UNISTD_H_INCLUDED