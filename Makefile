
KMOD	= kdw

SRCS	= kdw.cc

CXXFLAGS += -std=gnu++14 -fmodules

# Include kernel module makefile
.include <bsd.kmod.mk>

