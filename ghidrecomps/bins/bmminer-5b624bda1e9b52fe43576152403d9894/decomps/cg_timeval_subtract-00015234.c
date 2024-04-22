
/* WARNING: Unknown calling convention */

int cg_timeval_subtract(timeval *result,timeval *x,timeval *y)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = x->tv_sec;
  iVar3 = y->tv_sec;
  if (iVar2 == iVar3 || iVar2 < iVar3) {
    if ((iVar2 != iVar3) || (x->tv_usec <= y->tv_usec)) {
      iVar1 = y->tv_usec - x->tv_usec;
      result->tv_sec = iVar3 - iVar2;
      result->tv_usec = iVar1;
      if (iVar1 < 0) {
        result->tv_sec = (iVar3 - iVar2) + -1;
        result->tv_usec = iVar1 + 1000000;
        return 0;
      }
      return 0;
    }
  }
  return -1;
}

