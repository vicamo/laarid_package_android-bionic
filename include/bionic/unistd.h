/*
 * Copyright (C) 2014 You-Sheng Yang
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __BIONIC_UNISTD_H__
#define __BIONIC_UNISTD_H__

#if !defined(__BIONIC_IN_BIONIC_H__)
#error "Only <bionic/bionic.h> can be included directly."
#endif

#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/capability.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BIONIC_NEED_GETTID)
pid_t gettid(void);
#endif

#if defined(BIONIC_NEED_TGKILL)
int tgkill(int tgid, int tid, int sig);
#endif

#if defined(BIONIC_NEED_CAPGET_CAPSET)
int capget(cap_user_header_t hdrp, cap_user_data_t datap);
int capset(cap_user_header_t hdrp, const cap_user_data_t datap);
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/*
 * TEMP_FAILURE_RETRY is defined by some, but not all, versions of
 * <unistd.h>. (Alas, it is not as standard as we'd hoped!) So, if it's
 * not already defined, then define it here.
 */
#ifndef TEMP_FAILURE_RETRY
/* Used to retry syscalls that can return EINTR. */
#define TEMP_FAILURE_RETRY(exp) ({         \
    typeof (exp) _rc;                      \
    do {                                   \
        _rc = (exp);                       \
    } while (_rc == -1 && errno == EINTR); \
    _rc; })
#endif

#endif /* __BIONIC_UNISTD_H__ */
