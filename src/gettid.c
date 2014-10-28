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

#include "bionic/bionic.h"

#if defined(BIONIC_NEED_GETTID)

#include <unistd.h>
#include <sys/syscall.h>

#if defined(__APPLE__)
#define NR_GETTID SYS_thread_selfid
#else
#define NR_GETTID SYS_gettid
#endif

pid_t gettid()
{
  return syscall(NR_GETTID);
}

#endif /* BIONIC_NEED_GETTID */