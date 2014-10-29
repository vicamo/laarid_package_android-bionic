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
	src/gettid.c \
	src/uio.c

# bionic HEADERS
# --------------
bionicincdir = $(includedir)/android/bionic-$(BIONIC_API_VERSION)/bionic
bionicinc_HEADERS = \
	include/bionic/bionic.h \
	include/bionic/gettid.h \
	include/bionic/uio.h

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
