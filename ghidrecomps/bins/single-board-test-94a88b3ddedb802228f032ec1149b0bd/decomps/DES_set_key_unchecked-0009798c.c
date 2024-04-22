
void DES_set_key_unchecked(const_DES_cblock *key,DES_key_schedule *schedule)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  _union_24 *p_Var6;
  int *local_28;
  
  piVar1 = DAT_00097b70;
  p_Var6 = schedule->ks + 3;
  uVar5 = (uint)(*key)[2] << 0x10 | (uint)(*key)[1] << 8 | (uint)(*key)[0] | (uint)(*key)[3] << 0x18
  ;
  uVar2 = (uint)(*key)[6] << 0x10 | (uint)(*key)[5] << 8 | (uint)(*key)[4] | (uint)(*key)[7] << 0x18
  ;
  local_28 = DAT_00097b70;
  uVar4 = (uVar5 ^ uVar2 >> 4) & 0xf0f0f0f;
  uVar2 = uVar2 ^ uVar4 << 4;
  uVar4 = uVar4 ^ uVar5;
  uVar5 = (uVar4 ^ uVar4 << 0x12) & 0xcccc0000;
  uVar3 = (uVar2 ^ uVar2 << 0x12) & 0xcccc0000;
  uVar5 = uVar4 ^ uVar5 ^ uVar5 >> 0x12;
  uVar3 = uVar2 ^ uVar3 ^ uVar3 >> 0x12;
  uVar2 = (uVar5 ^ uVar3 >> 1) & 0x55555555;
  uVar3 = uVar3 ^ uVar2 << 1;
  uVar5 = uVar5 ^ uVar2;
  uVar2 = (uVar3 ^ uVar5 >> 8) & 0xff00ff;
  uVar5 = uVar5 ^ uVar2 << 8;
  uVar2 = uVar2 ^ uVar3;
  uVar3 = (uVar5 ^ uVar2 >> 1) & 0x55555555;
  uVar2 = uVar2 ^ uVar3 << 1;
  uVar3 = uVar3 ^ uVar5;
  uVar5 = uVar3 & 0xfffffff;
  uVar2 = uVar2 & 0xff00 | (uVar3 & 0xf0000000) >> 4 | (uVar2 & 0xff) << 0x10 | (uVar2 << 8) >> 0x18
  ;
  do {
    local_28 = local_28 + 1;
    uVar3 = uVar5 << 0x1a | uVar5 >> 2;
    uVar4 = uVar2 << 0x1a | uVar2 >> 2;
    if (*local_28 == 0) {
      uVar3 = uVar5 << 0x1b | uVar5 >> 1;
      uVar4 = uVar2 << 0x1b | uVar2 >> 1;
    }
    uVar5 = uVar3 & 0xfffffff;
    uVar2 = uVar4 & 0xfffffff;
    HintPreloadData(p_Var6);
    uVar4 = piVar1[((uVar2 << 0xb) >> 0x1a) + 0x191] | piVar1[(uVar4 & 0x3f) + 0x111] |
            piVar1[(uVar2 >> 8 & 0x3c | (uVar2 << 0x17) >> 0x1e) + 0x151] |
            piVar1[(uVar2 >> 0x16 & 0x30 | (uVar2 << 7) >> 0x1c) + 0x1d1];
    uVar3 = piVar1[(uVar5 >> 7 & 0x3c | (uVar5 << 0x18) >> 0x1e) + 0x51] |
            piVar1[(uVar5 >> 0xe & 0x30 | (uVar5 << 0xf) >> 0x1c) + 0x91] |
            piVar1[(uVar3 & 0x3f) + 0x11] |
            piVar1[(uVar5 >> 0x15 & 6 | (uVar5 << 0xb) >> 0x1f | uVar5 >> 0x16 & 0x38) + 0xd1];
    *(uint *)((int)p_Var6 + -0x14) = uVar4 >> 0x1a | (uVar4 & 0xffff0000 | uVar3 >> 0x10) << 6;
    ((DES_key_schedule *)(p_Var6 + -3))->ks[0].deslong[0] =
         (uVar4 << 0x10) >> 0x1e | (uVar3 & 0xffff | uVar4 << 0x10) << 2;
    p_Var6 = p_Var6 + 1;
  } while (local_28 != DAT_00097b74);
  return;
}

