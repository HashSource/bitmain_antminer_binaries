
undefined4 BN_GF2m_mod_arr(BIGNUM *param_1,BIGNUM *param_2,int *param_3)

{
  ulong *puVar1;
  undefined4 uVar2;
  BIGNUM *pBVar3;
  int words;
  int iVar4;
  int iVar5;
  ulong *puVar6;
  
  if (*param_3 == 0) {
    BN_set_word(param_1,0);
    return 1;
  }
  if (param_2 != param_1) {
    words = param_2->top;
    if (param_1->dmax < words) {
      pBVar3 = bn_expand2(param_1,words);
      if (pBVar3 == (BIGNUM *)0x0) {
        return 0;
      }
      words = param_2->top;
    }
    if (0 < words) {
      puVar1 = param_1->d;
      iVar4 = 0;
      puVar6 = param_2->d;
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 1;
        *(undefined4 *)((int)puVar1 + iVar4) = *(undefined4 *)((int)puVar6 + iVar4);
        iVar4 = iVar4 + 4;
        words = param_2->top;
      } while (iVar5 < words);
    }
    param_1->top = words;
  }
  uVar2 = BN_GF2m_mod_arr_part_0(param_1,param_3);
  return uVar2;
}

