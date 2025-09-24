
undefined4 ec_GF2m_simple_point_copy(int param_1,int param_2)

{
  BIGNUM *pBVar1;
  undefined4 uVar2;
  
  pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 8),*(BIGNUM **)(param_2 + 8));
  if (((pBVar1 != (BIGNUM *)0x0) &&
      (pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0xc),*(BIGNUM **)(param_2 + 0xc)),
      pBVar1 != (BIGNUM *)0x0)) &&
     (pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x10),*(BIGNUM **)(param_2 + 0x10)),
     pBVar1 != (BIGNUM *)0x0)) {
    uVar2 = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 4) = uVar2;
    return 1;
  }
  return 0;
}

