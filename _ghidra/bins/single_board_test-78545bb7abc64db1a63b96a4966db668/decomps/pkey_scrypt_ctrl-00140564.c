
undefined4 pkey_scrypt_ctrl(int param_1,undefined4 param_2,int param_3,uint *param_4)

{
  void *pvVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 0x14);
  switch(param_2) {
  case 0x1008:
    if (param_4 == (uint *)0x0) {
      return 1;
    }
    if (param_3 < 0) {
      return 0;
    }
    if (*piVar5 != 0) {
      CRYPTO_clear_free(*piVar5,piVar5[1],"crypto/kdf/scrypt.c",100);
    }
    if (param_3 == 0) {
      pvVar1 = CRYPTO_malloc(1,"crypto/kdf/scrypt.c",0x69);
      *piVar5 = (int)pvVar1;
    }
    else {
      pvVar1 = (void *)CRYPTO_memdup(param_4,param_3,"crypto/kdf/scrypt.c",0x67);
      *piVar5 = (int)pvVar1;
    }
    if (pvVar1 != (void *)0x0) {
      piVar5[1] = param_3;
      return 1;
    }
    goto LAB_00140676;
  case 0x1009:
    if (param_4 == (uint *)0x0) {
      return 1;
    }
    if (param_3 < 0) {
      return 0;
    }
    if (piVar5[2] != 0) {
      CRYPTO_clear_free(piVar5[2],piVar5[3],"crypto/kdf/scrypt.c",100);
    }
    if (param_3 == 0) {
      pvVar1 = CRYPTO_malloc(1,"crypto/kdf/scrypt.c",0x69);
      piVar5[2] = (int)pvVar1;
    }
    else {
      pvVar1 = (void *)CRYPTO_memdup(param_4,param_3,"crypto/kdf/scrypt.c",0x67);
      piVar5[2] = (int)pvVar1;
    }
    if (pvVar1 != (void *)0x0) {
      piVar5[3] = param_3;
      return 1;
    }
LAB_00140676:
    ERR_put_error(0x34,0x6b,0x41,"crypto/kdf/scrypt.c",0x6c);
    uVar2 = 0;
    break;
  case 0x100a:
    uVar3 = *param_4;
    uVar4 = param_4[1];
    if ((uVar4 == 0 && uVar3 < 2) ||
       (((uVar4 - 1) + (uint)(uVar3 != 0) & uVar4) != 0 || (uVar3 - 1 & uVar3) != 0)) {
      return 0;
    }
    uVar2 = 1;
    piVar5[4] = uVar3;
    piVar5[5] = uVar4;
    break;
  case 0x100b:
    uVar3 = param_4[1];
    if (*param_4 == 0 && uVar3 == 0) {
      return 0;
    }
    piVar5[6] = *param_4;
    piVar5[7] = uVar3;
    uVar2 = 1;
    break;
  case 0x100c:
    uVar3 = param_4[1];
    if (*param_4 == 0 && uVar3 == 0) {
      return 0;
    }
    piVar5[8] = *param_4;
    piVar5[9] = uVar3;
    uVar2 = 1;
    break;
  case 0x100d:
    uVar3 = param_4[1];
    if (*param_4 == 0 && uVar3 == 0) {
      return 0;
    }
    uVar2 = 1;
    piVar5[10] = *param_4;
    piVar5[0xb] = uVar3;
    break;
  default:
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}

