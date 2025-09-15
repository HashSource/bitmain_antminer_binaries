
undefined4 SRP_check_known_gN_param(BIGNUM *param_1,BIGNUM *param_2)

{
  int iVar1;
  
  if (param_1 == (BIGNUM *)0x0 || param_2 == (BIGNUM *)0x0) {
    return 0;
  }
  iVar1 = BN_cmp(DAT_0019a7bc,param_1);
  if ((iVar1 != 0) || (iVar1 = BN_cmp(DAT_0019a7c0,param_2), iVar1 != 0)) {
    iVar1 = BN_cmp(DAT_0019a7c8,param_1);
    if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_0019a7cc,param_2), iVar1 == 0)) {
      iVar1 = 1;
    }
    else {
      iVar1 = BN_cmp(DAT_0019a7d4,param_1);
      if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_0019a7d8,param_2), iVar1 == 0)) {
        iVar1 = 2;
      }
      else {
        iVar1 = BN_cmp(DAT_0019a7e0,param_1);
        if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_0019a7e4,param_2), iVar1 == 0)) {
          iVar1 = 3;
        }
        else {
          iVar1 = BN_cmp(DAT_0019a7ec,param_1);
          if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_0019a7f0,param_2), iVar1 == 0)) {
            iVar1 = 4;
          }
          else {
            iVar1 = BN_cmp(DAT_0019a7f8,param_1);
            if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_0019a7fc,param_2), iVar1 == 0)) {
              iVar1 = 5;
            }
            else {
              iVar1 = BN_cmp(DAT_0019a804,param_1);
              if (iVar1 != 0) {
                return 0;
              }
              iVar1 = BN_cmp(DAT_0019a808,param_2);
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

