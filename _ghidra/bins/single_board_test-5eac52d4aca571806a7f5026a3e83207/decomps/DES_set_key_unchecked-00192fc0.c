
void DES_set_key_unchecked(const_DES_cblock *key,DES_key_schedule *schedule)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  _union_24 *p_Var5;
  _union_24 *p_Var6;
  int *piVar7;
  
  uVar3 = (*(uint *)*key ^ *(uint *)(*key + 4) >> 4) & 0xf0f0f0f;
  uVar4 = *(uint *)(*key + 4) ^ uVar3 << 4;
  uVar3 = uVar3 ^ *(uint *)*key;
  piVar7 = (int *)(weak_keys + 0x7c);
  uVar1 = (uVar3 ^ uVar3 << 0x12) & 0xcccc0000;
  uVar2 = (uVar4 ^ uVar4 << 0x12) & 0xcccc0000;
  uVar3 = uVar3 ^ uVar1 ^ uVar1 >> 0x12;
  uVar2 = uVar4 ^ uVar2 ^ uVar2 >> 0x12;
  uVar1 = (uVar3 ^ uVar2 >> 1) & 0x55555555;
  uVar2 = uVar2 ^ uVar1 << 1;
  uVar3 = uVar3 ^ uVar1;
  uVar1 = (uVar2 ^ uVar3 >> 8) & 0xff00ff;
  uVar3 = uVar3 ^ uVar1 << 8;
  uVar1 = uVar1 ^ uVar2;
  uVar2 = (uVar3 ^ uVar1 >> 1) & 0x55555555;
  uVar1 = uVar1 ^ uVar2 << 1;
  uVar2 = uVar2 ^ uVar3;
  uVar3 = uVar2 & 0xfffffff;
  uVar1 = (uVar1 << 8) >> 0x18 | uVar1 & 0xff00 | (uVar2 & 0xf0000000) >> 4 | (uVar1 & 0xff) << 0x10
  ;
  p_Var5 = schedule->ks + 3;
  do {
    piVar7 = piVar7 + 1;
    HintPreloadData(p_Var5);
    uVar4 = uVar1 << 0x1a | uVar1 >> 2;
    uVar2 = uVar3 << 0x1a | uVar3 >> 2;
    if (*piVar7 == 0) {
      uVar4 = uVar1 << 0x1b | uVar1 >> 1;
      uVar2 = uVar3 << 0x1b | uVar3 >> 1;
    }
    uVar3 = uVar2 & 0xfffffff;
    uVar1 = uVar4 & 0xfffffff;
    p_Var6 = p_Var5 + 1;
    uVar2 = *(uint *)(des_skb + ((uVar3 << 0x18) >> 0x1e | uVar3 >> 7 & 0x3c) * 4 + 0x100) |
            *(uint *)(des_skb + (uVar3 >> 0xe & 0x30 | (uVar3 << 0xf) >> 0x1c) * 4 + 0x200) |
            *(uint *)(des_skb + (uVar2 & 0x3f) * 4) |
            *(uint *)(des_skb +
                     ((uVar3 << 0xb) >> 0x1f | uVar3 >> 0x15 & 6 | uVar3 >> 0x16 & 0x38) * 4 + 0x300
                     );
    uVar4 = *(uint *)(des_skb + ((uVar1 << 7) >> 0x1c | uVar1 >> 0x16 & 0x30) * 4 + 0x700) |
            *(uint *)(des_skb + (uVar1 >> 8 & 0x3c | (uVar1 << 0x17) >> 0x1e) * 4 + 0x500) |
            *(uint *)(des_skb + (uVar4 & 0x3f) * 4 + 0x400) |
            *(uint *)(des_skb + ((uVar1 << 0xb) >> 0x1a) * 4 + 0x600);
    ((DES_key_schedule *)(p_Var5 + -3))->ks[0].deslong[0] =
         (uVar4 << 0x10) >> 0x1e | (uVar2 & 0xffff | uVar4 << 0x10) << 2;
    *(uint *)((int)p_Var5 + -0x14) = uVar4 >> 0x1a | (uVar4 & 0xffff0000 | uVar2 >> 0x10) << 6;
    p_Var5 = p_Var6;
  } while (schedule[1].ks + 3 != p_Var6);
  return;
}

