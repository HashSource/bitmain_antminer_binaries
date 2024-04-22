
/* WARNING: Variable defined which should be unmapped: target-local */

double le256todouble(void *target)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  __uint64_t _Var5;
  undefined4 uStack_20;
  void *target_local;
  double dcut64;
  uint64_t *data64;
  
  _Var5 = __uint64_identity(CONCAT44(target,uStack_20));
  dVar1 = (double)__floatundidf((int)_Var5,(int)(_Var5 >> 0x20));
  dVar1 = dVar1 * DAT_0004c6d8;
  _Var5 = __uint64_identity(CONCAT44(target,uStack_20));
  dVar2 = (double)__floatundidf((int)_Var5,(int)(_Var5 >> 0x20));
  dVar2 = dVar2 * DAT_0004c6e0;
  _Var5 = __uint64_identity(CONCAT44(target,uStack_20));
  dVar3 = (double)__floatundidf((int)_Var5,(int)(_Var5 >> 0x20));
  dVar3 = dVar3 * DAT_0004c6e8;
  _Var5 = __uint64_identity(CONCAT44(target,uStack_20));
  dVar4 = (double)__floatundidf((int)_Var5,(int)(_Var5 >> 0x20));
  return dVar1 + dVar2 + dVar3 + dVar4;
}

