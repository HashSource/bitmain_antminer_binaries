
void timersubspec(timespec *a,timespec *b)

{
  timespec *b_local;
  timespec *a_local;
  
  a->tv_sec = a->tv_sec - b->tv_sec;
  a->tv_nsec = a->tv_nsec - b->tv_nsec;
  spec_nscheck(a);
  return;
}

