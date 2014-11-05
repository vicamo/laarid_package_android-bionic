ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

# Distribution
# ------------
EXTRA_DIST = \
	LICENSE \
	README.md \
	android-bionic-$(BIONIC_API_VERSION).pc.in

DISTCLEANFILES = \
	bionicconfig.h \
	config.lt

# Common/global flags
# -------------------
AM_CPPFLAGS = \
	-include config.h \
	-I$(top_srcdir)/include

AM_CFLAGS = \
	-Wall -Werror

AM_CXXFLAGS = \
	-std=c++11

libtool_opts = \
	-version-info $(LT_VERSION_INFO) \
	-export-dynamic \
	-rpath $(libdir)

lib_LTLIBRARIES = \
	libandroid-bionic-0.la

# libandroid-bionic.la
# --------------------
libandroid_bionic_0_la_LDFLAGS = \
	$(libtool_opts)
libandroid_bionic_0_la_SOURCES = \
	src/properties.cpp \
	src/properties_compat.c \
	src/stdio.c \
	src/string.c \
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

DISTCLEANFILES += \
	$(pkgconfig_DATA)
