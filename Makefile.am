ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

# Distribution
# ------------
EXTRA_DIST = \
	LICENSE \
	README.md \
	android-bionic-$(BIONIC_API_VERSION).pc.in
BUILT_SOURCES =
CLEANFILES =
DISTCLEANFILES = \
	bionicconfig.h \
	config.lt
MAINTAINERCLEANFILES = \
	$(GITIGNORE_MAINTAINERCLEANFILES_TOPLEVEL) \
	$(GITIGNORE_MAINTAINERCLEANFILES_M4_LIBTOOL) \
	$(GITIGNORE_MAINTAINERCLEANFILES_MAKEFILE_IN)

DISTCHECK_CONFIGURE_FLAGS = \
	--disable-maintainer-mode

GITIGNOREFILES = \
	build \
	debian \
	$(DIST_ARCHIVES)

# Common/global flags
# -------------------
AM_CPPFLAGS = \
	-include config.h \
	-I$(top_srcdir)/include

AM_CFLAGS = \
	-Wall -Werror \
	-std=gnu99

AM_CXXFLAGS = \
	-Wall -Werror \
	-std=gnu++11

libtool_opts = \
	-version-info $(LT_VERSION_INFO) \
	-export-dynamic \
	-rpath $(libdir)

lib_LTLIBRARIES = \
	libandroid-bionic.la

# libandroid-bionic.la
# ------------
libandroid_bionic_la_LDFLAGS = \
	$(libtool_opts)
libandroid_bionic_la_SOURCES = \
	src/futex.h \
	src/macros.h \
	src/properties.cpp \
	src/properties_compat.c \
	src/stdio.c \
	src/stdlib.c \
	src/string.c \
	src/strlcat.c \
	src/uio.c \
	src/unistd.c

# bionic HEADERS
# --------------
bionicincdir = $(includedir)/android/bionic-$(BIONIC_API_VERSION)/bionic
bionicinc_HEADERS = \
	include/bionic/bionic.h \
	include/bionic/cdefs.h \
	include/bionic/properties.h \
	include/bionic/properties_impl.h \
	include/bionic/stdio.h \
	include/bionic/stdlib.h \
	include/bionic/string.h \
	include/bionic/uio.h \
	include/bionic/unistd.h

# bionicconfig.h
# --------------
bioniccfgincdir = $(libdir)/android/bionic-$(BIONIC_API_VERSION)/include
nodist_bioniccfginc_HEADERS = \
	bionicconfig.h

# PKG-CONFIG data files
# ---------------------
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = \
	android-bionic-$(BIONIC_API_VERSION).pc

$(pkgconfig_DATA): config.status

EXTRA_DIST += $(pkgconfig_DATA:.pc=.pc.in)
DISTCLEANFILES += \
	$(pkgconfig_DATA)

CLEANFILES += $(BUILT_SOURCES)
GITIGNOREFILES += $(BUILT_SOURCES)

-include $(top_srcdir)/git.mk
