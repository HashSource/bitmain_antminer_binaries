
undefined4 SRP_check_known_gN_param(BIGNUM *param_1,BIGNUM *param_2)

{
  int iVar1;
  
  if (param_1 == (BIGNUM *)0x0 || param_2 == (BIGNUM *)0x0) {
    return 0;
  }
  iVar1 = BN_cmp(DAT_00252f54,param_1);
  if ((iVar1 != 0) || (iVar1 = BN_cmp(DAT_00252f58,param_2), iVar1 != 0)) {
    iVar1 = BN_cmp(DAT_00252f60,param_1);
    if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_00252f64,param_2), iVar1 == 0)) {
      iVar1 = 1;
    }
    else {
      iVar1 = BN_cmp(DAT_00252f6c,param_1);
      if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_00252f70,param_2), iVar1 == 0)) {
        iVar1 = 2;
      }
      else {
        iVar1 = BN_cmp(DAT_00252f78,param_1);
        if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_00252f7c,param_2), iVar1 == 0)) {
          iVar1 = 3;
        }
        else {
          iVar1 = BN_cmp(DAT_00252f84,param_1);
          if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_00252f88,param_2), iVar1 == 0)) {
            iVar1 = 4;
          }
          else {
            iVar1 = BN_cmp(DAT_00252f90,param_1);
            if ((iVar1 == 0) && (iVar1 = BN_cmp(DAT_00252f94,param_2), iVar1 == 0)) {
              iVar1 = 5;
            }
            else {
              iVar1 = BN_cmp(DAT_00252f9c,param_1);
              if (iVar1 != 0) {
                return 0;
              }
              iVar1 = BN_cmp(DAT_00252fa0,param_2);
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

