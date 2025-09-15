
/* WARNING: Unknown calling convention */

_Bool time_more(timeval *a,timeval *b)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = a->tv_sec;
  iVar3 = b->tv_sec;
  if (iVar2 != iVar3) {
    if (iVar2 <= iVar3) {
      a = (timeval *)0x0;
    }
    uVar1 = SUB41(a,0);
    if (iVar3 < iVar2) {
      uVar1 = 1;
    }
    return (_Bool)uVar1;
  }
  iVar3 = a->tv_usec;
  iVar2 = iVar3;
  if (iVar3 <= b->tv_usec) {
    iVar2 = 0;
  }
  uVar1 = (undefined1)iVar2;
  if (b->tv_usec < iVar3) {
    uVar1 = 1;
  }
  return (_Bool)uVar1;
}

