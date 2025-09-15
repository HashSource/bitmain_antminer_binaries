
/* WARNING: Unknown calling convention */

void cgtimer_sub(cgtimer_t *a,cgtimer_t *b,cgtimer_t *res)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  puVar1 = (undefined4 *)a->tv_nsec;
  iVar3 = (int)puVar1 - b->tv_nsec;
  bVar4 = iVar3 < 0;
  if (bVar4) {
    puVar1 = &DAT_0000ca00;
  }
  iVar2 = a->tv_sec - b->tv_sec;
  if (bVar4) {
    puVar1 = (undefined4 *)((uint)puVar1 & 0xffff | 0x3b9a0000);
  }
  res->tv_sec = iVar2;
  if (bVar4) {
    puVar1 = (undefined4 *)(iVar3 + (int)puVar1);
    iVar2 = iVar2 + -1;
  }
  if (bVar4) {
    res->tv_sec = iVar2;
  }
  else {
    res->tv_nsec = iVar3;
  }
  if (bVar4) {
    res->tv_nsec = (long)puVar1;
  }
  return;
}

