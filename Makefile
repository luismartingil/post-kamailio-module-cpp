#

include ../../Makefile.defs
auto_gen=
NAME=zzz.so
LIBS=
DEFS+= -DOPENSER_MOD_INTERFACE -D_GNU_SOURCE

CXX=g++
LD=g++

CXXFLAGS=$(CFLAGS:-Wno-deprecated option=)
CXXFLAGS+= -std=gnu++11 -ggdb3 -Wall
CXXFLAGS+= -Wno-write-strings -Wno-deprecated -Wno-unused-function -Wno-sign-compare -Wno-strict-aliasing

# Include folders
MYINC=$(LOCALBASE)/include /usr/local/share/ ./libzzz/src/
MYINC_PARAMS=$(foreach d, $(MYINC), -I$d)
DEFS+=$(MYINC_PARAMS)

LIBS+= -L$(SYSBASE)/include/lib -L/usr/local/lib/ -L$(LOCALBASE)/lib -L./libzzz/lib
LIBS+= -lzzz

SERLIBPATH=../../lib
SER_LIBS+=$(SERLIBPATH)/srutils/srutils

include ../../Makefile.modules

libzzz.a:
	@echo "-----------------------------------------------"
	@echo "Creating libzzz library..."
	pushd ./libzzz/build; cmake ../; make; popd
	@echo "-----------------------------------------------"

zzz.so: libzzz.a

clean:
	$(foreach d, $(DEP_FOLDERS), $(shell rm -f $d/*.o))
