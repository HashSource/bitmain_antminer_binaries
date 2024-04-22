
void cgtimer_time(cgtimer_t *ts_start)

{
  cgtimer_t *ts_start_local;
  
  clock_gettime(1,(timespec *)ts_start);
  return;
}

