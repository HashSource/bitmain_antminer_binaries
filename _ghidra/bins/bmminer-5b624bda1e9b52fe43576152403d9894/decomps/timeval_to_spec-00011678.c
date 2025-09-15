
/* WARNING: Unknown calling convention */

void timeval_to_spec(timespec *spec,timeval *val)

{
  int iVar1;
  
  iVar1 = val->tv_usec;
  spec->tv_sec = val->tv_sec;
  spec->tv_nsec = iVar1 * 1000;
  return;
}

