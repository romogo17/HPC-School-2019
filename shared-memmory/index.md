# Shared Memory

There are three main considerations in parallel programing:

- Communication, sending data between processors
- Synchronization, coordinating access to shared resources
- Load Balancing, distributing computations evenly across processor set

## Contents

- [Shared Memory](#shared-memory)
  - [Contents](#contents)
  - [Hello World with OpenMP](#hello-world-with-openmp)
- [OpenMP](#openmp)
  - [Number of threads](#number-of-threads)
  - [Critical Sections and Barriers](#critical-sections-and-barriers)

## Hello World with OpenMP

The following code prints the current thread out of all the number of threads parallelized with OpenMP

```c
#include <omp.h>
int main(){
	int id, np;
	#pragma omp parallel private(id, np)
	{
		np = omp_get_num_threads();
		id = omp_get_thread_num();
		printf("Hello from thread %d, out of %d threads\n",id,np);
	}
}
```

Compile with

```sh
icc -qopenmp -o hello_id hello_id.c
```

The output should be something like this:

```
Hello from thread 4, out of 256 threads
Hello from thread 14, out of 256 threads
Hello from thread 143, out of 256 threads
Hello from thread 168, out of 256 threads
Hello from thread 59, out of 256 threads
...
```

# OpenMP

OpenMP is an implementation of multithreading. It is a standard API for shared-memory programming

A compiler translates OpenMP directives into PThreads threading

## Number of threads

The `num_threads([thread_count])` clause can be added to the pre-processor directive to specify the amount of threads

You can also define an environment variable named `OMP_NUM_THREADS`

Another option is to define the number of threads programmatically using `omp_set_num_threads(int n)`

## Critical Sections and Barriers

A critical section is executed by one thread at the time.
A barrier must be reached by all threads before continuing with the following section.
