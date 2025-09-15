
/* WARNING: Unknown calling convention */

int ms_tdiff(timeval *end,timeval *start)

{
  int iVar1;
  
  iVar1 = end->tv_sec - start->tv_sec;
  if (iVar1 < 0xe11) {
    iVar1 = iVar1 * 1000 + (end->tv_usec - start->tv_usec) / 1000;
  }
  else {
    iVar1 = 3600000;
  }
  return iVar1;
}

