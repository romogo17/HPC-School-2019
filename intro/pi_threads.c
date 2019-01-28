#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct
{
  int num_of_points;
  int partial_result;
} pi_params;

void *calc_partial_pi(void *p)
{
  pi_params *params = p;
  int count = 0;
  double r1, r2;
  unsigned int seed = time(NULL);

  for (int i = 0; i < params->num_of_points; ++i)
  {
    r1 = (double)rand_r(&seed) / RAND_MAX;
    r2 = (double)rand_r(&seed) / RAND_MAX;
    if (hypot(r1, r2) < 1)
      count++;
  }
  params->partial_result = count;
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{

  if (argc != 3)
  {
    printf("Usage: $ %s num_thread num_points\n", argv[0]);
    exit(0);
  }

  int num_threads = atoi(argv[1]);
  int num_points = atoi(argv[2]);
  int num_points_per_thread = num_points / num_threads;

  pthread_t threads[num_threads];
  pi_params parameters[num_threads];

  for (int i = 0; i < num_threads; i++)
  {
    parameters[i].num_of_points = num_points_per_thread;
    pthread_create(threads + i, NULL, calc_partial_pi, parameters + i);
  }

  for (int i = 0; i < num_threads; i++)
    pthread_join(threads[i], NULL);

  double approx_pi = 0;
  for (int i = 0; i < num_threads; i++)
    approx_pi += parameters[i].partial_result;
  approx_pi /= (num_threads * num_points_per_thread) / 4;

  printf("Result is %f, error %f\n", approx_pi, fabs(M_PI - approx_pi));
}