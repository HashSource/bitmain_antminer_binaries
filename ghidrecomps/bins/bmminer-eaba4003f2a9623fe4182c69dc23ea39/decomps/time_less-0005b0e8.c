
_Bool time_less(timeval *a,timeval *b)

{
  undefined uVar1;
  int iVar2;
  int iVar3;
  timeval *b_local;
  timeval *a_local;
  
  if (a->tv_sec == b->tv_sec) {
    iVar2 = b->tv_usec;
    iVar3 = iVar2;
    if (iVar2 <= a->tv_usec) {
      iVar3 = 0;
    }
    uVar1 = (undefined)iVar3;
    if (a->tv_usec < iVar2) {
      uVar1 = 1;
    }
  }
  else {
    iVar2 = b->tv_sec;
    iVar3 = iVar2;
    if (iVar2 <= a->tv_sec) {
      iVar3 = 0;
    }
    uVar1 = (undefined)iVar3;
    if (a->tv_sec < iVar2) {
      uVar1 = 1;
    }
  }
  return (_Bool)uVar1;
}

