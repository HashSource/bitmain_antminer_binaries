
undefined4 SRP_check_known_gN_param(BIGNUM *param_1,BIGNUM *param_2)

{
  int iVar1;
  
  if (param_1 == (BIGNUM *)0x0 || param_2 == (BIGNUM *)0x0) {
    return 0;
  }
  iVar1 = BN_cmp(DAT_0024df64,param_1);
  if ((iVar1 != 0) || (iVar1 = BN_cmp(DAT_0024df68,param_2), iVar1 != 0)) {
    iVar1 = BN_cmp(DAT_0024df70,param_1);
    if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_0024df74,param_2), iVar1 == 0)) {
      iVar1 = 1;
    }
    else {
      iVar1 = BN_cmp(DAT_0024df7c,param_1);
      if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_0024df80,param_2), iVar1 == 0)) {
        iVar1 = 2;
      }
      else {
        iVar1 = BN_cmp(DAT_0024df88,param_1);
        if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_0024df8c,param_2), iVar1 == 0)) {
          iVar1 = 3;
        }
        else {
          iVar1 = BN_cmp(DAT_0024df94,param_1);
          if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_0024df98,param_2), iVar1 == 0)) {
            iVar1 = 4;
          }
          else {
            iVar1 = BN_cmp(DAT_0024dfa0,param_1);
            if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_0024dfa4,param_2), iVar1 == 0)) {
              iVar1 = 5;
            }
            else {
              iVar1 = BN_cmp(DAT_0024dfac,param_1);
              if (iVar1 != 0) {
                return 0;
              }
              iVar1 = BN_cmp(DAT_0024dfb0,param_2);
              if (iVar1 != 0) {
                return 0;
              }
              iVar1 = 6;
            }
          }
        }
      }
    }
  }
  return (&knowngN)[iVar1 * 3];
}

