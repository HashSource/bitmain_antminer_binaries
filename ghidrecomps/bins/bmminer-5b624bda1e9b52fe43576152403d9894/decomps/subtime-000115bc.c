
/* WARNING: Unknown calling convention */

void subtime(timeval *a,timeval *b)

{
  int iVar1;
  int iVar2;
  
  iVar1 = a->tv_sec - b->tv_sec;
  iVar2 = a->tv_usec - b->tv_usec;
  b->tv_sec = iVar1;
  b->tv_usec = iVar2;
  if (iVar2 < 0) {
    b->tv_sec = iVar1 + -1;
    b->tv_usec = iVar2 + 1000000;
  }
  return;
}

