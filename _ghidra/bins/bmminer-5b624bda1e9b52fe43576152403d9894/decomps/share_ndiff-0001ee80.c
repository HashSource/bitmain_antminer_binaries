
/* WARNING: Unknown calling convention */

uint64_t share_ndiff(work *work)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  uint64_t uVar5;
  
  if (work != (work *)0x0) {
    dVar1 = (double)__aeabi_ul2d(*(undefined4 *)(work->hash + 0x18),
                                 *(undefined4 *)(work->hash + 0x1c));
    dVar2 = (double)__aeabi_ul2d(*(undefined4 *)(work->hash + 0x10),
                                 *(undefined4 *)(work->hash + 0x14));
    dVar3 = (double)__aeabi_ul2d(*(undefined4 *)(work->hash + 8),*(undefined4 *)(work->hash + 0xc));
    dVar4 = (double)__aeabi_ul2d(*(undefined4 *)work->hash,*(undefined4 *)(work->hash + 4));
    dVar4 = dVar1 * 6.277101735386681e+57 + dVar2 * 3.402823669209385e+38 +
            dVar3 * 1.8446744073709552e+19 + dVar4;
    if (dVar4 != 0.0) {
      dVar4 = 2.695953529101131e+67 / dVar4;
      uVar5 = __fixunsdfdi(SUB84(dVar4,0),(int)((ulonglong)dVar4 >> 0x20));
      return uVar5;
    }
  }
  return 0;
}

