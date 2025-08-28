
double le256todouble(void *target)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  __uint64_t _Var5;
  void *target_local;
  double dcut64;
  uint64_t *data64;
  
  _Var5 = __uint64_identity(*(__uint64_t *)((int)target + 0x18));
  dVar1 = (double)__floatundidf((int)_Var5,(int)(_Var5 >> 0x20));
  _Var5 = __uint64_identity(*(__uint64_t *)((int)target + 0x10));
  dVar2 = (double)__floatundidf((int)_Var5,(int)(_Var5 >> 0x20));
  _Var5 = __uint64_identity(*(__uint64_t *)((int)target + 8));
  dVar3 = (double)__floatundidf((int)_Var5,(int)(_Var5 >> 0x20));
                    /* WARNING: Load size is inaccurate */
  _Var5 = __uint64_identity(*target);
  dVar4 = (double)__floatundidf((int)_Var5,(int)(_Var5 >> 0x20));
  return dVar1 * 6.277101735386681e+57 + dVar2 * 3.402823669209385e+38 +
         dVar3 * 1.8446744073709552e+19 + dVar4;
}

