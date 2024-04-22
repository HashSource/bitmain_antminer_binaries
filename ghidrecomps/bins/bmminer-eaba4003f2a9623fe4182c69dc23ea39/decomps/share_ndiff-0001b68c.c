
uint64_t share_ndiff(work *work)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  uint64_t uVar4;
  work *work_local;
  double s64;
  double d64;
  uint64_t ret;
  
  uVar2 = truediffone._4_4_;
  uVar1 = truediffone._0_4_;
  uVar4 = 0;
  if (work != (work *)0x0) {
    dVar3 = le256todouble(work->hash);
    if (dVar3 == 0.0) {
      uVar4 = 0;
    }
    else {
      dVar3 = (double)CONCAT44(uVar2,uVar1) / dVar3;
      uVar4 = __fixunsdfdi(SUB84(dVar3,0),(int)((ulonglong)dVar3 >> 0x20));
    }
  }
  return uVar4;
}

