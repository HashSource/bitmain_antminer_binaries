
undefined4 BN_GF2m_poly2arr(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = BN_is_zero();
  if (iVar1 != 0 || param_3 < 1) {
    return 0;
  }
  *param_2 = 0xffffffff;
  return 1;
}

