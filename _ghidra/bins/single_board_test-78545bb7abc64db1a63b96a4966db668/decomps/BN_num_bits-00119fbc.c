
int BN_num_bits(BIGNUM *a)

{
  ulong *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = a->top - 1;
  if ((a->flags & 4U) == 0) {
    iVar2 = BN_is_zero();
    if (iVar2 == 0) {
      iVar2 = BN_num_bits_word(a->d[uVar6]);
      return iVar2 + uVar6 * 0x40;
    }
  }
  else if (0 < a->dmax) {
    uVar8 = 0;
    uVar7 = 0;
    uVar5 = 0;
    do {
      puVar1 = a->d + uVar5;
      uVar4 = (int)((uVar5 ^ uVar6) - 1 & ~(uVar5 ^ uVar6)) >> 0x1f;
      uVar5 = uVar5 + 1;
      uVar3 = BN_num_bits_word(*puVar1);
      uVar7 = uVar7 | uVar4;
      uVar8 = (uVar3 & uVar4) + uVar8 + (~uVar7 & 0x40);
    } while ((int)uVar5 < a->dmax);
    return uVar8 & ~((int)(~uVar6 - 1 & uVar6) >> 0x1f);
  }
  return 0;
}

