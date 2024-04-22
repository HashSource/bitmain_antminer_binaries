
void cgtimer_sub(cgtimer_t *a,cgtimer_t *b,cgtimer_t *res)

{
  cgtimer_t *res_local;
  cgtimer_t *b_local;
  cgtimer_t *a_local;
  
  res->tv_sec = a->tv_sec - b->tv_sec;
  res->tv_nsec = a->tv_nsec - b->tv_nsec;
  if (res->tv_nsec < 0) {
    res->tv_nsec = res->tv_nsec + 1000000000;
    res->tv_sec = res->tv_sec + -1;
  }
  return;
}

