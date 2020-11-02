![](res/main.jpg)
##linux2windows4c

C code for Linux can be built directly from the Windows platform. If you set up an additional include directory*(header only library)*, you can build it without any restrictions.

On Linux, times.h has the functions `clock_gettime`, `clock_settime`, `clock_getres`. The functions are implemented in sys/times.h.


```
sys
 ├ mman.h
 ├ types.h
 ├ stat.h
 ├ time.h
 └ times.h
dirent.h
getopt.h
pthread.h
unistd.h
```

sys/types.h and sys/stat.h are already implemented in Visual Studio.