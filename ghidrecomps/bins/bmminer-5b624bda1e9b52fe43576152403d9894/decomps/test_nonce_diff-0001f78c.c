
_Bool test_nonce_diff(work *work,uint nonce,double diff)

{
  undefined uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  double in_d0;
  undefined8 uVar5;
  
  *(uint *)(work->data + 0x4c) = nonce;
  regen_hash(work);
  uVar5 = __fixunsdfdi(SUB84(DAT_0001f7c8 / in_d0,0),
                       (int)((ulonglong)(DAT_0001f7c8 / in_d0) >> 0x20));
  uVar3 = (uint)((ulonglong)uVar5 >> 0x20);
  uVar2 = (uint)uVar5;
  bVar4 = *(uint *)(work->hash + 0x1c) <= uVar3;
  if (uVar3 == *(uint *)(work->hash + 0x1c)) {
    bVar4 = *(uint *)(work->hash + 0x18) <= uVar2;
  }
  if (!bVar4) {
    uVar2 = 0;
  }
  uVar1 = (undefined)uVar2;
  if (bVar4) {
    uVar1 = 1;
  }
  return (_Bool)uVar1;
}

