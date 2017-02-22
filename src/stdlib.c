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

#include "bionic/bionic.h"

#if defined(BIONIC_NEED_GETPROGNAME)

#ifndef _WIN32

#include <errno.h>
const char* getprogname() {
  return program_invocation_short_name;
}

#else

const char* getprogname() {
  static bool first = true;
  static char progname[MAX_PATH] = {};

  if (first) {
    CHAR longname[MAX_PATH];
    DWORD nchars = GetModuleFileNameA(nullptr, longname, arraysize(longname));
    if ((nchars >= arraysize(longname)) || (nchars == 0)) {
      // String truncation or some other error.
      strcpy(progname, "<unknown>");
    } else {
      strcpy(progname, basename(longname));
    }
    first = false;
  }

  return progname;
}

#endif /* !_WIN32 */

#endif /* BIONIC_NEED_GETPROGNAME */
