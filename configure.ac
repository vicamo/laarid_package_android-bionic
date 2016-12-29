# Bionic versioning
# -----------------
# To make new release:
#
#   bionic_micro_version += 1
#   bionic_interface_revision += 1
#
# if any functions have been added:
#
#   bionic_micro_version += 1
#   bionic_interface_revision = 0
#
#   or
#
#   bionic_minor_version += 1
#   bionic_micro_version = 0
#   bionic_interface_revision = 0
#
# if backwards compatibility has been broken:
#
#   bionic_major_version += 1
#   bionic_minor_version = 0
#   bionic_micro_version = 0
#   bionic_interface_revision = 0
m4_define([bionic_major_version], [0])
m4_define([bionic_minor_version], [1])
m4_define([bionic_micro_version], [3])
m4_define([bionic_interface_revision], [0])
m4_define([bionic_api_version], [bionic_major_version.0])
m4_define([bionic_release_number], [bionic_major_version])
m4_define([bionic_version],
  [bionic_major_version.bionic_minor_version.bionic_micro_version])

AC_INIT([android-bionic], [bionic_version],
  [https://github.com/laarid/package_android-bionic/issues], [],
  [https://github.com/laarid/package_android-bionic])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([include/bionic/bionic.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects no-define tar-ustar])
AM_MAINTAINER_MODE([enable])
AM_SILENT_RULES([yes])

BIONIC_MAJOR_VERSION=bionic_major_version
BIONIC_MINOR_VERSION=bionic_minor_version
BIONIC_MICRO_VERSION=bionic_micro_version
BIONIC_API_VERSION=bionic_api_version
BIONIC_RELEASE_NUMBER=bionic_release_number
AC_SUBST([BIONIC_MAJOR_VERSION])
AC_SUBST([BIONIC_MINOR_VERSION])
AC_SUBST([BIONIC_MICRO_VERSION])
AC_SUBST([BIONIC_API_VERSION])
AC_SUBST([BIONIC_RELEASE_NUMBER])

AM_PROG_AR
AC_PROG_CC
AC_PROG_CXX

# libtool versioning
# ------------------
LT_INIT

m4_define([bionic_binary_age], [m4_eval(100 * bionic_minor_version + bionic_micro_version)])
m4_define([lt_current], [m4_eval(bionic_binary_age - bionic_interface_revision)])
m4_define([lt_revision], [bionic_interface_revision])
# Whenever backward compatibility is broken, we generate libraries of different
# release number. That follows the library files of the same release are always
# compatible, and they have their lt_age equal to lt_current.
m4_define([lt_age], [lt_current])
LT_VERSION_INFO="lt_current:lt_revision:lt_age"
AC_SUBST([LT_VERSION_INFO])

LT_OUTPUT

AC_LANG_C

# gettid wrapper
# --------------
AC_CHECK_FUNCS([gettid], [],
  [AC_MSG_CHECKING([for syscall(SYS_gettid)])
  AC_COMPILE_IFELSE(
    [AC_LANG_PROGRAM(
[#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#if defined(__APPLE__)
#define NR_GETTID SYS_thread_selfid
#else
#define NR_GETTID SYS_gettid
#endif], [pid_t tid = syscall(NR_GETTID);]
    )],
    [AC_MSG_RESULT([yes])],
    [AC_MSG_ERROR([no])]
  )]
)

# tgkill wrapper
# --------------
AC_CHECK_FUNCS([tgkill], [],
  [AC_MSG_CHECKING([for syscall(SYS_tgkill)])
  AC_COMPILE_IFELSE(
    [AC_LANG_PROGRAM(
[#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>],
[pid_t tid = syscall(SYS_tgkill);]
    )],
    [AC_MSG_RESULT([yes])],
    [AC_MSG_ERROR([no])]
  )]
)

# Userspace I/O
# -------------
AC_CHECK_HEADERS([sys/uio.h])

AC_CHECK_FUNCS([ funopen open_memstream strlcat strlcpy])

PKG_PROG_PKG_CONFIG

# SMP support
# -----------
AC_ARG_ENABLE([smp],
  [AS_HELP_STRING([--enable-smp],
    [enable ANDROID_SMP (default is yes)])], [], [enable_smp=yes])
ANDROID_SMP=m4_case([x$enable_smp], [xyes], [1], [xno], [0], [1])
AC_SUBST(ANDROID_SMP)

# AndroidConfig.h
# --------------
AC_CONFIG_COMMANDS([bionicconfig.h],
[
  outfile=bionicconfig.h-tmp

  cat >$outfile <<_______EOF
/* bionicconfig.h
 *
 * This is a generated file. Please modify 'configure.ac'.
 */

#ifndef __BIONIC_CONFIG_H__
#define __BIONIC_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

$bionic_cfg_defines
_______EOF

  if test x$bionic_cfg_func_gettid != xyes; then
    cat >>$outfile <<_______EOF
#define BIONIC_NEED_GETTID 1

_______EOF
  fi

  if test x$bionic_cfg_func_tgkill != xyes; then
    cat >>$outfile <<_______EOF
#define BIONIC_NEED_TGKILL 1

_______EOF
  fi

  if test x$bionic_cfg_header_sys_uio_h != xyes; then
    cat >>$outfile <<_______EOF
#define BIONIC_NEED_UIO 1

_______EOF
  fi

  if test x$bionic_cfg_func_open_memstream != xyes; then
    cat >>$outfile <<_______EOF
#define BIONIC_NEED_OPEN_MEMSTREAM 1

_______EOF
  fi

  if test x$bionic_cfg_func_strlcat != xyes; then
    cat >>$outfile <<_______EOF
#define BIONIC_NEED_STRLCAT 1

_______EOF
  fi

  if test x$bionic_cfg_func_strlcpy != xyes; then
    cat >>$outfile <<_______EOF
#define BIONIC_NEED_STRLCPY 1

_______EOF
  fi

  cat >>$outfile <<_______EOF
#ifdef __cplusplus
} // extern "C"
#endif

#endif /* __BIONIC_CONFIG_H__ */
_______EOF

  if cmp -s $outfile bionicconfig.h; then
    AC_MSG_NOTICE([bionicconfig.h is unchanged])
    rm -f $outfile
  else
    mv $outfile bionicconfig.h
  fi
], [
bionic_cfg_defines="
#define BIONIC_MAJOR_VERSION $BIONIC_MAJOR_VERSION
#define BIONIC_MINOR_VERSION $BIONIC_MINOR_VERSION
#define BIONIC_MICRO_VERSION $BIONIC_MICRO_VERSION

#define ANDROID_SMP $ANDROID_SMP
"

if test x$ac_cv_func_gettid = xyes; then
  bionic_cfg_func_gettid=yes
fi

if test x$ac_cv_func_tgkill = xyes; then
  bionic_cfg_func_tgkill=yes
fi

if test x$ac_cv_header_sys_uio_h = xyes; then
  bionic_cfg_header_sys_uio_h=yes
fi

if test x$ac_cv_func_open_memstream = xyes; then
  bionic_cfg_func_open_memstream=yes
fi

if test x$ac_cv_func_strlcat = xyes; then
  bionic_cfg_func_strlcat=yes
fi

if test x$ac_cv_func_strlcpy = xyes; then
  bionic_cfg_func_strlcpy=yes
fi
])

AC_CONFIG_FILES([
  Makefile
  android-bionic-$BIONIC_API_VERSION.pc
])
AC_OUTPUT
