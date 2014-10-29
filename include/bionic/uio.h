/*
 * Copyright (C) 2007-2014 The Android Open Source Project
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

//
// implementation of sys/uio.h for platforms that don't have it (Win32)
//
#ifndef __BIONIC_UIO_H__
#define __BIONIC_UIO_H__

#if !defined(__BIONIC_IN_BIONIC_H__)
#error "Only <bionic/bionic.h> can be included directly."
#endif

#if !defined(BIONIC_NEED_UIO)
#include <sys/uio.h>
#else

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

struct iovec {
    void*  iov_base;
    size_t iov_len;
};

extern int  readv( int  fd, struct iovec*  vecs, int  count );
extern int  writev( int  fd, const struct iovec*  vecs, int  count );

#ifdef __cplusplus
}
#endif

#endif /* !BIONIC_NEED_UIO */

#endif /* __BIONIC_UIO_H__ */

