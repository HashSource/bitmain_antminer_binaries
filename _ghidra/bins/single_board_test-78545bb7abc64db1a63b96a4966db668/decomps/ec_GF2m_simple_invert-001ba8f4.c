
undefined4 ec_GF2m_simple_invert(EC_GROUP *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if ((iVar1 == 0) && (iVar1 = BN_is_zero(*(undefined4 *)(param_2 + 0xc)), iVar1 == 0)) {
    iVar1 = EC_POINT_make_affine(param_1,param_2,param_3);
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = BN_GF2m_add(*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 8));
    return uVar2;
  }
  return 1;
}

