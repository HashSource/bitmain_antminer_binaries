
undefined4
SRP_user_pwd_set_sv_isra_3
          (undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  uchar auStack_9dc [2500];
  
  *param_2 = 0;
  *param_1 = 0;
  iVar1 = t_fromb64_constprop_5(auStack_9dc,param_4);
  if (-1 < iVar1) {
    pBVar2 = BN_bin2bn(auStack_9dc,iVar1,(BIGNUM *)0x0);
    *param_2 = pBVar2;
    if (pBVar2 != (BIGNUM *)0x0) {
      iVar1 = t_fromb64_constprop_5(auStack_9dc,param_3);
      if (-1 < iVar1) {
        pBVar2 = BN_bin2bn(auStack_9dc,iVar1,(BIGNUM *)0x0);
        *param_1 = pBVar2;
        if (pBVar2 != (BIGNUM *)0x0) {
          return 1;
        }
      }
      BN_free((BIGNUM *)*param_2);
      *param_2 = 0;
      return 0;
    }
  }
  return 0;
}

