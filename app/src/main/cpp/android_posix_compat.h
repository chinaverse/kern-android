#pragma once
/* bionic has no explicit_bzero; android_posix_compat.c implements it. */
#include <stddef.h>
#ifdef __cplusplus
extern "C"
#endif
void explicit_bzero(void *ptr, size_t len);
