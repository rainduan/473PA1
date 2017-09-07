#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "check.h"
#include <sys/time.h>
#include <sys/resource.h>


int x[5] = {1,2,3,4,5};
//double c = 10.0;

void allocate()
{
    int i;
    int *p;
    for(i =1 ; i<1000000 ; i++)
    {
      p = malloc(500 * sizeof(int));
      if(func(i)) { free (p);}
    }
}

void allocate1()
{
  int i;
  int *p;
  for (i=1 ; i<10000 ; i++)
  {
    p = malloc(1000 * sizeof(int));
    if(i & 1)
      free (p);
  }
}

void allocate2()
{
  int i;
  int *p;
  for (i=1 ; i<300000 ; i++)
  {
    p = malloc(10000 * sizeof(int));
    free (p);
  }
}


int main(int argc, char const *argv[]) {
  struct rusage usage;
  struct timeval start, end,startu,endu;
  int num1, num2, num3=0;
  int i;
  int *p;
  printf("Executing the code ......\n");
  getrusage(RUSAGE_SELF, &usage);
  start = usage.ru_stime;
  startu = usage.ru_utime;
  allocate();

  for (i=0 ; i<10000 ; i++)
  {
    p = malloc(1000 * sizeof(int));
    free (p);
  }
  getrusage(RUSAGE_SELF, &usage);
  end=usage.ru_stime;
  endu=usage.ru_utime;
  printf("Program execution successfull\n");
  printf("system Started at: %1d.%1ds\n", start.tv_sec,start.tv_usec);
  printf("system Ended at: %1d.%1ds\n", end.tv_sec,end.tv_usec);
 printf("user Started at: %1d.%1ds\n", startu.tv_sec,startu.tv_usec);
  printf("user Ended at: %1d.%1ds\n", endu.tv_sec,endu.tv_usec);
  printf("The maximum resident set size used are:  %1d\n",usage.ru_maxrss );
printf("Number of signals received :  %1d\n",usage.ru_nsignals );
printf("voluntary context switch :  %1d\n",usage.ru_nvcsw );
printf("involuntary context switch :  %1d\n",usage.ru_nivcsw );
  return 0;
}
