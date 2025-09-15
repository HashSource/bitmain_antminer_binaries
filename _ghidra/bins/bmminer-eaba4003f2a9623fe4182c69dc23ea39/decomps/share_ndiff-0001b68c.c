
uint64_t share_ndiff(work *work)

{
  double dVar1;
  uint64_t uVar2;
  work *work_local;
  double s64;
  double d64;
  uint64_t ret;
  
  uVar2 = 0;
  if (work != (work *)0x0) {
    dVar1 = le256todouble(work->hash);
    if (dVar1 == 0.0) {
      uVar2 = 0;
    }
    else {
      uVar2 = __fixunsdfdi(SUB84(2.695953529101131e+67 / dVar1,0),
                           (int)((ulonglong)(2.695953529101131e+67 / dVar1) >> 0x20));
    }
  }
  return uVar2;
}

