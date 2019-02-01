# This file is automatically generated after the make install step.

EXTRAE_HOME=/home/jgimenez/tools/extrae-3.6.1
MPI_HOME=/opt/tools/mpich-3.2.1
MPI_CFLAGS=-I/opt/tools/mpich-3.2.1/include
MPI_LDFLAGS=-L/opt/tools/mpich-3.2.1/lib
MPI_LIBS=-lmpi
PAPI_HOME=/home/jgimenez/tools/dep/papi-5.5.1
XML2_HOME= /usr
XML2_LDFLAGS=-L/usr/lib64
XML2_LIBS=-lxml2
UNWIND_HOME=/home/jgimenez/tools/dep/libunwind-1.3-rc1/
BFD_HOME=/usr
LIBERTY_HOME=/usr
BFD_LIBS=-L/usr/lib64 -lbfd -L/usr/lib64 -liberty
UNWIND_LIBS=-L$(UNWIND_HOME)/lib -lunwind
PAPI_LIBS=-L$(PAPI_HOME)/lib -lpapi
CUPTI_LIBS=
POSIX_CLOCK_LIBS=
LIBEXECINFO_LIBS= # FreeBSD specific
ZLIB_HOME=/usr
ZLIB_LIBS=-lz
DL_LIBS=-ldl
OPENCL_HOME=
OPENCL_LDFLAGS=

CC=/usr/bin/gcc
FC=/opt/tools/mpich-3.2.1/bin/mpif90
CXX=/usr/bin/g++
MPICC=/opt/tools/mpich-3.2.1/bin/mpicc
MPIF77=/opt/tools/mpich-3.2.1/bin/mpif77
MPIF90=/opt/tools/mpich-3.2.1/bin/mpif90
NVCC=
JAVAC=
JAR=

# For statically linked apps or systems

EXTRAE_LDFLAGS_LIBSEQTRACE=-L$(EXTRAE_HOME)/lib -lseqtrace -L$(ZLIB_HOME)/lib -lz -L$(PAPI_HOME)/lib -lpapi -L$(XML2_HOME)/lib -lxml2 -L$(BFD_HOME)/lib -lbfd -liberty

EXTRAE_LDFLAGS_LIBMPITRACE=-L$(EXTRAE_HOME)/lib -lmpitrace -L$(ZLIB_HOME)/lib -lz -L$(PAPI_HOME)/lib -lpapi -L$(XML2_HOME)/lib -lxml2 -L$(BFD_HOME)/lib -lbfd -liberty

EXTRAE_LDFLAGS_LIBMPITRACEF=-L$(EXTRAE_HOME)/lib -lmpitracef -L$(ZLIB_HOME)/lib -lz -L$(PAPI_HOME)/lib -lpapi -L$(XML2_HOME)/lib -lxml2 -L$(BFD_HOME)/lib -lbfd -liberty

