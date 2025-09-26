
void DES_set_key_unchecked(const_DES_cblock *key,DES_key_schedule *schedule)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  _union_24 *p_Var5;
  int *local_28;
  
  p_Var5 = schedule->ks + 3;
  uVar4 = (uint)(*key)[2] << 0x10 | (uint)(*key)[1] << 8 | (uint)(*key)[0] | (uint)(*key)[3] << 0x18
  ;
  uVar1 = (uint)(*key)[6] << 0x10 | (uint)(*key)[5] << 8 | (uint)(*key)[4] | (uint)(*key)[7] << 0x18
  ;
  local_28 = (int *)(weak_keys + 0x7c);
  uVar3 = (uVar4 ^ uVar1 >> 4) & 0xf0f0f0f;
  uVar1 = uVar1 ^ uVar3 << 4;
  uVar3 = uVar3 ^ uVar4;
  uVar4 = (uVar3 ^ uVar3 << 0x12) & 0xcccc0000;
  uVar2 = (uVar1 ^ uVar1 << 0x12) & 0xcccc0000;
  uVar4 = uVar3 ^ uVar4 ^ uVar4 >> 0x12;
  uVar2 = uVar1 ^ uVar2 ^ uVar2 >> 0x12;
  uVar1 = (uVar4 ^ uVar2 >> 1) & 0x55555555;
  uVar2 = uVar2 ^ uVar1 << 1;
  uVar4 = uVar4 ^ uVar1;
  uVar1 = (uVar2 ^ uVar4 >> 8) & 0xff00ff;
  uVar4 = uVar4 ^ uVar1 << 8;
  uVar1 = uVar1 ^ uVar2;
  uVar2 = (uVar4 ^ uVar1 >> 1) & 0x55555555;
  uVar1 = uVar1 ^ uVar2 << 1;
  uVar2 = uVar2 ^ uVar4;
  uVar4 = uVar2 & 0xfffffff;
  uVar1 = uVar1 & 0xff00 | (uVar2 & 0xf0000000) >> 4 | (uVar1 & 0xff) << 0x10 | (uVar1 << 8) >> 0x18
  ;
  do {
    local_28 = local_28 + 1;
    uVar2 = uVar4 << 0x1a | uVar4 >> 2;
    uVar3 = uVar1 << 0x1a | uVar1 >> 2;
    if (*local_28 == 0) {
      uVar2 = uVar4 << 0x1b | uVar4 >> 1;
      uVar3 = uVar1 << 0x1b | uVar1 >> 1;
    }
    uVar4 = uVar2 & 0xfffffff;
    uVar1 = uVar3 & 0xfffffff;
    HintPreloadData(p_Var5);
    uVar3 = *(uint *)(des_skb + ((uVar1 << 0xb) >> 0x1a) * 4 + 0x600) |
            *(uint *)(des_skb + (uVar3 & 0x3f) * 4 + 0x400) |
            *(uint *)(des_skb + (uVar1 >> 8 & 0x3c | (uVar1 << 0x17) >> 0x1e) * 4 + 0x500) |
            *(uint *)(des_skb + (uVar1 >> 0x16 & 0x30 | (uVar1 << 7) >> 0x1c) * 4 + 0x700);
    uVar2 = *(uint *)(des_skb + (uVar4 >> 7 & 0x3c | (uVar4 << 0x18) >> 0x1e) * 4 + 0x100) |
            *(uint *)(des_skb + (uVar4 >> 0xe & 0x30 | (uVar4 << 0xf) >> 0x1c) * 4 + 0x200) |
            *(uint *)(des_skb + (uVar2 & 0x3f) * 4) |
            *(uint *)(des_skb +
                     (uVar4 >> 0x15 & 6 | (uVar4 << 0xb) >> 0x1f | uVar4 >> 0x16 & 0x38) * 4 + 0x300
                     );
    *(uint *)((int)p_Var5 + -0x14) = uVar3 >> 0x1a | (uVar3 & 0xffff0000 | uVar2 >> 0x10) << 6;
    ((DES_key_schedule *)(p_Var5 + -3))->ks[0].deslong[0] =
         (uVar3 << 0x10) >> 0x1e | (uVar2 & 0xffff | uVar3 << 0x10) << 2;
    p_Var5 = p_Var5 + 1;
  } while (local_28 != (int *)(shifts2_8421 + 0x3c));
  return;
}

