/*
 * Copyright (C) 2006 The Android Open Source Project
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

#ifndef __BIONIC_STRING_H__
#define __BIONIC_STRING_H__

#if !defined(__BIONIC_IN_BIONIC_H__)
#error "Only <bionic/bionic.h> can be included directly."
#endif

#include <sys/types.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BIONIC_NEED_STRLCAT)

/* Declaration of strlcpy() for platforms that don't already have it. */
size_t strlcat(char *__restrict dst, const char *__restrict src, size_t size);

#endif /* BIONIC_NEED_STRLCAT */

#if defined(BIONIC_NEED_STRLCPY)

/* Declaration of strlcpy() for platforms that don't already have it. */
size_t strlcpy(char *__restrict dst, const char *__restrict src, size_t size);

#endif /* BIONIC_NEED_STRLCPY */

#ifdef __cplusplus
}
#endif

#endif /* __BIONIC_STRING_H__ */
