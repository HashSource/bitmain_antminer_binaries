
/* WARNING: Unknown calling convention */

double tdiff(timeval *end,timeval *start)

{
  return (double)(longlong)(end->tv_sec - start->tv_sec) +
         (double)(longlong)(end->tv_usec - start->tv_usec) / DAT_000119f0;
}

