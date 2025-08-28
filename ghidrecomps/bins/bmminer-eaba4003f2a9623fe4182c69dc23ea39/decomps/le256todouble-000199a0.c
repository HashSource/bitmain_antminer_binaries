
double le256todouble(void *target)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  void *target_local;
  double dcut64;
  uint64_t *data64;
  
  dVar1 = (double)__aeabi_ul2d(*(undefined4 *)((int)target + 0x18),
                               *(undefined4 *)((int)target + 0x1c));
  dVar2 = (double)__aeabi_ul2d(*(undefined4 *)((int)target + 0x10),
                               *(undefined4 *)((int)target + 0x14));
  dVar3 = (double)__aeabi_ul2d(*(undefined4 *)((int)target + 8),*(undefined4 *)((int)target + 0xc));
                    /* WARNING: Load size is inaccurate */
  dVar4 = (double)__aeabi_ul2d(*target,*(undefined4 *)((int)target + 4));
  return dVar1 * 6.277101735386681e+57 + dVar2 * 3.402823669209385e+38 +
         dVar3 * 1.8446744073709552e+19 + dVar4;
}

