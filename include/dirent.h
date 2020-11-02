
/*
*  dirent.h
*  l2w4c
*
*  Created by kimbomm on 2019. 4. 3...
*  Copyright 2019 kimbomm. All rights reserved.
*
*/
#if !defined(L2W4C_7E3_4_3_DIRENT_H_INCLUDED)
#define L2W4C_7E3_4_3_DIRENT_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<wchar.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>

#include <windows.h>

#define _DIRENT_HAVE_D_TYPE
#define _DIRENT_HAVE_D_NAMLEN
#if !defined(FILE_ATTRIBUTE_DEVICE)
#   define FILE_ATTRIBUTE_DEVICE 0x40
#endif
#if !defined(S_IFMT)
#   define S_IFMT _S_IFMT
#endif
#if !defined(S_IFDIR)
#   define S_IFDIR _S_IFDIR
#endif
#if !defined(S_IFCHR)
#   define S_IFCHR _S_IFCHR
#endif
#if !defined(S_IFFIFO)
#   define S_IFFIFO _S_IFFIFO
#endif
#if !defined(S_IFREG)
#   define S_IFREG _S_IFREG
#endif
#if !defined(S_IREAD)
#   define S_IREAD _S_IREAD
#endif
#if !defined(S_IWRITE)
#   define S_IWRITE _S_IWRITE
#endif
#if !defined(S_IEXEC)
#   define S_IEXEC _S_IEXEC
#endif
#if !defined(S_IFIFO)
#   define S_IFIFO _S_IFIFO
#endif
#if !defined(S_IFBLK)
#   define S_IFBLK 0
#endif
#if !defined(S_IFLNK)
#   define S_IFLNK 0
#endif
#if !defined(S_IFSOCK)
#   define S_IFSOCK 0
#endif
#if !defined(S_IRUSR)
#   define S_IRUSR S_IREAD
#endif
#if !defined(S_IWUSR)
#   define S_IWUSR S_IWRITE
#endif
#if !defined(S_IXUSR)
#   define S_IXUSR 0
#endif
#if !defined(S_IRGRP)
#   define S_IRGRP 0
#endif
#if !defined(S_IWGRP)
#   define S_IWGRP 0
#endif
#if !defined(S_IXGRP)
#   define S_IXGRP 0
#endif
#if !defined(S_IROTH)
#   define S_IROTH 0
#endif
#if !defined(S_IWOTH)
#   define S_IWOTH 0
#endif
#if !defined(S_IXOTH)
#   define S_IXOTH 0
#endif
#if !defined(PATH_MAX)
#   define PATH_MAX MAX_PATH
#endif
#if !defined(FILENAME_MAX)
#   define FILENAME_MAX MAX_PATH
#endif
#if !defined(NAME_MAX)
#   define NAME_MAX FILENAME_MAX
#endif
#define DT_UNKNOWN 0
#define DT_REG S_IFREG
#define DT_DIR S_IFDIR
#define DT_FIFO S_IFIFO
#define DT_SOCK S_IFSOCK
#define DT_CHR S_IFCHR
#define DT_BLK S_IFBLK
#define DT_LNK S_IFLNK
#define IFTODT(mode) ((mode) & S_IFMT)
#define DTTOIF(type) (type)
#if !defined(S_ISFIFO)
#   define S_ISFIFO(mode) (((mode) & S_IFMT) == S_IFIFO)
#endif
#if !defined(S_ISDIR)
#   define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#endif
#if !defined(S_ISREG)
#   define S_ISREG(mode) (((mode) & S_IFMT) == S_IFREG)
#endif
#if !defined(S_ISLNK)
#   define S_ISLNK(mode) (((mode) & S_IFMT) == S_IFLNK)
#endif
#if !defined(S_ISSOCK)
#   define S_ISSOCK(mode) (((mode) & S_IFMT) == S_IFSOCK)
#endif
#if !defined(S_ISCHR)
#   define S_ISCHR(mode) (((mode) & S_IFMT) == S_IFCHR)
#endif
#if !defined(S_ISBLK)
#   define S_ISBLK(mode) (((mode) & S_IFMT) == S_IFBLK)
#endif
#define _D_EXACT_NAMLEN(p) ((p)->d_namlen)
#define _D_ALLOC_NAMLEN(p) ((PATH_MAX)+1)

#ifdef __cplusplus
extern "C" {
#endif
typedef struct _wdirent {
	size_t d_ino;
	size_t d_off;
    unsigned short d_reclen;
    size_t d_namlen;
    int d_type;
    wchar_t d_name[PATH_MAX+1];
}_wdirent;
typedef struct _WDIR {
    struct _wdirent ent;
    WIN32_FIND_DATAW data;
    int cached;
    HANDLE handle;
    wchar_t *patt;
}_WDIR;
typedef struct dirent {
    size_t d_ino;
	size_t d_off;
    unsigned short d_reclen;
    size_t d_namlen;
    int d_type;
    char d_name[PATH_MAX+1];
}dirent;
typedef struct DIR {
    struct dirent ent;
    struct _WDIR *wdirp;
}DIR;

static DIR *opendir (const char *dirname);
static _WDIR *_wopendir (const wchar_t *dirname);

static struct dirent *readdir (DIR *dirp);
static struct _wdirent *_wreaddir (_WDIR *dirp);

static int readdir_r(
    DIR *dirp, struct dirent *entry, struct dirent **result);
static int _wreaddir_r(
    _WDIR *dirp, struct _wdirent *entry, struct _wdirent **result);

static int closedir (DIR *dirp);
static int _wclosedir (_WDIR *dirp);

static void rewinddir (DIR* dirp);
static void _wrewinddir (_WDIR* dirp);

static int scandir (const char *dirname, struct dirent ***namelist,
    int (*filter)(const struct dirent*),
    int (*compare)(const struct dirent**, const struct dirent**));

static int alphasort (const struct dirent **a, const struct dirent **b);

static int versionsort (const struct dirent **a, const struct dirent **b);


#define wdirent _wdirent
#define WDIR _WDIR
#define wopendir _wopendir
#define wreaddir _wreaddir
#define wclosedir _wclosedir
#define wrewinddir _wrewinddir


/* Internal utility functions */
static WIN32_FIND_DATAW *dirent_first (_WDIR *dirp);
static WIN32_FIND_DATAW *dirent_next (_WDIR *dirp);

static int dirent_mbstowcs_s(
    size_t *pReturnValue,
    wchar_t *wcstr,
    size_t sizeInWords,
    const char *mbstr,
    size_t count);

static int dirent_wcstombs_s(
    size_t *pReturnValue,
    char *mbstr,
    size_t sizeInBytes,
    const wchar_t *wcstr,
    size_t count);

static void dirent_set_errno (int error);
///===========================================

/*
 * Open directory stream DIRNAME for read and return a pointer to the
 * internal working area that is used to retrieve individual directory
 * entries.
 */
inline _WDIR* _wopendir(const wchar_t *dirname){
    _WDIR *dirp = NULL;
    int error;
    if (dirname == NULL  ||  dirname[0] == '\0') {
        dirent_set_errno (ENOENT);
        return NULL;
    }
    dirp = (_WDIR*) malloc (sizeof (struct _WDIR));
    if (dirp != NULL) {
        DWORD n;
        dirp->handle = INVALID_HANDLE_VALUE;
        dirp->patt = NULL;
        dirp->cached = 0;
#       if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)
            n = wcslen(dirname);
#       else
            n = GetFullPathNameW (dirname, 0, NULL, NULL);
#       endif
        dirp->patt = (wchar_t*) malloc (sizeof (wchar_t) * n + 16);
        if (dirp->patt) {
#           if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)
                wcsncpy_s(dirp->patt, n+1, dirname, n);
#           else
                n = GetFullPathNameW (dirname, n, dirp->patt, NULL);
#           endif
            if (n > 0) {
                wchar_t *p;
                p = dirp->patt + n;
                if (dirp->patt < p) {
                    switch (p[-1]) {
                    case '\\':
                    case '/':
                    case ':':break;
                    default:*p++ = '\\';
                    }
                }
                *p++ = '*';
                *p = '\0';
                if (dirent_first (dirp)) {
                    error = 0;
                } else {
                    error = 1;
                    dirent_set_errno (ENOENT);
                }
            } else {
                dirent_set_errno (ENOENT);
                error = 1;
            }
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
    if (error  &&  dirp) {
        _wclosedir (dirp);
        dirp = NULL;
    }
    return dirp;
}

inline struct _wdirent* _wreaddir(_WDIR *dirp){
    struct _wdirent *entry;
   _wreaddir_r(dirp, &dirp->ent, &entry);
    return entry;
}
inline int _wreaddir_r(_WDIR *dirp,struct _wdirent *entry,struct _wdirent **result){
    WIN32_FIND_DATAW *datap;
    datap = dirent_next (dirp);
    if (datap) {
        size_t n;
        DWORD attr;
        n = 0;
        while (n < PATH_MAX  &&  datap->cFileName[n] != 0) {
            entry->d_name[n] = datap->cFileName[n];
            n++;
        }
        entry->d_name[n] = 0;
        entry->d_namlen = n;
        attr = datap->dwFileAttributes;
        if ((attr & FILE_ATTRIBUTE_DEVICE) != 0) {
            entry->d_type = DT_CHR;
        } else if ((attr & FILE_ATTRIBUTE_DIRECTORY) != 0) {
            entry->d_type = DT_DIR;
        } else {
            entry->d_type = DT_REG;
        }
        entry->d_ino = 0;
        entry->d_off = 0;
        entry->d_reclen = sizeof (struct _wdirent);
        *result = entry;
    } else {
        *result = NULL;
    }
    return 0;
}
inline int _wclosedir(_WDIR *dirp){
    int ok;
    if (dirp) {
        if (dirp->handle != INVALID_HANDLE_VALUE) {
            FindClose (dirp->handle);
            dirp->handle = INVALID_HANDLE_VALUE;
        }
        if (dirp->patt) {
            free (dirp->patt);
            dirp->patt = NULL;
        }
        free (dirp);
        ok = 0;
    } else {
        dirent_set_errno (EBADF);
        ok = -1;
    }
    return ok;
}
inline void _wrewinddir(_WDIR* dirp){
    if (dirp) {
        if (dirp->handle != INVALID_HANDLE_VALUE) {
            FindClose (dirp->handle);
        }
        dirent_first (dirp);
    }
}
inline WIN32_FIND_DATAW* dirent_first(_WDIR *dirp){
    WIN32_FIND_DATAW *datap;
    dirp->handle = FindFirstFileExW(dirp->patt, FindExInfoStandard, &dirp->data,FindExSearchNameMatch, NULL, 0);
    if (dirp->handle != INVALID_HANDLE_VALUE) {
        datap = &dirp->data;
        dirp->cached = 1;
    } else {
        dirp->cached = 0;
        datap = NULL;
    }
    return datap;
}
inline WIN32_FIND_DATAW* dirent_next(_WDIR *dirp){
    WIN32_FIND_DATAW *p;
    if (dirp->cached != 0) {
        p = &dirp->data;
        dirp->cached = 0;
    } else if (dirp->handle != INVALID_HANDLE_VALUE) {
        if (FindNextFileW (dirp->handle, &dirp->data) != FALSE) {
            p = &dirp->data;
        } else {
            FindClose (dirp->handle);
            dirp->handle = INVALID_HANDLE_VALUE;
            p = NULL;
        }
    } else {
        p = NULL;
    }
    return p;
}
inline  DIR* opendir(const char *dirname){
    struct DIR *dirp;
    int error;
    if (dirname == NULL  ||  dirname[0] == '\0') {
        dirent_set_errno (ENOENT);
        return NULL;
    }
    dirp = (DIR*) malloc (sizeof (struct DIR));
    if (dirp) {
        wchar_t wname[PATH_MAX + 1];
        size_t n;
        error = dirent_mbstowcs_s(&n, wname, PATH_MAX + 1, dirname, PATH_MAX + 1);
        if (!error) {
            dirp->wdirp = _wopendir (wname);
            if (dirp->wdirp) {
                error = 0;
            } else {
                error = 1;
            }
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
    if (error  &&  dirp) {
        free (dirp);
        dirp = NULL;
    }
    return dirp;
}
inline struct dirent* readdir(DIR *dirp){
    struct dirent *entry;
    readdir_r (dirp, &dirp->ent, &entry);
    return entry;
}
inline int readdir_r(DIR *dirp,struct dirent *entry,struct dirent **result){
    WIN32_FIND_DATAW *datap;
    datap = dirent_next (dirp->wdirp);
    if (datap) {
        size_t n;
        int error;
        error = dirent_wcstombs_s(&n, entry->d_name, PATH_MAX + 1, datap->cFileName, PATH_MAX + 1);
        if (error  &&  datap->cAlternateFileName[0] != '\0') {
            error = dirent_wcstombs_s(
                &n, entry->d_name, PATH_MAX + 1,
                datap->cAlternateFileName, PATH_MAX + 1);
        }
        if (!error) {
            DWORD attr;
            entry->d_namlen = n - 1;
            attr = datap->dwFileAttributes;
            if ((attr & FILE_ATTRIBUTE_DEVICE) != 0) {
                entry->d_type = DT_CHR;
            } else if ((attr & FILE_ATTRIBUTE_DIRECTORY) != 0) {
                entry->d_type = DT_DIR;
            } else {
                entry->d_type = DT_REG;
            }
            entry->d_ino = 0;
            entry->d_off = 0;
            entry->d_reclen = sizeof (struct dirent);
        } else {
            entry->d_name[0] = '?';
            entry->d_name[1] = '\0';
            entry->d_namlen = 1;
            entry->d_type = DT_UNKNOWN;
            entry->d_ino = 0;
            entry->d_off = -1;
            entry->d_reclen = 0;
        }
        *result = entry;
    } else {
        *result = NULL;
    }
    return 0;
}
inline int closedir(DIR *dirp){
    int ok;
    if (dirp) {
        ok = _wclosedir (dirp->wdirp);
        dirp->wdirp = NULL;
        free (dirp);
    } else {
        dirent_set_errno (EBADF);
        ok = -1;
    }
    return ok;
}
inline void rewinddir(DIR* dirp){
    _wrewinddir (dirp->wdirp);
}
inline int scandir(const char *dirname,struct dirent ***namelist,int (*filter)(const struct dirent*),int (*compare)(const struct dirent**, const struct dirent**)){
    struct dirent **files = NULL;
    size_t size = 0;
    size_t allocated = 0;
    const size_t init_size = 1;
    DIR *dir = NULL;
    struct dirent *entry;
    struct dirent *tmp = NULL;
    size_t i;
    int result = 0;
    dir = opendir (dirname);
    if (dir) {
        while (1) {
            if (size >= allocated) {
                void *p;
                size_t num_entries;
                if (size < init_size) {
                    num_entries = init_size;
                } else {
                    num_entries = size * 2;
                }
                p = realloc (files, sizeof (void*) * num_entries);
                if (p != NULL) {
                    files = (dirent**) p;
                    allocated = num_entries;
                } else {
                    result = -1;
                    break;
                }
            }
            if (tmp == NULL) {
                tmp = (struct dirent*) malloc (sizeof (struct dirent));
                if (tmp == NULL) {
                    result = -1;
                    break;
                }
            }
            if (readdir_r (dir, tmp, &entry) == /*OK*/0) {
                if (entry != NULL) {
                    int pass;
                    if (filter) {
                        pass = filter (tmp);
                    } else {
                        pass = 1;
                    }
                    if (pass) {
                        files[size++] = tmp;
                        tmp = NULL;
                        result++;
                    }
                } else {
                    qsort (files, size, sizeof (void*), (int (*) (const void*, const void*)) compare);
                    break;
                }
            } else {
                result = -1;
                break;
            }
        }
    } else {
        result = -1;
    }
    if (tmp) {
        free (tmp);
    }
    if (result < 0) {
        for (i = 0; i < size; i++) {
            free (files[i]);
        }
        free (files);
        files = NULL;
    }
    if (dir) {
        closedir (dir);
    }
    if (namelist) {
        *namelist = files;
    }
    return result;
}
inline int alphasort(const struct dirent **a, const struct dirent **b){
    return strcoll ((*a)->d_name, (*b)->d_name);
}
inline int versionsort(const struct dirent **a, const struct dirent **b){
    return alphasort (a, b);
}
inline int dirent_mbstowcs_s(size_t *pReturnValue,wchar_t *wcstr,size_t sizeInWords,const char *mbstr,size_t count){
    int error;
    int n;
    size_t len;
    UINT cp;
    DWORD flags;
    if (AreFileApisANSI ()) {
        cp = GetACP ();
    } else {
        cp = GetOEMCP ();
    }
    switch (cp) {
    case 42:
    case 50220:
    case 50221:
    case 50222:
    case 50225:
    case 50227:
    case 50229:
    case 57002:
    case 57003:
    case 57004:
    case 57005:
    case 57006:
    case 57007:
    case 57008:
    case 57009:
    case 57010:
    case 57011:
    case 65000:
        flags = 0;
        break;
    default:
        flags = MB_ERR_INVALID_CHARS;
    }
    len = 0;
    while (mbstr[len] != '\0'  &&  len < count) {
        len++;
    }
    n = MultiByteToWideChar(cp,flags,mbstr,(int) len,wcstr,sizeInWords - 1);
    wcstr[n] = '\0';
    *pReturnValue = (size_t) (n + 1);
    if (n > 0) {
        error = 0;
    } else {
        error = 1;
    }
    return error;
}
inline int dirent_wcstombs_s(size_t *pReturnValue,char *mbstr,size_t sizeInBytes,const wchar_t *wcstr,size_t count){
    int n;
    int error;
    UINT cp;
    size_t len;
    BOOL flag = 0;
    LPBOOL pflag;
    if (AreFileApisANSI ()) {
        cp = GetACP ();
    } else {
        cp = GetOEMCP ();
    }
    len = 0;
    while (wcstr[len] != '\0'  &&  len < count) {
        len++;
    }
    switch (cp) {
    case CP_UTF7:
    case CP_UTF8:
        pflag = NULL;
        break;
    default:
        pflag = &flag;
    }
    n = WideCharToMultiByte(cp,0,wcstr,(int) len,mbstr,sizeInBytes - 1,NULL,pflag);
    mbstr[n] = '\0';
    *pReturnValue = (size_t) (n + 1);
    if (n > 0  &&  flag == 0) {
        error = 0;
    } else {
        error = 1;
    }
    return error;
}
inline void dirent_set_errno(int error){
#if defined(_MSC_VER)  &&  _MSC_VER >= 1400
    _set_errno (error);
#else
    errno = error;
#endif
}
#ifdef __cplusplus
}
#endif
#endif  //L2W4C_7E3_4_3_DIRENT_H_INCLUDED