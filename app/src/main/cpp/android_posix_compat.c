#include "android_posix_compat.h"

#include <pthread.h>
#include <string.h>

int pthread_cancel(pthread_t thread) {
    (void)thread;
    return 0;
}

/* libwally's wally_internal_bzero() uses this when HAVE_EXPLICIT_BZERO is set
 * (Kern's config.h). The barrier keeps the memset from being elided. */
void explicit_bzero(void *ptr, size_t len) {
    memset(ptr, 0, len);
    __asm__ __volatile__("" : : "r"(ptr) : "memory");
}
