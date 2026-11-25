#pragma once

#include "mbedtls_compat.h"
#include "lvgl_compat.h"

// kern_secret_alloc()/kern_secret_strdup() prototypes. Kern's utils/secure_mem.h
// only pulls secure_memory.h in under ESP_PLATFORM, and several Kern-pinyin
// sources (utils/bip39_lang.c, backup/mnemonic_qr.c, scan/scan_handlers.c,
// shared/key_confirmation.c) call them without including it. Clang rejects
// the implicit declaration, and an implicit int return would truncate the
// secret buffer pointer on 64-bit ABIs.
#include "secure_memory.h"

#if defined(__ANDROID__)
#include <pthread.h>
int pthread_cancel(pthread_t thread);
#endif
