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

#ifndef __BIONIC_STDLIB_H__
#define __BIONIC_STDLIB_H__

#if !defined(__BIONIC_IN_BIONIC_H__)
#error "Only <bionic/bionic.h> can be included directly."
#endif

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BIONIC_NEED_GETPROGNAME)

const char* getprogname(void);

#endif /* BIONIC_NEED_GETPROGNAME */

#ifdef __cplusplus
}
#endif

#endif /* __BIONIC_STDLIB_H__ */
