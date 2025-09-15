
/* WARNING: Unknown calling convention */

void timeraddspec(timespec *a,timespec *b)

{
  int iVar1;
  int iVar2;
  
  iVar2 = a->tv_nsec + b->tv_nsec;
  iVar1 = a->tv_sec + b->tv_sec;
  a->tv_sec = iVar1;
  a->tv_nsec = iVar2;
  if (999999999 < iVar2) {
    do {
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + -1000000000;
    } while (999999999 < iVar2);
    a->tv_sec = iVar1;
    a->tv_nsec = iVar2;
  }
  if (iVar2 < 0) {
    iVar1 = a->tv_sec;
    do {
      iVar1 = iVar1 + -1;
      iVar2 = iVar2 + 1000000000;
    } while (iVar2 < 0);
    a->tv_sec = iVar1;
    a->tv_nsec = iVar2;
  }
  return;
}

