
int aep_mod_exp_part_0(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                      BN_CTX *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_2c [2];
  
  iVar1 = aep_get_connection(local_2c);
  iVar2 = DAT_000d9aec;
  if (iVar1 == 0) {
    iVar1 = (**(code **)(DAT_000d9aec + 0xc))(local_2c[0],param_2,param_3,param_4,param_1,0);
    if (iVar1 == 0) {
      CRYPTO_lock(9,0x1e,DAT_000d9af0,0x3dc);
      iVar1 = 0;
      do {
        iVar3 = iVar1 * 8;
        iVar1 = iVar1 + 1;
        if (local_2c[0] == *(int *)(iVar2 + iVar3 + 0x2c)) {
          *(undefined4 *)(DAT_000d9aec + iVar3 + 0x28) = 1;
          break;
        }
      } while (iVar1 != 0x100);
      CRYPTO_lock(10,0x1e,DAT_000d9af0,1000);
      return 1;
    }
    iVar1 = *(int *)(iVar2 + 4);
    if (iVar1 == 0) {
      iVar1 = ERR_get_next_error_library();
      *(int *)(iVar2 + 4) = iVar1;
    }
    iVar3 = 0;
    ERR_put_error(iVar1,0x68,0x6e,DAT_000d9af0,0x279);
    iVar1 = DAT_000d9af4;
    CRYPTO_lock(9,0x1e,DAT_000d9af0,0x3f2);
    iVar2 = DAT_000d9aec;
    do {
      iVar4 = iVar3 * 8;
      iVar3 = iVar3 + 1;
      if (local_2c[0] == *(int *)(iVar1 + iVar4 + 4)) {
        iVar1 = (**(code **)(DAT_000d9aec + 0x24))(local_2c[0]);
        if (iVar1 == 0) {
          iVar2 = iVar2 + iVar4;
          *(undefined4 *)(iVar2 + 0x28) = 0;
          *(undefined4 *)(iVar2 + 0x2c) = 0;
        }
        break;
      }
    } while (iVar3 != 0x100);
    CRYPTO_lock(10,0x1e,DAT_000d9af0,0x403);
  }
  else {
    iVar1 = *(int *)(DAT_000d9aec + 4);
    if (iVar1 == 0) {
      iVar1 = ERR_get_next_error_library();
      *(int *)(iVar2 + 4) = iVar1;
    }
    ERR_put_error(iVar1,0x68,0x69,DAT_000d9af0,0x26e);
  }
  iVar2 = BN_mod_exp(param_1,param_2,param_3,param_4,param_5);
  return iVar2;
}

