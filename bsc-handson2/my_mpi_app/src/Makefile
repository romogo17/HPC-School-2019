MPIF77 = mpif77
FFLAGS = -O2 -g

all: my_mpi_app my_mpi_app_revisited

my_mpi_app: my_mpi_app.f
	$(MPIF77) $(FFLAGS) my_mpi_app.f pi.o -o my_mpi_app

my_mpi_app_revisited: my_mpi_app_revisited.f
	$(MPIF77) $(FFLAGS) my_mpi_app_revisited.f pi.o -o my_mpi_app_revisited


clean:
	rm -fr my_mpi_app my_mpi_app.o my_mpi_app_revisited my_mpi_app_revisited.o TRACE.* set-*

