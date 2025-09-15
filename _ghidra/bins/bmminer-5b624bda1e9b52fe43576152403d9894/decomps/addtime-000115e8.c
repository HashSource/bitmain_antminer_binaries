
/* WARNING: Unknown calling convention */

void addtime(timeval *a,timeval *b)

{
  int iVar1;
  int iVar2;
  
  iVar2 = a->tv_usec + b->tv_usec;
  iVar1 = a->tv_sec + b->tv_sec;
  b->tv_sec = iVar1;
  b->tv_usec = iVar2;
  if (999999 < iVar2) {
    b->tv_sec = iVar1 + 1;
    b->tv_usec = iVar2 + -1000000;
  }
  return;
}

