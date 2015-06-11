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

#ifndef __BIONIC_CDEFS_H__
#define __BIONIC_CDEFS_H__

#if !defined(__BIONIC_IN_BIONIC_H__)
#error "Only <bionic/bionic.h> can be included directly."
#endif

#include <sys/cdefs.h>

#if defined(__glibc_unlikely)
#define __predict_false(expr) __glibc_unlikely(expr)
#define __predict_true(expr)  __glibc_likely(expr)
#else
#define __predict_false(expr) (expr)
#define __predict_true(expr)  (expr)
#endif

#endif /* __BIONIC_CDEFS_H__ */
