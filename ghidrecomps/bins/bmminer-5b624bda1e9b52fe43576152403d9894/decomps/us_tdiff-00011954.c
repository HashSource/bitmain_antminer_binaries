
/* WARNING: Unknown calling convention */

double us_tdiff(timeval *end,timeval *start)

{
  int iVar1;
  
  iVar1 = end->tv_sec - start->tv_sec;
  if (iVar1 < 0x3d) {
    return (double)(longlong)(iVar1 * 1000000 + (end->tv_usec - start->tv_usec));
  }
  return DAT_00011980;
}

