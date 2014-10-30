/*
 * Copyright (C) 2010 The Android Open Source Project
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

#ifndef __BIONIC_STDIO_H__
#define __BIONIC_STDIO_H__

#if !defined(__BIONIC_IN_BIONIC_H__)
#error "Only <bionic/bionic.h> can be included directly."
#endif

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BIONIC_NEED_OPEN_MEMSTREAM)

FILE* open_memstream(char** bufp, size_t* sizep);

#endif /* BIONIC_NEED_OPEN_MEMSTREAM */

#ifdef __cplusplus
}
#endif

#endif /* __BIONIC_STDIO_H__ */
