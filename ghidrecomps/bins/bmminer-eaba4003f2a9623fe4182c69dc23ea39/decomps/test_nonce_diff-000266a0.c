
_Bool test_nonce_diff(work *work,uint nonce,double diff)

{
  uint uVar1;
  undefined uVar2;
  uint uVar3;
  bool bVar4;
  double in_d0;
  double dVar5;
  undefined8 uVar6;
  double diff_local;
  uint nonce_local;
  work *work_local;
  uint64_t diff64;
  uint64_t *hash64;
  
  rebuild_nonce(work,nonce);
  dVar5 = (double)__aeabi_ul2d(0xffff0000,0);
  uVar6 = __fixunsdfdi(SUB84(dVar5 / in_d0,0),(int)((ulonglong)(dVar5 / in_d0) >> 0x20));
  uVar1 = (uint)((ulonglong)uVar6 >> 0x20);
  uVar3 = *(uint *)(work->hash + 0x1c);
  bVar4 = uVar3 <= uVar1;
  if (uVar1 == uVar3) {
    bVar4 = *(uint *)(work->hash + 0x18) <= (uint)uVar6;
  }
  if (!bVar4) {
    uVar3 = 0;
  }
  uVar2 = (undefined)uVar3;
  if (bVar4) {
    uVar2 = 1;
  }
  return (_Bool)uVar2;
}

