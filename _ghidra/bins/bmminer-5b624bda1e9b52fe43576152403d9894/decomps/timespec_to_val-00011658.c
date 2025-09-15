
/* WARNING: Unknown calling convention */

void timespec_to_val(timeval *val,timespec *spec)

{
  int iVar1;
  
  iVar1 = spec->tv_nsec;
  val->tv_sec = spec->tv_sec;
  val->tv_usec = iVar1 / 1000;
  return;
}

