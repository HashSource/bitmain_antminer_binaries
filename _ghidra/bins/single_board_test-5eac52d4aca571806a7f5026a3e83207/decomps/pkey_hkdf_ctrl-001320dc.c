
undefined4 pkey_hkdf_ctrl(int param_1,undefined4 param_2,size_t param_3,void *param_4)

{
  size_t sVar1;
  size_t *psVar2;
  
  psVar2 = *(size_t **)(param_1 + 0x14);
  switch(param_2) {
  case 0x1003:
    if (param_4 != (void *)0x0) {
      psVar2[1] = (size_t)param_4;
      return 1;
    }
    break;
  case 0x1004:
    if (param_4 == (void *)0x0 || param_3 == 0) {
      return 1;
    }
    if (-1 < (int)param_3) {
      if (psVar2[2] != 0) {
        CRYPTO_clear_free(psVar2[2],psVar2[3],"crypto/kdf/hkdf.c",0x5e);
      }
      sVar1 = CRYPTO_memdup(param_4,param_3,"crypto/kdf/hkdf.c",0x60);
      psVar2[2] = sVar1;
      if (sVar1 != 0) {
        psVar2[3] = param_3;
        return 1;
      }
    }
    break;
  case 0x1005:
    if (-1 < (int)param_3) {
      if (psVar2[4] != 0) {
        CRYPTO_clear_free(psVar2[4],psVar2[5],"crypto/kdf/hkdf.c",0x6c);
      }
      sVar1 = CRYPTO_memdup(param_4,param_3,"crypto/kdf/hkdf.c",0x6e);
      psVar2[4] = sVar1;
      if (sVar1 != 0) {
        psVar2[5] = param_3;
        return 1;
      }
    }
    break;
  case 0x1006:
    if (param_4 == (void *)0x0 || param_3 == 0) {
      return 1;
    }
    if ((-1 < (int)param_3) && ((int)param_3 <= (int)(0x400 - psVar2[0x106]))) {
      memcpy((void *)((int)psVar2 + psVar2[0x106] + 0x18),param_4,param_3);
      psVar2[0x106] = param_3 + psVar2[0x106];
      return 1;
    }
    break;
  case 0x1007:
    *psVar2 = param_3;
    return 1;
  default:
    return 0xfffffffe;
  }
  return 0;
}

