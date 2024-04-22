
undefined4 SRP_check_known_gN_param(BIGNUM *param_1,BIGNUM *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_000d77b0;
  if (param_1 == (BIGNUM *)0x0 || param_2 == (BIGNUM *)0x0) {
    return 0;
  }
  iVar2 = BN_cmp(*(BIGNUM **)(DAT_000d77b0 + 4),param_1);
  if ((iVar2 != 0) || (iVar2 = BN_cmp(*(BIGNUM **)(iVar1 + 8),param_2), iVar2 != 0)) {
    iVar2 = DAT_000d77b0;
    iVar3 = BN_cmp(*(BIGNUM **)(iVar1 + 0x10),param_1);
    if ((iVar3 == 0) && (iVar2 = BN_cmp(*(BIGNUM **)(iVar2 + 0x14),param_2), iVar2 == 0)) {
      iVar2 = 1;
    }
    else {
      iVar2 = DAT_000d77b0;
      iVar3 = BN_cmp(*(BIGNUM **)(iVar1 + 0x1c),param_1);
      if ((iVar3 == 0) && (iVar2 = BN_cmp(*(BIGNUM **)(iVar2 + 0x20),param_2), iVar2 == 0)) {
        iVar2 = 2;
      }
      else {
        iVar2 = DAT_000d77b0;
        iVar3 = BN_cmp(*(BIGNUM **)(iVar1 + 0x28),param_1);
        if ((iVar3 == 0) && (iVar2 = BN_cmp(*(BIGNUM **)(iVar2 + 0x2c),param_2), iVar2 == 0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = DAT_000d77b0;
          iVar3 = BN_cmp(*(BIGNUM **)(iVar1 + 0x34),param_1);
          if ((iVar3 == 0) && (iVar2 = BN_cmp(*(BIGNUM **)(iVar2 + 0x38),param_2), iVar2 == 0)) {
            iVar2 = 4;
          }
          else {
            iVar2 = DAT_000d77b0;
            iVar3 = BN_cmp(*(BIGNUM **)(iVar1 + 0x40),param_1);
            if ((iVar3 == 0) && (iVar2 = BN_cmp(*(BIGNUM **)(iVar2 + 0x44),param_2), iVar2 == 0)) {
              iVar2 = 5;
            }
            else {
              iVar2 = DAT_000d77b0;
              iVar3 = BN_cmp(*(BIGNUM **)(iVar1 + 0x4c),param_1);
              if (iVar3 != 0) {
                return 0;
              }
              iVar2 = BN_cmp(*(BIGNUM **)(iVar2 + 0x50),param_2);
              if (iVar2 != 0) {
                return 0;
              }
              iVar2 = 6;
            }
          }
        }
      }
    }
  }
  return *(undefined4 *)(iVar1 + iVar2 * 0xc);
}

