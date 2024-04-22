
/* WARNING: Unknown calling convention */

uint64_t share_ndiff(work *work)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  uint64_t uVar6;
  
  dVar1 = DAT_0001ef08;
  if (work != (work *)0x0) {
    dVar2 = (double)__aeabi_ul2d(*(undefined4 *)(work->hash + 0x18),
                                 *(undefined4 *)(work->hash + 0x1c));
    dVar3 = (double)__aeabi_ul2d(*(undefined4 *)(work->hash + 0x10),
                                 *(undefined4 *)(work->hash + 0x14));
    dVar3 = dVar3 * DAT_0001ef10;
    dVar4 = (double)__aeabi_ul2d(*(undefined4 *)(work->hash + 8),*(undefined4 *)(work->hash + 0xc));
    dVar4 = dVar4 * DAT_0001ef18;
    dVar5 = (double)__aeabi_ul2d(*(undefined4 *)work->hash,*(undefined4 *)(work->hash + 4));
    dVar5 = dVar2 * dVar1 + dVar3 + dVar4 + dVar5;
    if (dVar5 != 0.0) {
      dVar5 = DAT_0001ef20 / dVar5;
      uVar6 = __fixunsdfdi(SUB84(dVar5,0),(int)((ulonglong)dVar5 >> 0x20));
      return uVar6;
    }
  }
  return 0;
}

